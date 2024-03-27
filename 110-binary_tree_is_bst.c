#include "binary_trees.h"

/**
 * bst_helper - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the node that contains the minimum value allowed
 * @max: Pointer to the node that contains the maximum value allowed
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int bst_helper(const binary_tree_t *tree,
		const binary_tree_t *min, const binary_tree_t *max)
{
	if (!tree)
		return (1);

	if (min && tree->n <= min->n)
		return (0);

	if (max && tree->n >= max->n)
		return (0);

	return (bst_helper(tree->left, min, tree) &&
			bst_helper(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (bst_helper(tree, NULL, NULL));
}
