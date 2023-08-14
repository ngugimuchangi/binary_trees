#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a node as the right-child of another node
 * Description: If parent already has a right-child, the new node must take its
 * place, and the old right-child must be set as the right-child of the new
 * node.
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: binary_tree_t* - pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *temp = NULL, *node = NULL;

	if (!parent)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	if (parent->right)
	{
		temp = parent->right;
		node->right = temp;
		temp->parent = node;
	}
	parent->right = node;
	return (node);
}
