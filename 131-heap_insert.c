#include <stdlib.h>
#include "binary_trees.h"

int node_count(const binary_tree_t *tree);
void max_heapify(heap_t **arr, int index, int size);
void max_heap_to_array(heap_t **arr, heap_t *root, int index, int size);
heap_t *array_to_max_heap(heap_t **arr, heap_t *parent, int index, int size);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int i, size;
	heap_t **nodes_array = NULL, *new_node = NULL;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	size = node_count(*root) + 1;
	nodes_array = malloc(sizeof(heap_t **) * size);
	if (!nodes_array)
		return (NULL);

	max_heap_to_array(nodes_array, *root, 0, size - 1);
	nodes_array[size - 1] = new_node;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(nodes_array, i, size);

	*root = array_to_max_heap(nodes_array, NULL, 0, size);
	free(nodes_array);
	return (new_node);
}

/**
 * node_count - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: Number of nodes in the tree
 */
int node_count(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + node_count(tree->left) + node_count(tree->right));
}

/**
 * max_heap_to_array - Creates an array of nodes from a Max Binary Heap
 *
 * @root: Pointer to the root node of the Heap to convert
 * @arr: Pointer to the array to be created from the Heap
 * @index: Index of array
 * @size: Size of the array
 *
 * Return: Nothing
 */
void max_heap_to_array(heap_t **arr, heap_t *root, int index, int size)
{
	if (index >= size)
		return;
	arr[index] = root;
	max_heap_to_array(arr, root->left, 2 * index + 1, size);
	max_heap_to_array(arr, root->right, 2 * index + 2, size);
}

/**
 * array_to_max_heap - Creates a Max Binary Heap tree from an array
 *
 * @arr: Pointer to the array to be converted
 * @parent: Pointer to the parent node
 * @index: Index of current node
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the created Max Binary Heap
 */
heap_t *array_to_max_heap(heap_t **arr, heap_t *parent, int index, int size)
{
	heap_t *node;

	if (index >= size)
		return (NULL);
	node = arr[index];
	node->parent = parent;
	node->left = array_to_max_heap(arr, node, 2 * index + 1, size);
	node->right = array_to_max_heap(arr, node, 2 * index + 2, size);

	return (node);
}

/**
 * max_heapify - Converts an array into a Max Binary Heap
 *
 * @arr: Pointer to the first element of the array to be converted
 * @index: Index of current node
 * @size: Size of the array
 *
 * Return: Nothing
 */
void max_heapify(heap_t **arr, int index, int size)
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
		max_heapify(arr, largest, size);
	}
}
