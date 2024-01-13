#include "bplus.h"
#include "file_globals.h"
#include <linux/limits.h>

bp_tree *Giprimary_bptree = NULL;

struct Gititle_arr Gititle_arr = {
	.arr_size = 0,
	NULL,
};

struct Gfilepointers Gfile_pointer = {
	NULL,
	NULL,
};

const char *const Gfilenames[] = {
	"movies.dat",
	"iprimary.idx",
	"ititle.idx",
};

char filepath[256] = "";
