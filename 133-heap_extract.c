#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

int get_node_count(const binary_tree_t *tree);
void heapify_tree(heap_t **arr, int index, int size);
void create_array_from_heap(heap_t **arr, heap_t *root, int index, int size);
heap_t *generate_heap(heap_t **arr, heap_t *parent, int index, int size);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 *
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value, size, i;
	heap_t **arr = NULL, *last_node = NULL;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	size = get_node_count(*root);

	/* Create an array of nodes from the heap */
	arr = malloc(sizeof(heap_t **) * size);
	if (!arr)
		return (0);
	create_array_from_heap(arr, *root, 0, size);

	/* Replace root node with last node */
	last_node = arr[size - 1];
	(*root)->n = last_node->n;
	free(last_node);

	/* Heapify the tree */
	size = size - 1;
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify_tree(arr, i, size);

	/* Generate a Max Binary Heap from the array */
	*root = generate_heap(arr, NULL, 0, size);

	free(arr);
	return (value);
}

/**
 * get_node_count - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: Number of nodes in the tree
 */
int get_node_count(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_node_count(tree->left) + get_node_count(tree->right));
}

/**
 * create_array_from_heap - Creates an array of nodes from a Max Binary Heap
 *
 * @root: Pointer to the root node of the Heap to convert
 * @arr: Pointer to the array to be created from the Heap
 * @index: Index of array
 * @size: Size of the array
 *
 * Return: Nothing
 */
void create_array_from_heap(heap_t **arr, heap_t *root, int index, int size)
{
	if (index >= size)
		return;
	arr[index] = root;
	create_array_from_heap(arr, root->left, 2 * index + 1, size);
	create_array_from_heap(arr, root->right, 2 * index + 2, size);
}

/**
 * generate_heap - Creates a Max Binary Heap tree from an array
 *
 * @arr: Pointer to the array to be converted
 * @parent: Pointer to the parent node
 * @index: Index of current node
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the created Max Binary Heap
 */
heap_t *generate_heap(heap_t **arr, heap_t *parent, int index, int size)
{
	heap_t *node;

	if (index >= size)
		return (NULL);
	node = arr[index];
	node->parent = parent;
	node->left = generate_heap(arr, node, 2 * index + 1, size);
	node->right = generate_heap(arr, node, 2 * index + 2, size);

	return (node);
}

/**
 * heapify_tree - Converts an array into a Max Binary Heap
 *
 * @arr: Pointer to the first element of the array to be converted
 * @index: Index of current node
 * @size: Size of the array
 *
 * Return: Nothing
 */
void heapify_tree(heap_t **arr, int index, int size)
{
	int largest = index, l = index * 2 + 1, r = index * 2 + 2;
	heap_t *temp = NULL;

	if (l < size && (arr[largest])->n < (arr[l])->n)
		largest = l;
	if (r < size && (arr[largest])->n < (arr[r])->n)
		largest = r;
	if (largest != index)
	{
		temp = arr[index];
		arr[index] = arr[largest];
		arr[largest] = temp;
		heapify_tree(arr, largest, size);
	}
}
