#include "binary_trees.h"

/**
 * bnrtree_size - Measures the size of a binary tree using a specific approach
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: The size of the tree
 */
size_t bnrtree_size(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_size = 1 + bnrtree_size(tree->left);

	if (tree->right)
		right_size = 1 + bnrtree_size(tree->right);

	return (left_size + right_size);
}

/**
 * create_sorted_arr - Creates a sorted array from a Binary Max Heap
 * @heap: Pointer to the root node of the heap
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers
 */
int *create_sorted_arr(heap_t *heap, size_t *size)
{
	int idx, *sortedArr = NULL;

	if (!heap || !size)
		return (NULL);

	*size = bnrtree_size(heap) + 1;

	sortedArr = malloc(sizeof(int) * (*size));

	if (!sortedArr)
		return (NULL);

	for (idx = 0; heap; idx++)
		sortedArr[idx] = heap_extract(&heap);

	return (sortedArr);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	return (create_sorted_arr(heap, size));
}
