#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * Description: The lowest common ancestor is the farthest node from the root
 * that is an ancestor of both nodes. This solution give O(n^2) time complexity
 * but it can be improve with a hash set to store the ancestors of the first
 * then traverse the ancestors of the second to find the first common ancestor
 * resulting in O(n) time complexity.
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
	node_one = (binary_tree_t *)first;

	while (node_one)
	{
		node_two = (binary_tree_t *)second;
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
