#include "binary_trees.h"

/**
 *binary_tree_depth - find the depth of the node
 *@tree: tree to loop through
 *Return: depth of the node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	int n = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		tree = tree->parent;
		n++;
	}
	return (n);
}
