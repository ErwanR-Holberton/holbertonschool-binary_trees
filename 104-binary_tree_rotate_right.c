#include "binary_trees.h"
/**
 * binary_tree_is_complete - check if the given tree is complete
 * @tree: tree to loop through
 * Return: 1 if complete 0 otherwise
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;
	if (tree == NULL)
		return (0);
	temp = tree->left;
	if (tree->left != NULL)
	{
		tree->left->parent = temp;
		tree->left = tree->left->right;
		if (tree->left != NULL)
			tree->left->parent = tree;
	}
	temp->right = tree;
	tree->parent = temp;
	return(temp);
}
