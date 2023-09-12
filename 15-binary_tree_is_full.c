#include "binary_trees.h"
#include "11-binary_tree_size.c"
#include "9-binary_tree_height.c"
/**
 * binary_tree_is_full - checks if tree is full
 *@tree: tree to check
 *
 *Return: 1 full 0 not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t size, i, j, sum = 0, pow;
	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	for (i = 0; i <= binary_tree_height(tree); i++)
	{
		for (j = 0, pow = 1; j < i; j++)
			pow *= 2;
		sum += pow;
	}
	if (sum == size)
		return (1);
	return (0);
}
