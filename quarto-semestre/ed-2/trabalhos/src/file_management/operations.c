#include "bplus.h"
#include "file_globals.h"
#include "../movie.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

static int cmp_ititle_id(const void *x, const void *y)
{
	return strcmp(((const struct Gititle *)x)->id,
		      ((const struct Gititle *)y)->id);
}

static int cmp_ititle_title(const void *x, const void *y)
{
	return strcasecmp(((const struct Gititle *)x)->title,
			  ((const struct Gititle *)y)->title);
}

static int iprimary_insert(const char *id, long rrn)
{
	if (bp_search_data_rrn(Giprimary_bptree, id) != -1)
		return 0;
	bp_insert(Giprimary_bptree, id, rrn);

	return 1;
}

static int ititle_insert(const char *id, const char *title)
{
	void *new_ptr =
		realloc(Gititle_arr.Ptitle,
			(Gititle_arr.arr_size + 1) * sizeof(struct Gititle));
	if (new_ptr == NULL)
		return 0;
	Gititle_arr.Ptitle = new_ptr;

	Gititle_arr.Ptitle[Gititle_arr.arr_size].title =
		malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(Gititle_arr.Ptitle[Gititle_arr.arr_size].title, title);
	strcpy(Gititle_arr.Ptitle[Gititle_arr.arr_size].id, id);

	Gititle_arr.arr_size++;
	qsort(Gititle_arr.Ptitle, Gititle_arr.arr_size, sizeof(struct Gititle),
	      cmp_ititle_title);

	return 1;
}

void reorder_indexes()
{
	qsort(Gititle_arr.Ptitle, Gititle_arr.arr_size, sizeof(struct Gititle),
	      cmp_ititle_title);
}

int insert_movie(Tmovie movie)
{
	char buffer[193] = { 0 };
	fseek(Gfile_pointer.movies, 0, SEEK_SET);
	long initial_state = ftell(Gfile_pointer.movies);

	fseek(Gfile_pointer.movies, 0, SEEK_END);
	long start_entry = ftell(Gfile_pointer.movies);

	long rrn = (start_entry - initial_state) / 192;

	char *copy = malloc((strlen(movie.director) + 1) * sizeof(char));
	strcpy(copy, movie.director);
	char *prev;
	for (char *pointer = copy, *token;
	     (token = strtok_r(pointer, " ", &pointer));)
		prev = token;

	for (int i = 0; i < 3; i++)
		movie.id[i] = toupper(prev[i]);
	memcpy(&movie.id[3], &movie.release_year[2], 2 * sizeof(char));
	movie.id[5] = 0;
	free(copy);

	sprintf(buffer, "%s@%s@%s@%s@%s@%s@%c@", movie.id, movie.pt_title,
		movie.title, movie.director, movie.release_year, movie.country,
		movie.score);
	for (size_t length; (length = strlen(buffer)) < 192;)
		sprintf(buffer + length, "%c", '#');

	fprintf(Gfile_pointer.movies, "%s", buffer);

	return iprimary_insert(movie.id, rrn) &&
	       ititle_insert(movie.id, movie.pt_title);
}

int change_score(char *id, char score)
{
	int rrn = bp_search_data_rrn(Giprimary_bptree, id);
	if (rrn == -1)
		return 0;
	long initial_state = ftell(Gfile_pointer.movies);
	fseek(Gfile_pointer.movies, rrn * 192, SEEK_SET);
	delimitors_move(Gfile_pointer.movies, '@', 6);
	fprintf(Gfile_pointer.movies, "%c", score);
	fseek(Gfile_pointer.movies, initial_state, SEEK_SET);
	return 1;
}

