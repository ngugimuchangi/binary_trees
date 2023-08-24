#include <stdlib.h>
#include "binary_trees.h"

size_t get_node_count(const binary_tree_t *tree);
heap_t *get_last_node(heap_t *root, size_t size);
void top_bottom_heapify(heap_t *root);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 *
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	size_t size;
	heap_t *last = NULL;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	size = get_node_count(*root);
	last = get_last_node(*root, size);

	(*root)->n = last->n;

	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
	}
	free(last);
	top_bottom_heapify(*root);
	return (value);
}

/**
 * get_node_count - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: Number of nodes in the tree
 */
size_t get_node_count(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_node_count(tree->left) + get_node_count(tree->right));
}

/**
 * get_last_node - Gets the last node of a Max Binary Heap
 * Description: This function gets the last node of a Max Binary Heap by
 * traversing the tree from the root to the last node using the binary
 * representation of the size of the Heap.
 *
 * Example: If the Heap has 6 nodes, its size is 6. The binary representation
 * of 6 is 110. Starting from the root, we traverse the tree to the right
 * child, then to the left child. The last node is the left child of the
 * right child of the root.
 *
 * @root: Pointer to the root node of the Heap
 * @size: Size of the Heap
 *
 * Return: Pointer to the last node of the Heap
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t temp_size = size, bit;
	heap_t *node = root;

	while (node->left || node->right)
	{
		temp_size = temp_size << 1;
		bit = temp_size & size;

		if (bit)
			node = node->right;
		else
			node = node->left;
	}
	return (node);
}

/**
 * top_bottom_heapify - Moves the node at the top of the tree down to its
 * correct position in the Max Binary Heap
 *
 * Description: This function compares the value of the current node with the
 * values of its left and right children. If the value of the current node is
 * less than the value of either of its children, the values of the current
 * node and the child node with the largest value are swapped. This process
 * is repeated until the current node is greater than both of its children.
 *
 * @root: Pointer to the root node of the Heap
 * Return: Nothing
 */
void top_bottom_heapify(heap_t *root)
{
	heap_t *largest = NULL, *current = root;
	int temp;

	while (1)
	{
		largest = current;
		if (current->left && current->left->n > current->n)
			largest = current->left;
		if (current->right && current->right->n > largest->n)
			largest = current->right;

		if (largest == current)
			break;
		temp = current->n;
		current->n = largest->n;
		largest->n = temp;
		current = largest;
	}
}
