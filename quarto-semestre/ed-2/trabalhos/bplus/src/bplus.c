#include "bplus.h"
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void bp_print_values(bp_tree *tree)
{
	bp_node temp;
	ibp_node_read(&temp, tree, tree->root_offset);
	while (temp.is_leaf == false)
		ibp_node_read(&temp, tree, temp.d[0].child_offset);
	for (;;) {
		for (int i = 0; i < temp.num_keys; i++) {
			printf("%s - %d\n", temp.d[i].key, temp.d[i].data_rrn);
		}
		if (temp.next_offset == -1)
			break;
		ibp_node_read(&temp, tree, temp.next_offset);
	}
}

bp_node *ibp_search_node(bp_tree *tree, char *key)
{
	if (tree->root_offset == -1)
		return NULL;

	bp_node inner;
	bp_node *cur_node = malloc(sizeof(*cur_node));
	ibp_node_read(cur_node, tree, tree->root_offset);

	while (cur_node->is_leaf == false) {
		assert(cur_node->num_keys != 0);
		int i = 0;
		ibp_node_read(&inner, tree, cur_node->d[i].child_offset); //
		while (i < cur_node->num_keys &&
		       strcasecmp(key, cur_node->d[i].key) >= 0) {
			i++;
			ibp_node_read(&inner, tree,
				      cur_node->d[i].child_offset); //
		}

		ibp_node_read(cur_node, tree, cur_node->d[i].child_offset);
	}
	return cur_node;
}

int bp_search_data_rrn(bp_tree *tree, char *key)
{
	bp_node *cur_node = ibp_search_node(tree, key);
	if (cur_node == NULL)
		return -1;

	int i = 0;
	while (i < cur_node->num_keys &&
	       strcasecmp(key, cur_node->d[i].key) != 0)
		i++;
	if (i != cur_node->num_keys) {
		int ret = cur_node->d[i].data_rrn;
		free(cur_node);
		return ret;
	}
	free(cur_node);
	return -1;
}

void bp_insert(bp_tree *tree, char *key, int data_rrn)
{
	bp_node *node = ibp_search_node(tree, key);
	if (node == NULL) {
		// Create new root
		bp_node root = {
			.num_keys = 1,
			.offset = ibp_new_offset(tree),
			.is_leaf = true,
			.next_offset = -1,
			.prev_offset = -1,
			.parent_offset = -1,
		};

		memcpy(root.d[0].key, key, sizeof root.d[0].key);

		root.d[0].data_rrn = data_rrn;

		tree->root_offset = root.offset;

		ibp_header_write(tree);
		ibp_node_write(&root, tree, root.offset);
		return;
	}

	{ // verify if key is unique
		int i = 0;
		while (i < node->num_keys &&
		       strcasecmp(key, node->d[i].key) != 0)
			i++;
		if (i != node->num_keys) {
			free(node);
			return;
		}
	}

	// Insert into leaf
	int pos = 0;
	while (pos < node->num_keys && strcasecmp(key, node->d[pos].key) >= 0)
		pos++;
	memmove(&node->d[pos + 1], &node->d[pos],
		(node->num_keys - pos) * sizeof node->d[0]);

	memcpy(node->d[pos].key, key, sizeof node->d[0].key);
	node->d[pos].data_rrn = data_rrn;
	node->num_keys++;

	ibp_node_write(node, tree, node->offset);

	if (node->num_keys > ORDER - 1) {
		// split and then insert into index tree
		bp_node new_node = {
			.is_leaf = true,
			.offset = ibp_new_offset(tree),
			.parent_offset = node->parent_offset,
			.prev_offset = node->offset,
			.next_offset = node->next_offset,
		};
		node->next_offset = new_node.offset;

		int split_pos = node->num_keys / 2;
		new_node.num_keys = node->num_keys - split_pos;
		node->num_keys = split_pos;

		memcpy(new_node.d, &node->d[split_pos],
		       new_node.num_keys * sizeof new_node.d[0]);

		ibp_node_write(&new_node, tree, new_node.offset);
		ibp_node_write(node, tree, node->offset);

		ibp_insert_after_split(tree, node, &new_node);
	}
	free(node);
	return;
}

void ibp_insert_after_split(bp_tree *tree, bp_node *left_node,
			    bp_node *right_node)
{
	bp_node parent;
	if (left_node->parent_offset == -1) {
		// Create new root
		parent = (bp_node){
			.num_keys = 1,
			.offset = ibp_new_offset(tree),
			.is_leaf = false,
			.parent_offset = -1,
		};

		memcpy(parent.d[0].key, right_node->d[0].key,
		       sizeof parent.d[0].key);

		parent.d[0].child_offset = left_node->offset;
		parent.d[1].child_offset = right_node->offset;

		if (right_node->is_leaf == false) {
			memmove(right_node->d, &right_node->d[1],
				(right_node->num_keys) *
					sizeof right_node->d[0]);
			right_node->num_keys--;
		}
		tree->root_offset = parent.offset;

		left_node->parent_offset = parent.offset;
		right_node->parent_offset = parent.offset;

		ibp_header_write(tree);
		ibp_node_write(&parent, tree, parent.offset);

		ibp_node_write(left_node, tree, left_node->offset);
		ibp_node_write(right_node, tree, right_node->offset);
		return;
	}
	ibp_node_read(&parent, tree, left_node->parent_offset);

	// Insert into parent
	int pos = 0;
	while (pos < parent.num_keys &&
	       strcasecmp(right_node->d[0].key, parent.d[pos].key) >= 0)
		pos++;
	memmove(&parent.d[pos + 1], &parent.d[pos],
		(parent.num_keys + 1 - pos) * sizeof parent.d[0]);

	memcpy(parent.d[pos].key, right_node->d[0].key, sizeof parent.d[0].key);
	parent.d[pos + 1].child_offset = right_node->offset;
	parent.num_keys++;

	if (right_node->is_leaf == false) {
		memmove(right_node->d, &right_node->d[1],
			(right_node->num_keys) * sizeof right_node->d[0]);
		right_node->num_keys--;
		ibp_node_write(right_node, tree, right_node->offset);
	}

	ibp_node_write(&parent, tree, parent.offset);

	if (parent.num_keys > ORDER - 1) {
		// split and call recursive
		bp_node right_parent = {
			.is_leaf = false,
			.offset = ibp_new_offset(tree),
			.parent_offset = parent.parent_offset,
		};

		int split_pos = parent.num_keys / 2;
		right_parent.num_keys = parent.num_keys - split_pos;
		parent.num_keys = split_pos;

		memcpy(right_parent.d, &parent.d[split_pos],
		       (right_parent.num_keys + 1) * sizeof right_parent.d[0]);

		ibp_node_write(&right_parent, tree, right_parent.offset);
		ibp_node_write(&parent, tree, parent.offset);

		assert(right_parent.is_leaf == false);
		for (int i = 1; i <= right_parent.num_keys; i++) {
			bp_node temp;
			ibp_node_read(&temp, tree,
				      right_parent.d[i].child_offset);
			temp.parent_offset = right_parent.offset;
			ibp_node_write(&temp, tree, temp.offset);
		}
		ibp_insert_after_split(tree, &parent, &right_parent);
	}
	return;
}
