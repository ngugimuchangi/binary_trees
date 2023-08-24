# 0x1D. C - Binary trees

## About

This is project to explore the following concepts:

- What is a binary tree
- What is the difference between a binary tree and a Binary Search Tree
- What is the possible gain in terms of time complexity compared to linked lists
- What are the depth, the height, the size of a binary tree
- What are the different traversal methods to go through a binary tree
- What is a complete, a full, a perfect, a balanced binary tree

## Requirements

- Ubuntu 20.04 LTS
- gcc 4.8.4

## Compiling

```
$ gcc -Wall -Werror -Wextra -pedantic --std=c89 *.c -o <output file name>
```

## File Descriptions

### [binary_trees.h](./binary_trees.h)

- Header file containing definitions and prototypes for all types and functions
  written for the project.

### [binary_tree_print.c](utils/binary_tree_print.c)

- Function to print binary trees

### [Tests](tests)

- Folder containing the test files for all the tasks.

## Tasks

### [0. New node](./0-binary_tree_node.c)

- Write a function that creates a binary tree node
  - Prototype:
    `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
  - `parent` is a pointer to the parent node of the node to create
  - `value` is the value to put in the new node
  - When created, a node does not have any children
  - Your function must return a pointer to the new node, or `NULL` on failure

### [1. Insert left](./1-binary_tree_insert_left.c)

- Write a function that inserts a node as the left-child of another node
  - Prototype:
    `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);`
  - `parent` is a pointer to the node to insert the left-child in
  - `value` is the value to store in the new node
  - Your function must return a pointer to the created node, or `NULL` on
    failure or if `parent` is `NULL`
  - If `parent` already has a left-child, the new node must take its place, and
    the old left-child must be set as the left-child of the new node.

### [2. Insert right](./2-binary_tree_insert_right.c)

- Write a function that inserts a node as the right-child of another node
  - Prototype:
    `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);`
  - `parent` is a pointer to the node to insert the right-child in
  - `value` is the value to store in the new node
  - Your function must return a pointer to the created node, or `NULL` on
    failure or if `parent` is `NULL`
  - If `parent` already has a right-child, the new node must take its place, and
    the old right-child must be set as the right-child of the new node.

### [3. Delete](./3-binary_tree_delete.c)

- Write a function that deletes an entire binary tree
  - Prototype: `void binary_tree_delete(binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to delete
  - If `tree` is `NULL`, do nothing

### [4. Is leaf](./4-binary_tree_is_leaf.c)

- Write a function that checks if a node is a leaf
  - Prototype: `int binary_tree_is_leaf(const binary_tree_t *node);`
  - `node` is a pointer to the node to check
  - Your function must return `1` if `node` is a leaf, otherwise `0`
  - If `node` is `NULL`, return `0`

### [5. Is root](./5-binary_tree_is_root.c)

- Write a function that checks if a given node is a root
  - Prototype: `int binary_tree_is_root(const binary_tree_t *node);`
  - `node` is a pointer to the node to check
  - Your function must return `1` if `node` is a root, otherwise `0`
  - If `node` is `NULL`, return `0`

### [6. Pre-order traversal](./6-binary_tree_preorder.c)

- Write a function that goes through a binary tree using pre-order traversal
  - Prototype:
    `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));`
  - `tree` is a pointer to the root node of the tree to traverse
  - `func` is a pointer to a function to call for each node. The value in the
    node must be passed as a parameter to this function.
  - If `tree` or `func` is `NULL`, do nothing

### [7. In-order traversal](./7-binary_tree_inorder.c)

- Write a function that goes through a binary tree using in-order traversal
  - Prototype:
    `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));`
  - `tree` is a pointer to the root node of the tree to traverse
  - `func` is a pointer to a function to call for each node. The value in the
    node must be passed as a parameter to this function.
  - If `tree` or `func` is `NULL`, do nothing

### [8. Post-order traversal](./8-binary_tree_postorder.c)

- Write a function that goes through a binary tree using post-order traversal
  - Prototype:
    `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));`
  - `tree` is a pointer to the root node of the tree to traverse
  - `func` is a pointer to a function to call for each node. The value in the
    node must be passed as a parameter to this function.
  - If `tree` or `func` is `NULL`, do nothing

### [9. Height](./9-binary_tree_height.c)

- Write a function that measures the height of a binary tree
  - Prototype: `size_t binary_tree_height(const binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to measure the height.
  - If `tree` is `NULL`, your function must return `0`

### [10. Depth](./10-binary_tree_depth.c)

- Write a function that measures the depth of a node in a binary tree
  - Prototype: `size_t binary_tree_depth(const binary_tree_t *tree);`
  - `tree` is a pointer to the node to measure the depth
  - If `tree` is `NULL`, your function must return `0`

### [11. Size](./11-binary_tree_size.c)

- Write a function that measures the size of a binary tree
  - Prototype: `size_t binary_tree_size(const binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to measure the size
  - If `tree` is `NULL`, the function must return `0`

### [12. Leaves](./12-binary_tree_leaves.c)

- Write a function that counts the leaves in a binary tree
  - Prototype: `size_t binary_tree_leaves(const binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to count the number of
    leaves
  - If `tree` is `NULL`, the function must return `0`
  - A `NULL` pointer is not a leaf

### [13. Nodes](./13-binary_tree_nodes.c)

- Write a function that counts the nodes with at least 1 child in a binary tree
  - Prototype: `size_t binary_tree_nodes(const binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to count the number of
    nodes
  - If `tree` is `NULL`, the function must return `0`
  - A `NULL` pointer is not a node

### [14. Balance factor](./14-binary_tree_balance.c)

- Write a function that measures the balance factor of a binary tree
  - Prototype: `int binary_tree_balance(const binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to measure the balance
    factor
  - If `tree` is `NULL`, return `0`

### [15. Is full](./15-binary_tree_is_full.c)

- Write a function that checks if a binary tree is full
  - Prototype: `int binary_tree_is_full(const binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to check
  - If `tree` is `NULL`, your function must return `0`

### [16. Is perfect](./16-binary_tree_is_perfect.c)

- Write a function that checks if a binary tree is perfect
  - Prototype: `int binary_tree_is_perfect(const binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to check
  - If `tree` is `NULL`, your function must return `0`

### [17. Sibling](./17-binary_tree_sibling.c)

- Write a function that finds the sibling of a node
  - Prototype: `binary_tree_t *binary_tree_sibling(binary_tree_t *node);`
  - `node` is a pointer to the node to find the sibling
  - Your function must return a pointer to the sibling node
  - If `node` is `NULL` or the parent is `NULL`, return `NULL`
  - If `node` has no sibling, return `NULL`

### [18. Uncle](./18-binary_tree_uncle.c)

- Write a function that finds the uncle of a node
  - Prototype: `binary_tree_t *binary_tree_uncle(binary_tree_t *node);`
  - `node` is a pointer to the node to find the uncle
  - Your function must return a pointer to the uncle node
  - If `node` is `NULL`, return `NULL`
  - If `node` has no uncle, return `NULL`

### [19. Lowest common ancestor](./100-binary_trees_ancestor.c)

- Write a function that finds the lowest common ancestor of two nodes
  - Prototype:
    `binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);`
  - `first` is a pointer to the first node
  - `second` is a pointer to the second node
  - Your function must return a pointer to the lowest common ancestor node of
    the two given nodes
  - If no common ancestor was found, your function must return `NULL`
  - Note: The lowest common ancestor is defined for two nodes `p` and `q` as the
    lowest node in `T` that has both `p` and `q` as descendants where we allow a
    node to be a descendant of itself.

### [20. Level-order traversal](./101-binary_tree_levelorder.c)

- Write a function that goes through a binary tree using level-order traversal
  - Prototype:
    `void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));`
  - `tree` is a pointer to the root node of the tree to traverse
  - `func` is a pointer to a function to call for each node. The value in the
    node must be passed as a parameter to this function.
  - If `tree` or `func` is `NULL`, do nothing

### [21. Is complete](./102-binary_tree_is_complete.c)

- Write a function that checks if a binary tree is complete
  - Prototype: `int binary_tree_is_complete(const binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to check
  - If `tree` is `NULL`, your function must return `0`

### [22. Rotate left](./103-binary_tree_rotate_left.c)

- Write a function that performs a left-rotation on a binary tree
  - Prototype: `binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to rotate
  - Your function must return a pointer to the new root node of the tree once
    rotated

### [23. Rotate right](./104-binary_tree_rotate_right.c)

- Write a function that performs a right-rotation on a binary tree
  - Prototype: `binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to rotate
  - Your function must return a pointer to the new root node of the tree once
    rotated

### [24. Is BST](./110-binary_tree_is_bst.c)

- Write a function that checks if a binary tree is a valid Binary Search Tree
  - Prototype: `int binary_tree_is_bst(const binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to check
  - Your function must return `1` if `tree` is a valid BST, and `0` otherwise
  - If `tree` is `NULL`, return `0`

### [25. BST - Insert](./111-bst_insert.c)

- Write a function that inserts a value in a Binary Search Tree
  - Prototype: `bst_t *bst_insert(bst_t **tree, int value);`
  - `tree` is a double pointer to the root node of the BST to insert the value
  - Once inserted, the tree must be in a valid BST order
  - If `tree` is `NULL`, the created node must become the root node.
  - Return a pointer to the created node, or `NULL` on failure
  - If the address stored in `tree` is `NULL`, the created node must become the
    root node.

### [26. BST - Array to BST](./112-array_to_bst.c)

- Write a function that builds a Binary Search Tree from an array
  - Prototype: `bst_t *array_to_bst(int *array, size_t size);`
  - `array` is a pointer to the first element of the array to be converted
  - `size` is the number of element in the array
  - Your function must return a pointer to the root node of the created BST, or
    `NULL` on failure
  - If a value of the array is already present in the tree, this value must be
    ignored

### [27. BST - Search](./113-bst_search.c)

- Write a function that searches for a value in a Binary Search Tree
  - Prototype: `bst_t *bst_search(const bst_t *tree, int value);`
  - `tree` is a pointer to the root node of the BST to search
  - `value` is the value to search in the tree
  - Your function must return a pointer to the node containing a value equals to
    `value`
  - If `tree` is `NULL` or if nothing is found, your function must return `NULL`

### [28. BST - Remove](./114-bst_remove.c)

- Write a function that removes a node from a Binary Search Tree
  - Prototype: `bst_t *bst_remove(bst_t *root, int value);`
  - `root` is a pointer to the root node of the tree where you will remove a
    node
  - `value` is the value to remove in the tree
  - Once located, the node containing a value equals to `value` must be removed
    and freed
  - If the node to be deleted is a leaf, it can be simply removed
  - If the node to be deleted is a root node, the root pointer must be updated
  - When removing a node with two children, it must be replaced with its first
    in-order successor (not predecessor)
  - Your function must return a pointer to the new root node of the tree after
    removing the desired value

### [29. Big O #BST](./115-O)

- What are the average time complexities of those operations on a Binary Search
  Tree (one answer per line):
  - Inserting the value `n`
  - Removing the node with the value `n`
  - Searching for a node in a BST of size `n`

### [30. Is AVL](./120-binary_tree_is_avl.c)

- Write a function that checks if a binary tree is a valid AVL Tree
  - Prototype: `int binary_tree_is_avl(const binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to check
  - Your function must return `1` if `tree` is a valid AVL Tree, and `0`
    otherwise
  - If `tree` is `NULL`, return `0`

### [31. AVL - Insert](./121-avl_insert.c)

- Write a function that inserts a value in an AVL Tree
  - Prototype: `avl_t *avl_insert(avl_t **tree, int value);`
  - `tree` is a double pointer to the root node of the AVL tree for inserting
    the value
  - Once inserted, the tree must be in a valid AVL Tree order
  - Rebalancing of nodes is not allowed
  - You can assume that `value` will be inserted in a binary search tree
  - `value` won’t appear twice
  - Return a pointer to the created node, or `NULL` on failure
  - If the address stored in `tree` is `NULL`, the created node must become the
    root node.

### [32. AVL - Array to AVL](./122-array_to_avl.c)

- Write a function that builds an AVL tree from an array
  - Prototype: `avl_t *array_to_avl(int *array, size_t size);`
  - `array` is a pointer to the first element of the array to be converted
  - `size` is the number of element in the array
  - Your function must return a pointer to the root node of the created AVL
    tree, or `NULL` on failure
  - If a value of the array is already present in the tree, this value must be
    ignored

### [33. AVL - Remove](./123-avl_remove.c)

- Write a function that removes a node from an AVL tree
  - Prototype: `avl_t *avl_remove(avl_t *root, int value);`
  - `root` is a pointer to the root node of the tree for removing a node
  - `value` is the value to remove in the tree
  - Once located, the node containing a value equals to `value` must be removed
    and freed
  - If the node to be deleted is a leaf, it can be simply removed
  - If the node to be deleted has only one child, it should be replaced by its
    child
  - When removing a node with two children, it must be replaced with its first
    in-order successor (not predecessor)
  - Your function must return a pointer to the new root node of the tree after
    removing the desired value

### [34. AVL - From sorted array](./124-sorted_array_to_avl.c)

- Write a function that builds an AVL tree from an array
  - Prototype: `avl_t *sorted_array_to_avl(int *array, size_t size);`
  - `array` is a pointer to the first element of the array to be converted
  - `size` is the number of element in the array
  - Your function must return a pointer to the root node of the created AVL
    tree, or `NULL` on failure
  - You can assume there will be no duplicate value in the array
  - You are not allowed to rotate
  - You can only have 3 functions in your file

### [35. Big O #AVL Tree](./125-O)

- What are the average time complexities of those operations on an AVL Tree (one
  answer per line):
  - Inserting the value `n`
  - Removing the node with the value `n`
  - Searching for a node in an AVL tree of size `n`

### [36. Is Binary heap](./130-binary_tree_is_heap.c)

- Write a function that checks if a binary tree is a valid Max Binary Heap
  - Prototype: `int binary_tree_is_heap(const binary_tree_t *tree);`
  - `tree` is a pointer to the root node of the tree to check
  - Your function must return `1` if `tree` is a valid Max Binary Heap, and `0`
    otherwise
  - If `tree` is `NULL`, return `0`

### [37. Heap - Insert](./131-heap_insert.c)

- Write a function that inserts a value in Max Binary Heap
  - Prototype: `heap_t *heap_insert(heap_t **root, int value);`
  - `root` is a double pointer to the root node of the Heap to insert the value
  - Once inserted, the tree must be in Max Heap order
  - You have to respect a `Max Heap` ordering
  - You are allowed to have up to `6` functions in your file

### [38. Heap - Array to Binary Heap](./132-array_to_heap.c)

- Write a function that builds a Max Binary Heap tree from an array
  - Prototype: `heap_t *array_to_heap(int *array, size_t size);`
  - `array` is a pointer to the first element of the array to be converted
  - `size` is the number of element in the array
  - Your function must return a pointer to the root node of the created Binary
    Heap, or `NULL` on failure
  - If `array` is `NULL` or `size` is `0`, return `NULL`
  - You can assume there will be no duplicate value in the array
  - You are allowed to use `printf`

### [39. Heap - Extract](./133-heap_extract.c)

- Write a function that extracts the root node of a Max Binary Heap
  - Prototype: `int heap_extract(heap_t **root);`
  - `root` is a double pointer to the root node of the heap
  - Your function must return the value stored in the root node
  - The root node must be freed and replace with the last `level-order` node of
    the heap
  - Once replaced, the heap must be rebuilt if necessary
  - If your function fails, return `0`

### [40. Heap - Sort](./134-heap_to_sorted_array.c)

- Write a function that converts a Binary Max Heap to a sorted array of integers
  - Prototype: `int *heap_to_sorted_array(heap_t *heap, size_t *size);`
  - `heap` is a pointer to the root node of the heap to convert
  - `size` is the address to a variable containing the size of the array
  - Your function must return an array containing all values stored in the heap
    sorted in ascending order
  - If your function fails, return `NULL`
  - You can assume that `size` will be lower than `INT_MAX`
  - You are allowed to use `malloc` and `free` only once (only one call)

### [41. Big O #Binary Heap](./135-O)

- What are the average time complexities of those operations on a Binary Heap
  (one answer per line):
  - Inserting the value `n`
  - Extracting the root node
  - Searching for a node in a binary heap of size `n`

---

## Author

- [**Duncan Ngugi**](github.com/ngugimuchangi)

---
