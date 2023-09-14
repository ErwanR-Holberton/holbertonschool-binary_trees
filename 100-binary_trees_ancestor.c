#include "binary_trees.h"
#include "10-binary_tree_depth.c"
#include <stdio.h>
/**
 * *binary_trees_ancestor - find lowest common ancestor
 * @first: first node to find the ancestor
 * @second: node to find the ancestor
 * Return: address of the ancestor or null
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t **path1, **path2, *cur, *res = NULL;/*cur means current*/
	int i, depth1, depth2;

	if (first == NULL || second == NULL)
		return (NULL);

	depth1 = binary_tree_depth(first) + 1;
	depth2 = binary_tree_depth(second) + 1;

	path1 = malloc(depth1 * sizeof(binary_tree_t *));
	path2 = malloc(depth2 * sizeof(binary_tree_t *));

	for (cur = (void *)first, i = depth1 - 1; cur != NULL; cur = cur->parent, i--)
		path1[i] = cur;

	i = depth2 - 1;
	for (cur = (void *)second; cur != NULL; cur = cur->parent, i--)
		path2[i] = cur;

	if (path1[0] != path2[0])
	{
		free(path1);
		free(path2);
		return (0);
	}

	for (i = 0; i < depth1 && i < depth2; i++)
		if (path1[i] == path2[i])
			res = path1[i];

	free(path1);
	free(path2);

	return (res);
}
