#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (binary_tree_is_bst(tree->left, min, tree->n) &&
			binary_tree_is_bst(tree->right, tree->n, max));
}

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);
	left_height = tree_height(tree->left) + 1;
	right_height = tree_height(tree->right) + 1;
	return ((left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (!tree)
		return (1); /* An empty tree is AVL */

	if (!binary_tree_is_bst(tree, INT_MIN, INT_MAX))
		return (0); /* Must be a BST */

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);
	balance_factor = left_height - right_height;

	if (abs(balance_factor) > 1)
		return (0); /* Balance factor check */

	/* Recursive check for left and right subtrees */
	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
