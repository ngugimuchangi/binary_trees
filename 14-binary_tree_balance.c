#include "binary_trees.h"
int get_tree_height(const binary_tree_t *tree);
int max(int a, int b);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor of a binary tree
 */
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

/**
 * get_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of a binary tree
 */
int get_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (-1);
	return (max(get_tree_height(tree->left),
				get_tree_height(tree->right)) +
			1);
}

/**
 * max - returns the maximum of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: maximum of two integers
 */
int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
