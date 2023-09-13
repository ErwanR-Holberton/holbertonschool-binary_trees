#include "binary_trees.h"
#include "1-binary_tree_insert_left.c"
#include "2-binary_tree_insert_right.c"

/**
 *bst_insert - insert a new value
 *@tree: tree to loop through
 *@value: insert value
 *Return: bst
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		(*tree = binary_tree_node(NULL, value));
		return (*tree);
		}
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
			return (binary_tree_insert_left(*tree, value));
		return (bst_insert(&(*tree)->left, value));
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
			return (binary_tree_insert_right(*tree, value));
		return (bst_insert(&(*tree)->right, value));
	}
	return (NULL);
}
