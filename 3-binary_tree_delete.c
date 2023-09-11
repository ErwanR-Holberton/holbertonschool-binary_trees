#include "binary_trees.h"

/**
 * binary_tree_delete - frees the tree passed as an argument
 *
 * @tree: tree to free
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		binary_tree_delete(tree->left);
	if (tree->right != NULL)
		binary_tree_delete(tree->right);
	free(tree);
}
