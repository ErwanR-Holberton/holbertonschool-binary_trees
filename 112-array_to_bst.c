#include "binary_trees.h"
/**
 * *array_to_bst - create a binary search tree from an array
 * @array: future tree
 * @size: number of elements in the array
 * Return: adress of the root of the tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
