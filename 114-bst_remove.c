#include "binary_trees.h"

/**
 * binary_tree_min - Finds the minimum value in a binary search tree
 * @tree: Pointer to the root of the tree to search
 * Return: Pointer to the node containing the minimum value
 */
bst_t *binary_tree_min(bst_t *tree)
{
	while (tree && tree->left != NULL)
		tree = tree->left;
	return (tree);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	/* Node is found, perform removal */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Node with only one child or no child */
		if (root->left == NULL)
		{
			bst_t *temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;
			free(root);
			return (temp);
		}

		/* Node with two children: Get the inorder successor */
		bst_t *temp = binary_tree_min(root->right);

		/* Copy the inorder successor's content to this node */
		root->n = temp->n;

		/* Delete the inorder successor */
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
