#include <stdlib.h>
#include "binary_trees.h"

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t internal_nodes = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	internal_nodes = 1 + binary_tree_nodes(tree->left) +
					 binary_tree_nodes(tree->right);
	return (internal_nodes);
}
