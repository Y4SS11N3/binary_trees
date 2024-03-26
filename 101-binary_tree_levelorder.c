#include "binary_trees.h"

/**
 * enqueue - Adds a node to the queue
 * @head: pointer to the head of the queue
 * @node: pointer to the binary tree node to add to the queue
 */
static void enqueue(queue_t **head, const binary_tree_t *node)
{
	queue_t *new_node = malloc(sizeof(queue_t));
	queue_t *temp = *head;

	if (new_node == NULL)
		return;

	new_node->node = node;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

/**
 * dequeue - Removes a node from the queue
 * @head: pointer to the head of the queue
 * Return: pointer to the dequeued binary tree node
 */
static const binary_tree_t *dequeue(queue_t **head)
{
	if (head == NULL || *head == NULL)
		return (NULL);

	queue_t *temp = *head;
	const binary_tree_t *node = temp->node;
	*head = (*head)->next;

	free(temp);

	return (node);
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;

	if (tree == NULL || func == NULL)
		return;

	enqueue(&queue, tree);

	while (queue != NULL)
	{
		const binary_tree_t *current = dequeue(&queue);

		func(current->n);
		if (current->left != NULL)
			enqueue(&queue, current->left);
		if (current->right != NULL)
			enqueue(&queue, current->right);
	}
}
