#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *current = NULL;

	if (!tree)
		return (0);
	current = tree->parent;

	while (current)
	{
		depth += 1;
		current = current->parent;
	}
	return (depth);
}
