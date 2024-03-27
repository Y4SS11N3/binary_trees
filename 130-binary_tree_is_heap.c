#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Root node pointer.
 * Return: 1 if valid Max Heap, 0 otherwise or if NULL.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_heap_helper(tree));
}

/**
 * is_heap_helper - Recursive helper for checking Max Binary Heap.
 * @tree: Node pointer.
 * Return: 1 if valid Max Heap, 0 otherwise or if NULL.
 */
int is_heap_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (is_heap_helper(tree->left) && is_heap_helper(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Root node pointer.
 * Return: 1 if complete, 0 otherwise or if NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	return (is_complete_helper(tree, 0, size));
}

/**
 * is_complete_helper - Recursive helper for checking complete binary tree.
 * @tree: Node pointer.
 * @index: Current node index.
 * @size: Total number of nodes.
 * Return: 1 if complete, 0 otherwise or if NULL.
 */
int is_complete_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete_helper(tree->left, 2 * index + 1, size) &&
			is_complete_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Root node pointer.
 * Return: Size of the tree or 0 if NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
