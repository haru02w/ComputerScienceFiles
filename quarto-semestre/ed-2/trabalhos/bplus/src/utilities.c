#include "bplus.h"
#include <assert.h>
#include <stdlib.h>

bp_tree *bp_open(char *filename)
{
	bp_tree *tree = malloc(sizeof *tree);
	assert(tree != NULL);
	if ((tree->fp = fopen(filename, "rb+")) == NULL) {
		if ((tree->fp = fopen(filename, "wb+")) == NULL) {
			fprintf(stderr,
				"Não foi possivel ler nem criar o arquivo. "
				"Não vai dá não...\n");
			exit(EXIT_FAILURE);
		} else {
			tree->root_offset = -1;
		}
	} else {
		ibp_header_read(tree);
	}
	ibp_header_write(tree);
	return tree;
}

void bp_close(bp_tree **tree)
{
	assert(tree != NULL);
	assert((*tree)->fp != NULL);
	fclose((*tree)->fp);
	free(*tree);
	*tree = NULL;
}

void ibp_header_read(bp_tree *tree)
{
	assert(fseek(tree->fp, 0L, SEEK_SET) == 0);
	fread(&tree->root_offset, sizeof tree->root_offset, 1, tree->fp);
}

void ibp_header_write(bp_tree *tree)
{
	assert(fseek(tree->fp, 0L, SEEK_SET) == 0);
	fwrite(&tree->root_offset, sizeof tree->root_offset, 1, tree->fp);
}

void ibp_node_read(bp_node *out, bp_tree *tree, long offset)
{
	assert(fseek(tree->fp, offset, SEEK_SET) == 0);
	fread(out, sizeof *out, 1, tree->fp);
}

void ibp_node_write(bp_node *in, bp_tree *tree, long offset)
{
	assert(fseek(tree->fp, offset, SEEK_SET) == 0);
	fwrite(in, sizeof *in, 1, tree->fp);
	fflush(tree->fp);
}

long ibp_new_offset(bp_tree *tree)
{
	assert(fseek(tree->fp, 0L, SEEK_END) == 0);
	return ftell(tree->fp);
}
