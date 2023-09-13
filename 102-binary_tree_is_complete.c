#include "binary_trees.h"
#include "14-binary_tree_balance.c"
#include "15-binary_tree_is_full.c"
/**
 * binary_tree_is_complete - check if the given tree is complete
 * @tree: tree to loop through
 * Return: 1 if complete 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (0);

	balance = binary_tree_balance(tree);

	if (balance < 0 || balance > 1)
		return (0);
	if (tree->left == NULL || tree->right == NULL)
		return (1);
	if (balance == 0)
		if (binary_tree_is_full(tree->left) == 0)
			return (0);
	return (binary_tree_is_complete(tree->left) &&
	binary_tree_is_complete(tree->right));
}
