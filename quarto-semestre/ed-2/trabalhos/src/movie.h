#ifndef MOVIE_H
#define MOVIE_H
#include "file_management/bplus.h"
#include <stddef.h>
typedef struct {
	char id[6];
	char *pt_title;
	char *title;
	char *director;
	char release_year[5];
	char *country;
	char score;
} Tmovie;

int insert_movie(Tmovie movie);
int change_score(char *id, char score);
int remove_movie(char *id);
void reorder_indexes();
char *search_next(bp_node *node, int *i);
char *search_by_id(char *id);
char **search_by_title(char *title, int *arr_length);
int clean_deleted_entries();

#endif /* end of include guard: MOVIE_H */
