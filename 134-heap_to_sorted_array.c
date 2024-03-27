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

	return (left_size + right_size + 1);
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
	int *sorted_array;
	size_t i, actual_size;

	if (!heap || !size)
		return (NULL);

	*size = bnrtree_size(heap);
	sorted_array = malloc(sizeof(int) * (*size));
	if (!sorted_array)
		return (NULL);

	for (i = 0, actual_size = *size; i < actual_size; i++)
	{
		int extracted = heap_extract(&heap);

		if (extracted == 0 && i != actual_size - 1)
		{
			*size = i;
			break;
		}
		sorted_array[i] = extracted;
	}

	binary_tree_delete(heap);
	return (sorted_array);
}
