#include "binary_trees.h"

/**
 * measure_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t measure_height(const heap_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + measure_height(tree->left);

	if (tree->right)
		height_right = 1 + measure_height(tree->right);

	if (height_left > height_right)
		return (height_left);
	return (height_right);
}

/**
 * measure_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t measure_size(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + measure_size(tree->left);

	if (tree->right)
		height_right = 1 + measure_size(tree->right);

	return (height_left + height_right);
}

/**
 * traverse_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 *
 * Return: No Return
 */
void traverse_preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	traverse_preorder(tree->left, node, height);
	traverse_preorder(tree->right, node, height);
}

/**
 * max_heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void max_heapify(heap_t *root)
{
	int temp_value;
	heap_t *temp1, *temp2;

	if (!root)
		return;

	temp1 = root;

	while (1)
	{
		if (!temp1->left)
			break;
		if (!temp1->right)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		temp_value = temp1->n;
		temp1->n = temp2->n;
		temp2->n = temp_value;
		temp1 = temp2;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of heap
 *
 * Return: the value stored in the root node
 *         0 on failure
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *heap_root, *node;

	if (!root || !*root)
		return (0);
	heap_root = *root;
	extracted_value = heap_root->n;
	if (!heap_root->left && !heap_root->right)
	{
		*root = NULL;
		free(heap_root);
		return (extracted_value);
	}

	traverse_preorder(heap_root, &node, measure_height(heap_root));

	heap_root->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	max_heapify(heap_root);
	*root = heap_root;
	return (extracted_value);
}
