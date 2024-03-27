#include "binary_trees.h"

/**
 * bst_util - Checks if a binary tree is a valid AVL
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value
 * @max: Maximum value
 * Return: 1 if tree is a valid AVL, and 0 otherwise
 */
int bst_util(const binary_tree_t *tree, int min, int max)
{
	int height_l, height_r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	height_l = tree->left ? 1 + tree_depth_measure(tree->left) : 0;
	height_r = tree->right ? 1 + tree_depth_measure(tree->right) : 0;

	if (abs(height_l - height_r) > 1)
		return (0);

	return (bst_util(tree->left, min, tree->n - 1) &&
		bst_util(tree->right, tree->n + 1, max));
}

/**
 * tree_depth_measure - Measures the depth of a binary tree
 * @node: Pointer to the node to measure the depth from
 * Return: The depth of the tree
 */
size_t tree_depth_measure(const binary_tree_t *node)
{
	size_t left_depth = 0, right_depth = 0;

	if (!node)
		return (0);

	left_depth = node->left ? 1 + tree_depth_measure(node->left) : 0;
	right_depth = node->right ? 1 + tree_depth_measure(node->right) : 0;
	return (left_depth > right_depth ? left_depth : right_depth);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bst_util(tree, INT_MIN, INT_MAX));
}
