#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_management.h"
#include "file_globals.h"
#include "bplus.h"
#include "../movie.h"

enum { HEADER_OFFSET = 3 };

void init_files()
{
	char filename_buffer[256];
movies:
	strcpy(filename_buffer, filepath);
	strcat(filename_buffer, Gfilenames[MOVIES]);
	Gfile_pointer.movies = fopen(filename_buffer, "w+");
ids:
	strcpy(filename_buffer, filepath);
	strcat(filename_buffer, Gfilenames[IDS]);
	Giprimary_bptree = bp_open(filename_buffer);

titles:
	strcpy(filename_buffer, filepath);
	strcat(filename_buffer, Gfilenames[TITLES]);

	Gfile_pointer.titles = fopen(filename_buffer, "w+");
	reorder_indexes();
}

void end_files()
{
	fseek(Gfile_pointer.titles, 0, SEEK_SET);

	fprintf(Gfile_pointer.titles, "\1\n\n");

	bp_close(&Giprimary_bptree);
	for (int i = 0; i < Gititle_arr.arr_size; i++) {
		fprintf(Gfile_pointer.titles, "%s@%s@",
			Gititle_arr.Ptitle[i].id, Gititle_arr.Ptitle[i].title);
		free(Gititle_arr.Ptitle[i].title);
	}
	free(Gititle_arr.Ptitle);

	fclose(Gfile_pointer.movies);
	fclose(Gfile_pointer.titles);
}

void set_path(char *path)
{
	strcpy(filepath, path);
}
