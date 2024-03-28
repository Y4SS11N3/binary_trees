#include "binary_trees.h"

/**
 * validate_node - Validates a node in a binary tree
 * @node: Node of the tree
 * @lower: Lower bound of checked nodes
 * @upper: Upper bound of checked nodes
 *
 * Return: 1 if valid node, 0 otherwise
 */
int validate_node(const binary_tree_t *node, int lower, int upper)
{
	if (node->n < lower || node->n > upper)
		return (0);

	return (1);
}

/**
 * check_bst - Validates a binary tree
 * @node: Root node of the tree
 * @lower: Lower bound of checked nodes
 * @upper: Upper bound of checked nodes
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int check_bst(const binary_tree_t *node, int lower, int upper)
{
	if (!node)
		return (1);

	if (!validate_node(node, lower, upper))
		return (0);

	return (check_bst(node->left, lower, node->n - 1) &&
		check_bst(node->right, node->n + 1, upper));
}

/**
 * binary_tree_is_bst - Validates a binary tree
 * @tree: Root node of the tree
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (check_bst(tree, INT_MIN, INT_MAX));
}
