#include "binary_trees.h"
/**
 * *bst_search - search for a value in a tree
 * @tree: tree to search
 * @value: value to search
 * Return: adress of the node found or NULL if fail or not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	if (tree->n > value)
		return (bst_search(tree->left, value));

	return (bst_search(tree->right, value));
}
