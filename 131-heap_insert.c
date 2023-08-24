#include <stdlib.h>
#include "binary_trees.h"

int get_total_nodes(const binary_tree_t *tree);
void heapify(heap_t **arr, int index, int size);
void array_from_heap(heap_t **arr, heap_t *root, int index, int size);
heap_t *create_heap(heap_t **arr, heap_t *parent, int index, int size);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int i, node_count;
	heap_t **nodes_array = NULL, *new_node = NULL;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	node_count = get_total_nodes(*root) + 1;
	nodes_array = malloc(sizeof(heap_t **) * node_count);
	if (!nodes_array)
		return (NULL);

	array_from_heap(nodes_array, *root, 0, node_count - 1);
	nodes_array[node_count - 1] = new_node;

	for (i = (node_count / 2) - 1; i >= 0; i--)
		heapify(nodes_array, i, node_count);

	*root = create_heap(nodes_array, NULL, 0, node_count);
	free(nodes_array);
	return (new_node);
}

/**
 * get_total_nodes - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: Number of nodes in the tree
 */
int get_total_nodes(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_total_nodes(tree->left) + get_total_nodes(tree->right));
}

/**
 * array_from_heap - Creates an array of nodes from a Max Binary Heap
 *
 * @root: Pointer to the root node of the Heap to convert
 * @arr: Pointer to the array to be created from the Heap
 * @index: Index of array
 * @size: Size of the array
 *
 * Return: Nothing
 */
void array_from_heap(heap_t **arr, heap_t *root, int index, int size)
{
	if (index >= size)
		return;
	arr[index] = root;
	array_from_heap(arr, root->left, 2 * index + 1, size);
	array_from_heap(arr, root->right, 2 * index + 2, size);
}

/**
 * create_heap - Creates a Max Binary Heap tree from an array
 *
 * @arr: Pointer to the array to be converted
 * @parent: Pointer to the parent node
 * @index: Index of current node
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the created Max Binary Heap
 */
heap_t *create_heap(heap_t **arr, heap_t *parent, int index, int size)
{
	heap_t *node;

	if (index >= size)
		return (NULL);
	node = arr[index];
	node->parent = parent;
	node->left = create_heap(arr, node, 2 * index + 1, size);
	node->right = create_heap(arr, node, 2 * index + 2, size);

	return (node);
}

/**
 * heapify - Converts an array into a Max Binary Heap
 *
 * @arr: Pointer to the first element of the array to be converted
 * @index: Index of current node
 * @size: Size of the array
 *
 * Return: Nothing
 */
void heapify(heap_t **arr, int index, int size)
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
		heapify(arr, largest, size);
	}
}
