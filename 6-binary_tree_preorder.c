#include "binary_trees.h"

/**
 * binary_tree_preorder - function that goes through the tree and call func
 *@tree: tree to loop through
 *@func: pointer to the function call for each node
 *Return: nothing
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{

	if (tree == NULL)
		return;

	func(tree->n);
	if (tree->left != NULL)
		binary_tree_preorder(tree->left, func);
	if (tree->right != NULL)
		binary_tree_preorder(tree->right, func);
}
