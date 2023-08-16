#include "binary_trees.h"
#include <stdio.h>

size_t depth(const binary_tree_t *tree);
int is_perfect(const binary_tree_t *tree, size_t depth, size_t max_depth);

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t max_depth = depth(tree);

	if (!tree)
		return (0);
	return (is_perfect(tree, 0, max_depth));
}

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
