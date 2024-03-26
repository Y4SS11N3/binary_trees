#include "binary_trees.h"

/**
 * btlo_helper - helper function to execute func on each node at a given level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node's value
 * @level: level at which to apply func
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL || func == NULL)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_l = 1 + binary_tree_height(tree->left);
	if (tree->right)
		height_r = 1 + binary_tree_height(tree->right);

	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (level = 0; level <= height; level++)
		btlo_helper(tree, func, level);
}
