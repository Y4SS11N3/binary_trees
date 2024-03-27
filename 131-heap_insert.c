#include "binary_trees.h"

/**
 * find_insert_pos - Finds the position to insert a new node in the heap
 * @root: Double pointer to the root of the heap
 *
 * Return: Pointer to the node where the new node should be inserted
 */
binary_tree_t *find_insert_pos(heap_t **root)
{
	heap_t *temp;
	int size, leaves, bit, level;

	if (!root || !(*root))
		return (NULL);

	temp = *root;
	size = binary_tree_size(temp);
	leaves = size;

	for (level = 0, bit = 1; leaves >= bit; bit *= 2, level++)
		leaves -= bit;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		temp = leaves & bit ? temp->right : temp->left;

	return (temp);
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *insert_pos;

	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	insert_pos = find_insert_pos(root);
	if (!insert_pos)
		return (NULL);

	new_node = binary_tree_node(insert_pos, value);
	if (!new_node)
		return (NULL);

	if (insert_pos->left == NULL)
		insert_pos->left = new_node;
	else
		insert_pos->right = new_node;

	while (new_node->parent && (new_node->n > new_node->parent->n))
	{
		int tmp = new_node->n;

		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 * 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
