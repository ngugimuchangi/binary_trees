#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *node_one, *node_two;

	if (!first || !second)
		return (NULL);
	node_one = first;

	while (node_one)
	{
		node_two = second;
		while (node_two)
		{
			if (node_one == node_two)
				return (node_one);
			node_two = node_two->parent;
		}
		node_one = node_one->parent;
	}
	return (NULL);
}
