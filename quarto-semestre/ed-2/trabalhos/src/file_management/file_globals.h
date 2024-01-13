#ifndef FILE_GLOBALS_H
#define FILE_GLOBALS_H

#include "bplus.h"
#include <stdio.h>

struct Gfilepointers {
	FILE *movies;
	FILE *titles;
};

struct Gititle_arr {
	size_t arr_size;
	struct Gititle {
		char id[6];
		char *title;
	} *Ptitle;
};

int chars_until(FILE *fp, int ch);
int delimitors_until_end(FILE *fp, int ch);
void delimitors_move(FILE *fp, int ch, int qtd);

extern char filepath[256];
enum { F_RIGHT = 1 };
extern struct Gfilepointers Gfile_pointer;

extern bp_tree *Giprimary_bptree;
extern struct Gititle_arr Gititle_arr;

enum { MOVIES, IDS, TITLES };

extern const char *const Gfilenames[];
#endif /* end of include guard: FILE_GLOBALS_H */
