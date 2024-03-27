#include "binary_trees.h"

/**
 * heap_check - Helper to verify Max Binary Heap properties.
 * @node: Pointer to the current node being checked.
 *
 * Return: 1 if subtree rooted at node is a valid Max Binary Heap, 0 otherwise.
 */
int heap_check(const binary_tree_t *node)
{
	if (!node)
		return (1);

	if (node->left && node->left->n > node->n)
		return (0);
	if (node->right && node->right->n > node->n)
		return (0);

	return (heap_check(node->left) && heap_check(node->right));
}

/**
 * is_max_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @root: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *root)
{
	if (!root)
		return (0);

	size_t node_count = count_nodes(root);
	return (tree_is_complete(root, 0, node_count) && heap_check(root));
}

/**
 * tree_is_complete - Verifies if a binary tree is complete.
 * @node: Pointer to the current node.
 * @index: Index of the current node.
 * @nodes: Total number of nodes in the tree.
 *
 * Return: 1 if tree is complete, 0 otherwise.
 */
int tree_is_complete(const binary_tree_t *node, size_t index, size_t nodes)
{
	if (!node)
		return (1);

	if (index >= nodes)
		return (0);

	return (tree_is_complete(node->left, 2 * index + 1, nodes) &&
			tree_is_complete(node->right, 2 * index + 2, nodes));
}

/**
 * count_nodes - Counts the total number of nodes in a binary tree.
 * @node: Pointer to the root node of the tree.
 *
 * Return: Number of nodes in the tree.
 */
size_t count_nodes(const binary_tree_t *node)
{
	if (!node)
		return (0);

	return 1 + count_nodes(node->left) + count_nodes(node->right);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return is_max_heap(tree);
}
