#include "binary_trees.h"
#include "113-bst_search.c"

/**
 * handle_child_of_replacement - if replacement have child link it to parent
 * @replacement: node that will be moved
 * Return: NOTHING
 */
void handle_child_of_replacement(bst_t *replacement)
{
	if (replacement->left != NULL)
	{
		if (replacement->parent->left == replacement)
			replacement->parent->left = replacement->left;
		else
			replacement->parent->right = replacement->left;
		replacement->left->parent = replacement->parent;
	}
	else if (replacement->right != NULL)
	{
		if (replacement->parent->left == replacement)
			replacement->parent->left = replacement->right;
		else
			replacement->parent->right = replacement->right;
		replacement->right->parent = replacement->parent;
	}
	else
	{
		if (replacement->parent->left == replacement)
			replacement->parent->left = NULL;
		else
			replacement->parent->right = NULL;
	}
}
/**
 * *find_replacement - find the node in-order successor to replace the other
 * @node: node that will be removed (searches from this point)
 * Return: adress of the replacement node that will be in the place of node
 */
bst_t *find_replacement(bst_t *node)
{
	bst_t *replacement;

	replacement = node->right;
	if (replacement != NULL)
		while (replacement->left != NULL)
			replacement = replacement->left;
	else
	{
		replacement = node->left;
		if (replacement != NULL)
			while (replacement->right != NULL)
				replacement = replacement->right;
	}
	return (replacement);
}
/**
 * replace - switches two nodes and bring up any children to the parent
 * @node: node that will be removed
 * @replacement: node that will replace the other
 * Return:nothing
 */
void replace(bst_t *node, bst_t *replacement)
{
	if (replacement == NULL || node == NULL)
		return;

	handle_child_of_replacement(replacement);

	replacement->left = node->left;
	replacement->right = node->right;
	replacement->parent = node->parent;
	if (node->parent != NULL)
	{
		if (node->parent->left == node)
			node->parent->left = replacement;
		else
			node->parent->right = replacement;
	}

	if (node->left != NULL)
		node->left->parent = replacement;
	if (node->right != NULL)
		node->right->parent = replacement;
}
/**
 * *bst_remove - remove a node and replace it with in order successor
 * @root: root of the tree to search
 * @value: value of the node to delete
 * Return: adress of the new root or NULL if fail or not found
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *replacement;

	if (root == NULL)
		return (NULL);

	node = bst_search(root, value);
	if (node == NULL)
		return (root);

	if (node->left == NULL && node->right == NULL)
	{
		if (node->parent != NULL)
		{
			if (node->parent->left == node)
				node->parent->left = NULL;
			else
				node->parent->right = NULL;
		}
		free(node);
		return (root);
	}
	else
		replacement = find_replacement(node);

	replace(node, replacement);
	if (node == root)
		root = replacement;
	free(node);
	return (root);
}