int remove_movie(char *id)
{
	char buffer[256];

	// find the id in the id/rrn array
	int rrn = bp_search_data_rrn(Giprimary_bptree, id);
	if (rrn == -1)
		return 0;

	// remove entry from movies.dat
	fseek(Gfile_pointer.movies, rrn * 192, SEEK_SET);
	fprintf(Gfile_pointer.movies, "*|");
	fseek(Gfile_pointer.movies, 0, SEEK_SET);

	// remove entry from id/rrn iprimary
	//
	// find entry from id/title
	struct Gititle *tmp_ititle =
		bsearch(id, Gititle_arr.Ptitle, Gititle_arr.arr_size,
			sizeof(struct Gititle), cmp_ititle_id);
	if (tmp_ititle == NULL)
		return 0;

	// remove entry from id/title array
	int tmp_ititle_offset = (int)(tmp_ititle - Gititle_arr.Ptitle);
	if (tmp_ititle_offset != Gititle_arr.arr_size - 1)
		memmove(tmp_ititle, tmp_ititle + 1,
			Gititle_arr.arr_size - tmp_ititle_offset - 1);
	{
		struct Gititle *new_ptr = realloc(
			Gititle_arr.Ptitle,
			sizeof(struct Gititle) * (Gititle_arr.arr_size - 1));
		if (new_ptr == NULL)
			return 0;
		Gititle_arr.Ptitle = new_ptr;
	}
	Gititle_arr.arr_size--;
	return 1;
}

static char search_buffer[193];

char *search_next(bp_node *node, int *i)
{
	if (*i == node->num_keys) {
		if (bp_next(Giprimary_bptree, node) == NULL)
			return NULL;

		*i = 0;

		fseek(Gfile_pointer.movies, node->d[*i].data_rrn * 192,
		      SEEK_SET);
		fgets(search_buffer, 192, Gfile_pointer.movies);

		return search_buffer;
	}
	(*i)++;
	fseek(Gfile_pointer.movies, node->d[*i].data_rrn * 192, SEEK_SET);
	fgets(search_buffer, 192, Gfile_pointer.movies);
	return search_buffer;
}

char *search_by_id(char *id)
{
	int rrn = bp_search_data_rrn(Giprimary_bptree, id);
	if (rrn == -1)
		return 0;
	fseek(Gfile_pointer.movies, rrn * 192, SEEK_SET);
	fgets(search_buffer, 192, Gfile_pointer.movies);
	return search_buffer;
}

char **search_by_title(char *title, int *arr_length)
{
	struct Gititle key = { .title = malloc(sizeof(char) *
					       (strlen(title) + 1)) };
	strcpy(key.title, title);
	struct Gititle *tmp_ititle =
		bsearch(&key, Gititle_arr.Ptitle, Gititle_arr.arr_size,
			sizeof(struct Gititle), cmp_ititle_title);
	if (tmp_ititle == NULL)
		return NULL;

	int offset = (int)(tmp_ititle - Gititle_arr.Ptitle);

	while (offset - 1 >= 0 &&
	       cmp_ititle_title(&key, &Gititle_arr.Ptitle[offset - 1]) == 0)
		offset--;

	*arr_length = 1;
	while (offset + *arr_length < Gititle_arr.arr_size &&
	       cmp_ititle_title(&key,
				&Gititle_arr.Ptitle[offset + *arr_length]) == 0)
		(*arr_length)++;

	free(key.title);

	char **result = malloc(sizeof(char *) * *arr_length);
	for (int i = 0; i < *arr_length; i++) {
		char *tmp_buf = search_by_id(tmp_ititle[i].id);
		if (tmp_buf == NULL)
			return NULL;
		result[i] = malloc(sizeof(char) * (strlen(tmp_buf) + 1));
		strcpy(result[i], tmp_buf);
	}
	return result;
}

int clean_deleted_entries()
{
	const char *const tmpfilename = ".tmpfile.trabalho1";
	char buffer[193];
	FILE *tmpfile = fopen(tmpfilename, "w");
	long new_file_rrn = 0;
	bp_node temp;
	ibp_node_read(&temp, Giprimary_bptree, Giprimary_bptree->root_offset);
	do {
		for (int i = 0; i < temp.num_keys; i++) {
			fseek(Gfile_pointer.movies, temp.d[i].data_rrn * 192,
			      SEEK_SET);
			fgets(buffer, 192, Gfile_pointer.movies);
			fputs(buffer, tmpfile);
			temp.d[i].data_rrn = new_file_rrn;
			ibp_node_write(&temp, Giprimary_bptree, temp.offset);
			new_file_rrn++;
		}
	} while (bp_next(Giprimary_bptree, &temp));
	fclose(tmpfile);
	if (rename(tmpfilename, Gfilenames[MOVIES]))
		return 0;
	fclose(Gfile_pointer.movies);
	Gfile_pointer.movies = fopen(Gfilenames[MOVIES], "r+");
	return 1;
}
