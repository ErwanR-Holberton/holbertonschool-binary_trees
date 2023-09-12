#include "binary_trees.h"

/**
 *binary_tree_is_leaf- verification if a node is a leaf
 *@node:the node who checks
 *Return: 1 or 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node->left == NULL && node->right == NULL && node != NULL);
}
