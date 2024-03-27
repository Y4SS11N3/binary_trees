#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	size_t left_height = tree_height(tree->left);
	size_t right_height = tree_height(tree->right);
	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @number_nodes: Total number of nodes in the tree
 * Return: 1 if complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t number_nodes)
{
	if (tree == NULL)
		return (1);
	if (index >= number_nodes)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, number_nodes) &&
		is_complete(tree->right, 2 * index + 2, number_nodes));
}

/**
 * is_heap - Checks if a binary tree is a max heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a max heap, 0 otherwise
 */
int is_heap(const binary_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->right == NULL)
		return (tree->n >= tree->left->n);
	else
	{
		if (tree->n >= tree->left->n && tree->n >= tree->right->n)
			return (is_heap(tree->left) && is_heap(tree->right));
		else
			return (0);
	}
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	size_t height = tree_height(tree);
	size_t number_nodes = (1 << height) - 1; // 2^height - 1
	return (is_complete(tree, 0, number_nodes) && is_heap(tree));
}
