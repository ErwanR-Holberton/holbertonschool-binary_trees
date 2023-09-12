#include "binary_trees.h"
/**
 * binary_tree_nodes - count nodes with at leat one child
 * @tree: tree to loop through
 * Return: number of nodes whith a child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
	return (0);


}
