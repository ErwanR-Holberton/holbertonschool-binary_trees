#include "binary_trees.h"

/**
 * binary_tree_postorder - function that goes through the tree and call func
 *@tree: tree to loop through
 *@func: pointer to the function call for each node
 *Return: nothing
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{

	if (tree == NULL || func == NULL)
		return;

	if (tree->left != NULL)
		binary_tree_postorder(tree->left, func);
	if (tree->right != NULL)
		binary_tree_postorder(tree->right, func);
	func(tree->n);
}
