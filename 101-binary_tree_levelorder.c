#include"binary_trees.h"
#include "9-binary_tree_height.c"
#include "10-binary_tree_depth.c"
/**
 * all_nodes_level - print all nodes in same level
 * @tree: tree to loop through
 * @depth: depth of the tree
 * @func: function to call
 * Return - void
 */
void all_nodes_level(const binary_tree_t *tree, int depth, void (*func)(int))
{
	int actual_depth;

	if (tree == NULL)
		return;

	actual_depth = binary_tree_depth(tree);
	if (actual_depth == depth)
	{
		func(tree->n);
		return;
	}

	if (actual_depth > depth)
		return;

	all_nodes_level(tree->left, depth, func);
	all_nodes_level(tree->right, depth, func);

}

/**
 *binary_tree_levelorder - function to run all the levels
 *@tree: tree to loop through
 *@func: function to call
 *Return - void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height;
	int i;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);

	for (i = 0; i <= height; i++)
	{
		all_nodes_level(tree, i, func);
	}

}
