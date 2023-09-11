#include "binary_trees.h"

/**
 * *binary_tree_insert_right - creates a right child for the parent
 *
 * @parent: Pointer to the node to add a child
 * @value: value of the node to create
 *
 * Description: creates a right child for the parent
 * if there is already a node it become the child of the new one
 * Return: pointer to the created node or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	new_node->right = parent->right;
	if (new_node->right != NULL)
		new_node->right->parent = new_node;

	parent->right = new_node;

	return (new_node);
}
