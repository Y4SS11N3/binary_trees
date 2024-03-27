#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure or if value exists
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = NULL;
	bst_t *parent = NULL;
	bst_t *current;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	current = *tree;
	while (current)
	{
		parent = current;
		if (value < current->n) /* Move left */
		{
			current = current->left;
			if (!current)
			{
				node = binary_tree_node(parent, value);
				parent->left = node;
				return (node);
			}
		}
		else if (value > current->n) /* Move right */
		{
			current = current->right;
			if (!current)
			{
				node = binary_tree_node(parent, value);
				parent->right = node;
				return (node);
			}
		}
		else
			return (NULL);
	}
	return (NULL);
}
