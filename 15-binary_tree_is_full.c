#include "binary_trees.h"
#include "11-binary_tree_size.c"
#include "4-binary_tree_is_leaf.c"
#include <stdio.h>
/**
 * binary_tree_is_full - checks if tree is full
 *@tree: tree to check
 *
 *Return: 1 full 0 not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_leaf(tree))
		return (1);
	if (binary_tree_size(tree->left) != binary_tree_size(tree->right))
		return (0);
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
