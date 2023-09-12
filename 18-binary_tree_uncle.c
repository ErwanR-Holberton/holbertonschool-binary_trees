#include"binary_trees.h"
#include "17-binary_tree_sibling.c"
/**
 * binary_tree_uncle - search the uncle
 *@node: each node of tree
 *Return: value of uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->parent == NULL)
		return (0);

	return (binary_tree_sibling(node->parent));
}
