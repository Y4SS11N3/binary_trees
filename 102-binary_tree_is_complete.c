#include "binary_trees.h"

/**
 * get_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: The size of the tree
 */
size_t get_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_tree_size(tree->left) + get_tree_size(tree->right));
}

/**
 * check_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @size: Total number of nodes in the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int check_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);

	return (check_complete(tree->left, 2 * index + 1, size) &&
			check_complete(tree->right, 2 * index + 2, size) &&
			(tree->left || !tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size = get_tree_size(tree);

	return (check_complete(tree, 0, size));
}
