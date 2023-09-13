#include "binary_trees.h"
/**
 * *binary_tree_rotate_left - rotate the tree to the left
 * @tree: tree to loop through
 * Return: new address of tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (tree == NULL)
		return (0);
	temp = tree->right;
	if (tree->right != NULL)
	{
		tree->right->parent = temp;
		tree->right = tree->right->left;
		if (tree->right != NULL)
			tree->right->parent = tree;
	}
	temp->left = tree;
	tree->parent = temp;
	return (temp);
}
