#include "binary_trees.h"
/**
 *binary_tree_is_root- check if a node is a the root
 *@node: the node to check
 *Return: 1 (root), 0 (not root)
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node->parent == NULL);
}
