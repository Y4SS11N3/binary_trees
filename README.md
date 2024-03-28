# 0x1D. C - Binary Trees

## Introduction

This project dives into the implementation and manipulation of various types of binary trees in C. From the creation of nodes to more complex operations such as insertion, deletion, and traversal, this guide covers a comprehensive list of tasks tailored to explore the functionality and application of binary trees, including Binary Search Trees (BST), AVL Trees, and Max Binary Heaps.

## Table of Contents

* [General Requirements](#general-requirements)
* [Data Structures](#data-structures)
* [Tasks Overview](#tasks-overview)

## General Requirements

* **Compilation**: Ubuntu 20.04 LTS using gcc with `-Wall -Werror -Wextra -pedantic -std=gnu89`
* **Coding Style**: Betty style
* **Restrictions**:
    * No global variables
    * No more than 5 functions per file
    * No more than 40 lines per function
    * Standard library allowed

## Data Structures

### Basic Binary Tree

``` c
/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Binary Search Tree */
typedef struct binary_tree_s bst_t;

/* AVL Tree */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;
```

## Tasks Overview

| Task No. | Task Title | Description | Prototype |
| -------- | ---------- | ----------- | --------- |
| 0 | New node | Creates a binary tree node. | `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);` |
| 1 | Insert left | Inserts a node as the left-child of another node. | `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);` |
| 2 | Insert right | Inserts a node as the right-child of another node. | `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);` |
| 3 | Delete | Deletes an entire binary tree. | `void binary_tree_delete(binary_tree_t *tree);` |
| 4 | Is leaf | Checks if a node is a leaf. | `int binary_tree_is_leaf(const binary_tree_t *node);` |
| 5 | Is root | Checks if a given node is a root. | `int binary_tree_is_root(const binary_tree_t *node);` |
| 6 | Pre-order traversal | Goes through a binary tree using pre-order traversal. | `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));` |
| 7 | In-order traversal | Goes through a binary tree using in-order traversal. | `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));` |
| 8 | Post-order traversal | Goes through a binary tree using post-order traversal. | `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));` |
| 9 | Height | Measures the height of a binary tree. | `size_t binary_tree_height(const binary_tree_t *tree);` |
| 10 | Depth | Measures the depth of a node in a binary tree. | `size_t binary_tree_depth(const binary_tree_t *tree);` |
| 11 | Size | Measures the size of a binary tree. | `size_t binary_tree_size(const binary_tree_t *tree);` |
| 12 | Leaves | Counts the leaves in a binary tree. | `size_t binary_tree_leaves(const binary_tree_t *tree);` |
| 13 | Nodes | Counts the nodes with at least 1 child in a binary tree. | `size_t binary_tree_nodes(const binary_tree_t *tree);` |
| 14 | Balance factor | Measures the balance factor of a binary tree. | `int binary_tree_balance(const binary_tree_t *tree);` |
| 15 | Is full | Checks if a binary tree is full. | `int binary_tree_is_full(const binary_tree_t *tree);` |
| 16 | Is perfect | Checks if a binary tree is perfect. | `int binary_tree_is_perfect(const binary_tree_t *tree);` |
| 17 | Sibling | Finds the sibling of a node. | `binary_tree_t *binary_tree_sibling(binary_tree_t *node);` |
| 18 | Uncle | Finds the uncle of a node. | `binary_tree_t *binary_tree_uncle(binary_tree_t *node);` |
| 19 | Lowest common ancestor | Finds the lowest common ancestor of two nodes. | `binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);` |
| 20 | Level-order traversal | Goes through a binary tree using level-order traversal. | `void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));` |
| 21 | Is complete | Checks if a binary tree is complete. | `int binary_tree_is_complete(const binary_tree_t *tree);` |
| 22 | Rotate left | Performs a left-rotation on a binary tree. | `binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);` |
| 23 | Rotate right | Performs a right-rotation on a binary tree. | `binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);` |
| 24 | Is BST | Checks if a binary tree is a valid Binary Search Tree. | `int binary_tree_is_bst(const binary_tree_t *tree);` |
| 25 | BST - Insert | Inserts a value in a Binary Search Tree. | `bst_t *bst_insert(bst_t **tree, int value);` |
| 26 | BST - Array to BST | Builds a Binary Search Tree from an array. | `bst_t *array_to_bst(int *array, size_t size);` |
| 27 | BST - Search | Searches for a value in a Binary Search Tree. | `bst_t *bst_search(const bst_t *tree, int value);` |
| 28 | BST - Remove | Removes a node from a Binary Search Tree. | `bst_t *bst_remove(bst_t *root, int value);` |
| 29 | Big O #BST | Analyzes the average time complexities of operations on a Binary Search Tree. | N/A |
| 30 | Is AVL | Checks if a binary tree is a valid AVL Tree. | `int binary_tree_is_avl(const binary_tree_t *tree);` |
| 31 | AVL - Insert | Inserts a value in an AVL Tree. | `avl_t *avl_insert(avl_t **tree, int value);` |
| 32 | AVL - Array to AVL | Builds an AVL tree from an array. | `avl_t *array_to_avl(int *array, size_t size);` |
| 33 | AVL - Remove | Removes a node from an AVL tree. | `avl_t *avl_remove(avl_t *root, int value);` |
| 34 | AVL - From sorted array | Builds an AVL tree from a sorted array. | `avl_t *sorted_array_to_avl(int *array, size_t size);` |
| 35 | Big O #AVL Tree | Analyzes the average time complexities of operations on an AVL Tree. | N/A |
| 36 | Is Binary heap | Checks if a binary tree is a valid Max Binary Heap. | `int binary_tree_is_heap(const binary_tree_t *tree);` |
| 37 | Heap - Insert | Inserts a value in Max Binary Heap. | `heap_t *heap_insert(heap_t **root, int value)` |
| 38 | Heap - Array to Binary Heap | Converts an array to a Max Binary Heap. | `heap_t *array_to_heap(int *array, size_t size);` |
| 39 | Heap - Extract | Extracts the root node of a Max Binary Heap. | `int heap_extract(heap_t **root);` |
| 40 | Heap - Sort | Converts a Binary Max Heap to a sorted array of integers. | `int *heap_to_sorted_array(heap_t *heap, size_t *size);` |
| 41 | Big O #Binary Heap | Analyzes the average time complexities of operations on a Binary Heap. | N/A |

**Note:** The table above outlines the key tasks involved in this project, aimed at familiarizing oneself with binary trees' creation, manipulation, and traversal in C.

## Authors

- Yassine Mtejjal
