#ifndef BPLUS_H
#define BPLUS_H
#include <stdio.h>
#include <stdbool.h>
#define ORDER 252

typedef struct bp_node {
	long offset;
	bool is_leaf;
	long parent_offset;
	int num_keys;

	struct {
		struct {
			char key[6];
			union {
				// if_leaf == false
				long int child_offset;
				// if_leaf == true
				int data_rrn;
			};
		} d[ORDER + 1];
		// if_leaf == true
		long prev_offset, next_offset;
	};
} bp_node;

typedef struct bp_tree {
	FILE *fp;
	long root_offset;
} bp_tree;

void ibp_node_read(bp_node *out, bp_tree *tree, long int offset);
void ibp_node_write(bp_node *in, bp_tree *tree, long int offset);

void ibp_header_write(bp_tree *tree);
void ibp_header_read(bp_tree *tree);

long ibp_new_offset(bp_tree *tree);
bp_node *ibp_search_node(bp_tree *tree, char *key);

void ibp_insert_after_split(bp_tree *tree, bp_node *left_node,
			    bp_node *right_node);

bp_tree *bp_open(char *filename);
void bp_close(bp_tree **tree);
int bp_search_data_rrn(bp_tree *tree, char *key);
void bp_insert(bp_tree *tree, char *key, int data_rrn);
void bp_print_values(bp_tree *tree);

#endif /* end of include guard: BPLUS_H */
