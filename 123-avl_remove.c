#include "binary_trees.h"

/**
 * find_min_value - Finds the minimum value node in a subtree.
 * @node: The root node of the subtree.
 *
 * Return: The minimum value node.
 */
static avl_t *find_min_value(avl_t *node)
{
    avl_t *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/**
 * remove_and_rebalance - Removes a node and rebalances the AVL tree.
 * @root: The root of the AVL tree.
 * @value: The value to remove.
 *
 * Return: The new root after removal and rebalancing.
 */
static avl_t *remove_and_rebalance(avl_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = remove_and_rebalance(root->left, value);
    else if (value > root->n)
        root->right = remove_and_rebalance(root->right, value);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            avl_t *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            avl_t *temp = find_min_value(root->right);
            root->n = temp->n;
            root->right = remove_and_rebalance(root->right, temp->n);
        }
    }

    if (root == NULL)
        return root;

    rebalance_avl(&root);
    return root;
}

/**
 * avl_remove - Wrapper function for removing a node from an AVL tree.
 * @root: The root of the AVL tree.
 * @value: The value to remove.
 *
 * Return: The new root after removal and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
    return remove_and_rebalance(root, value);
}

/**
 * rebalance_avl - Rebalances an AVL tree at a given node.
 * @tree: The node to rebalance from.
 */
void rebalance_avl(avl_t **tree)
{
    int balance;
    avl_t *root = *tree;

    if (root == NULL)
        return;

    balance = binary_tree_balance(root);
    if (balance > 1)
    {
        if (binary_tree_balance(root->left) < 0)
            root->left = binary_tree_rotate_left(root->left);
        *tree = binary_tree_rotate_right(root);
    }
    else if (balance < -1)
    {
        if (binary_tree_balance(root->right) > 0)
            root->right = binary_tree_rotate_right(root->right);
        *tree = binary_tree_rotate_left(root);
    }
}
