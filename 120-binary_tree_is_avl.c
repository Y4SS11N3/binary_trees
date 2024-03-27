#include "binary_trees.h"

/**
 * bst_util - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value
 * @max: Maximum value
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int bst_util(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);
    if (tree->n < min || tree->n > max)
        return (0);
    return (bst_util(tree->left, min, tree->n - 1) &&
            bst_util(tree->right, tree->n + 1, max));
}

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
int height(const binary_tree_t *tree)
{
    int height_l, height_r;

    if (tree == NULL)
        return (0);
    height_l = height(tree->left);
    height_r = height(tree->right);
    return ((height_l > height_r ? height_l : height_r) + 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int balance;

    if (tree == NULL)
        return (0);
    if (!bst_util(tree, INT_MIN, INT_MAX))
        return (0);
    balance = height(tree->left) - height(tree->right);
    if (abs(balance) > 1)
        return (0);
    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);
    return (1);
}

