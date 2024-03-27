#include "binary_trees.h"

/**
 * adjust_balance - Adjusts the balance of an AVL tree.
 * @tree_ref: A double pointer to the root node of the tree to adjust.
 */
void adjust_balance(avl_t **tree_ref)
{
	int balance_factor;

	if (tree_ref == NULL || *tree_ref == NULL)
		return;
	if ((*tree_ref)->left == NULL && (*tree_ref)->right == NULL)
		return;
	adjust_balance(&(*tree_ref)->left);
	adjust_balance(&(*tree_ref)->right);
	balance_factor = binary_tree_balance((const binary_tree_t *)*tree_ref);
	if (balance_factor > 1)
		*tree_ref = binary_tree_rotate_right((binary_tree_t *)*tree_ref);
	else if (balance_factor < -1)
		*tree_ref = binary_tree_rotate_left((binary_tree_t *)*tree_ref);
}

/**
 * find_successor - Finds the successor of a node in an AVL tree.
 * @node_check: A pointer to the tree node to find the successor for.
 * Return: The smallest node value in the right subtree.
 */
int find_successor(bst_t *node_check)
{
	int left_min = 0;

	if (node_check == NULL)
	{
		return (0);
	}
	else
	{
		left_min = find_successor(node_check->left);
		if (left_min == 0)
		{
			return (node_check->n);
		}
		return (left_min);
	}
}

/**
 * node_removal_logic - Determines the node removal
 * process based on its children.
 * @node_target: The node to remove.
 * Return: 0 if no children, or the new node value if it has children.
 */
int node_removal_logic(bst_t *node_target)
{
	int value_replace = 0;

	if (!node_target->left && !node_target->right)
	{
		if (node_target->parent->right == node_target)
			node_target->parent->right = NULL;
		else
			node_target->parent->left = NULL;
		free(node_target);
		return (0);
	}
	else if ((!node_target->left && node_target->right) ||
			(!node_target->right && node_target->left))
	{
		if (!node_target->left)
		{
			if (node_target->parent->right == node_target)
				node_target->parent->right = node_target->right;
			else
				node_target->parent->left = node_target->right;
			node_target->right->parent = node_target->parent;
		}
		if (!node_target->right)
		{
			if (node_target->parent->right == node_target)
				node_target->parent->right = node_target->left;
			else
				node_target->parent->left = node_target->left;
			node_target->left->parent = node_target->parent;
		}
		free(node_target);
		return (0);
	}
	else
	{
		value_replace = find_successor(node_target->right);
		node_target->n = value_replace;
		return (value_replace);
	}
}

/**
 * bst_remove - Removes a node from a BST.
 * @root: The root of the tree.
 * @value: The node value to remove.
 * Return: The modified tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int operation_result = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		operation_result = node_removal_logic(root);
		if (operation_result != 0)
			bst_remove(root->right, operation_result);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree and rebalances it.
 * @root: The root of the tree.
 * @value: The value to remove from the tree.
 * Return: The new root of the balanced AVL tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root = (avl_t *)bst_remove((bst_t *)root, value);

	if (new_root == NULL)
		return (NULL);
	adjust_balance(&new_root);
	return (new_root);
}
