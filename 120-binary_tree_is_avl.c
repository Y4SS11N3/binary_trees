#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * @height: Pointer to store the height of the tree
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, size_t *height)
{
    size_t left_height = 0, right_height = 0;
    int is_left_avl = 1, is_right_avl = 1;

    if (tree == NULL)
    {
        *height = 0;
        return (1);
    }

    is_left_avl = is_avl_helper(tree->left, &left_height);
    is_right_avl = is_avl_helper(tree->right, &right_height);

    *height = 1 + (left_height > right_height ? left_height : right_height);

    if (abs((int)left_height - (int)right_height) > 1)
        return (0);

    return (is_left_avl && is_right_avl);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    size_t height = 0;

    if (tree == NULL)
        return (0);

    return is_avl_helper(tree, &height);
}
