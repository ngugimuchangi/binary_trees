#include "binary_trees.h"
int get_tree_height(const binary_tree_t *tree);
int max(int a, int b);

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0, left, right;

	if (!tree)
		return (0);
	left = get_tree_height(tree->left);
	right = get_tree_height(tree->right);
	balance_factor = left - right;
	return (balance_factor);
}

int get_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (-1);
	return (max(get_tree_height(tree->left),
				get_tree_height(tree->right)) +
			1);
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
