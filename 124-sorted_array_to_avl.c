#include "binary_trees.h"

/**
 * insert_into_avl - Helper function to insert nodes into an AVL tree
 * from a sorted array segment.
 * @array: Pointer to the first element of the array to be converted.
 * @start: Starting index of the segment.
 * @end: Ending index of the segment.
 * @parent: Pointer to the parent node.
 *
 * Return: Pointer to the root node of
 * the created AVL tree segment, or NULL on failure.
 */
avl_t *insert_into_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = insert_into_avl(array, start, mid - 1, root);
	root->right = insert_into_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: Pointer to the root node of
 * the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (insert_into_avl(array, 0, size - 1, NULL));
}
