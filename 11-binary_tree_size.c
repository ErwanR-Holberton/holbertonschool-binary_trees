#include "binary_trees.h"
/**
 * binary_tree_size - count all child nodes including the root
 * @tree: tree to loop through
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	int size_left = 0, size_right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		size_left = binary_tree_size(tree->left);
	if (tree->right != NULL)
		size_right = binary_tree_size(tree->right);
	return (size_left + size_right + 1);
}
