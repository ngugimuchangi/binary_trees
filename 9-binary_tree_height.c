#include <stdlib.h>
#include "binary_trees.h"

size_t max(size_t a, size_t b);
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	return (max(binary_tree_height(tree->left),
				binary_tree_height(tree->right)) +
			1);
}

/**
 * max - returns the max of two numbers
 * @a: first number
 * @b: second number
 * Return: max of a and b
 */
size_t max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}
