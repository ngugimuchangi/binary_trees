#include "binary_trees.h"
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the desired
 * value, or NULL if value doesn't exist
 */
bst_t *bst_remove(bst_t *root, int value) {}

bst_t *inorder_successor(bst_t *node)
{
	bst_t *current = node;

	while (current->left)
		current = current->left;
	return (current);
}
