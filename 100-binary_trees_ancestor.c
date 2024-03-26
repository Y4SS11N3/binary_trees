#include "binary_trees.h"

/**
 * depth - Measures the depth of a node in a binary tree
 * @node: pointer to the node to measure the depth
 *
 * Return: the depth of the node
 */
static size_t depth(const binary_tree_t *node)
{
	size_t d = 0;

	while (node)
	{
		d++;
		node = node->parent;
	}
	return (d);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	depth_first = depth(first);
	depth_second = depth(second);

	/* Align the nodes at the same depth */
	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	/* Find the common ancestor */
	while (first && second && first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *)first);
}
