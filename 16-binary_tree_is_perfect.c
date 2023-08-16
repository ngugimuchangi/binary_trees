#include "binary_trees.h"
#include <stdio.h>

size_t depth(const binary_tree_t *tree);
int is_perfect(const binary_tree_t *tree, size_t depth, size_t max_depth);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t max_depth = depth(tree);

	if (!tree)
		return (0);
	return (is_perfect(tree, 0, max_depth));
}

/**
 * is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @depth: depth of the current node
 * @max_depth: depth of the deepest node
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int is_perfect(const binary_tree_t *tree, size_t depth, size_t max_depth)
{
	if (!tree)
		return (1);
	if ((!tree->left && tree->right) || (tree->left && !tree->right))
		return (0);
	if (depth > max_depth)
		return (0);
	depth += 1;
	return (is_perfect(tree->left, depth, max_depth) &&
			is_perfect(tree->right, depth, max_depth));
}

/**
 * depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of the node, 0 if tree is NULL
 */
size_t depth(const binary_tree_t *tree)
{
	binary_tree_t *node = (binary_tree_t *)tree;
	size_t depth = 0;

	while (node)
	{
		depth += 1;
		node = node->left;
	}
	return (depth - 1);
}
