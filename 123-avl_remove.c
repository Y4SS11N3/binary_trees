#include "binary_trees.h"

/**
 * find_inorder_successor - Finds the in-order
 * successor of a node in an AVL tree
 * @node: Pointer to the node to find the in-order successor for
 *
 * Return: Pointer to the in-order successor node
 */
static avl_t *find_inorder_successor(avl_t *node)
{
	avl_t *current = node->right;

	while (current && current->left != NULL)
		current = current->left;
	return (current);
}

/**
 * remove_node - Handles the removal of a node in an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: The value to remove from the tree
 *
 * Return: Pointer to the new root node after removal
 */
static avl_t *remove_node(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
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
			avl_t *temp = find_inorder_successor(root);

			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}
	return (root);
}

/**
 * rebalance_avl - Rebalances an AVL tree after a node has been removed
 * @root: Pointer to the root node of the tree to rebalance
 *
 * Return: Pointer to the new root node after rebalancing
 */
static avl_t *rebalance_avl(avl_t *root)
{
	int balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of
 * the tree after removing the desired value and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	root = remove_node(root, value);
	if (root == NULL)
		return (NULL);

	return (rebalance_avl(root));
}
