#include "binary_trees.h"

/**
 * min_node - Finds the minimum node in a subtree.
 * @node: Starting node to search for the min value.
 * Return: Minimum value node or NULL if tree is empty.
 */
int min_node(bst_t *node)
{
        int minVal = 0; /* Minimum value found */

        if (!node)
        {
                return (0);
        }
        minVal = min_node(node->left);
        return ((minVal == 0) ? node->n : minVal);
}

/**
 * replace_node - Replaces a node with its in-order successor.
 * @node: Node to replace, having two children.
 * Return: Value of successor for replacement.
 */
int replace_node(bst_t *node)
{
        int succVal = 0; /* Successor value */

        succVal = min_node(node->right);
        node->n = succVal;
        return (succVal);
}

/**
 * node_remove - Handles removal of a node based on child presence.
 * @node: Node to evaluate and remove accordingly.
 * Return: 0 if leaf, successor value if two children, -1 otherwise.
 */
int node_remove(bst_t *node)
{
        if (!node->left && !node->right) /* Leaf node */
        {
                if (node->parent->right == node)
                        node->parent->right = NULL;
                else
                        node->parent->left = NULL;
                free(node);
                return (0);
        }
        else if ((!node->left) != (!node->right)) /* Single child */
        {
                bst_t *child = node->left ? node->left : node->right; /* Child node */

                if (node->parent->right == node)
                        node->parent->right = child;
                else
                        node->parent->left = child;
                child->parent = node->parent;
                free(node);
                return (0);
        }
        else /* Two children */
        {
                return (replace_node(node));
        }
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Root node of the BST.
 * @value: Value to find and remove from the BST.
 * Return: New root node of the BST after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
        int nodeStatus = 0; /* Status after node removal attempt */

        if (!root)
                return (NULL);
        if (value < root->n)
                bst_remove(root->left, value);
        else if (value > root->n)
                bst_remove(root->right, value);
        else /* Found node to remove */
        {
                nodeStatus = node_remove(root);
                if (nodeStatus != 0)
                        bst_remove(root->right, nodeStatus);
        }
        return (root);
}
