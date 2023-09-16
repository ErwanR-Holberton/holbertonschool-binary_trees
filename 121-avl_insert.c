#include "binary_trees.h"
#include "111-bst_insert.c"
#include "120-binary_tree_is_avl.c"
avl_t *find_non_avl_node(avl_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->left != NULL)
		if (binary_tree_is_avl(node->left) == 0)
			return (find_non_avl_node(node->left));
	if (node->right != NULL)
		if (binary_tree_is_avl(node->right) == 0)
			return (find_non_avl_node(node->right));
	if (binary_tree_is_avl(node))
		return (NULL);
	return (node);
}
/**
 * *avl_insert - insert a node in an avl tree
 * @tree: tree to insert into
 * Return: adress of nex node or null for failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = bst_insert(tree, value), *node, *save;

	(void)node;
	if (binary_tree_is_avl(*tree))
		return (new);
	else
		node = find_non_avl_node(*tree);


	if (binary_tree_balance(node) < -1)
	{
		if (binary_tree_balance(node->right) == 1)
		{
			node->right = binary_tree_rotate_left(node->right);
			node->right->parent = node;
		}

		if (node->parent->left == node)
		{
			save = node->parent;
			node->parent->left = binary_tree_rotate_left(node);
			node->parent->parent = save;
		}
		else
		{
			node->parent->right = binary_tree_rotate_left(node);
			node->parent->right->parent = node->parent;
		}
	}
	else if (binary_tree_balance(node) > 1)
	{
		if (binary_tree_balance(node->left) == -1)
		{
			node->left = binary_tree_rotate_left(node->left);
			node->left->parent = node;
		}
		if (node->parent->left == node)
		{
			node->parent->left = binary_tree_rotate_right(node);
			node->parent->left->parent = node->parent;
		}
		else
		{
			node->parent->right = binary_tree_rotate_right(node);
			node->parent->right->parent = node->parent;
		}
	}

	return (new);

}
