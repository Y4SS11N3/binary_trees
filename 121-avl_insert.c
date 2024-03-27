#include "binary_trees.h"

/**
 * rebalance_node - Rebalances an AVL tree node
 * @node: Double pointer to the node to rebalance
 * @value: The value inserted that might cause imbalance
 */
static void rebalance_node(avl_t **node, int value)
{
	int balance;

	balance = binary_tree_balance(*node);

	if (balance > 1)
	{
		if (value > (*node)->left->n)
		{
			(*node)->left = binary_tree_rotate_left((*node)->left);
		}
		*node = binary_tree_rotate_right(*node);
	}
	else if (balance < -1)
	{
		if (value < (*node)->right->n)
		{
			(*node)->right = binary_tree_rotate_right((*node)->right);
		}
		*node = binary_tree_rotate_left(*node);
	}
}

/**
 * insert_and_rebalance - Inserts a value in an AVL tree and rebalances it
 * @tree: Double pointer to the root node of the tree to insert the value
 * @value: The value to store in the node to be inserted
 * @parent: Pointer to the parent node of the current node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
static avl_t *insert_and_rebalance(avl_t **tree, int value, avl_t *parent)
{
	avl_t *inserted_node = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(parent, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		inserted_node = insert_and_rebalance(&((*tree)->left), value, *tree);
	}
	else if (value > (*tree)->n)
	{
		inserted_node = insert_and_rebalance(&((*tree)->right), value, *tree);
	}

	rebalance_node(tree, value);
	return (inserted_node);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of
 * the AVL tree for inserting the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
	{
		return (NULL);
	}

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (insert_and_rebalance(tree, value, NULL));
}
