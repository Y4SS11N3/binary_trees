#include "binary_trees.h"

/**
 * binary_tree_min - Finds the minimum value in a binary search tree
 * @tree: Pointer to the root of the tree to search
 * Return: Pointer to the node containing the minimum value
 */
bst_t *binary_tree_min(bst_t *tree)
{
	bst_t *current = tree;

	while (current && current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 * Return: Pointer to the new root node of
 * the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Node to be removed is found */
		if (root->left == NULL)
		{
			/* Node has no left child */
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			/* Node has no right child */
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		/* Node has two children */
		bst_t *temp = binary_tree_min(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
