#include "binary_trees.h"

/**
 * swap_nodes - Swaps two nodes in the heap
 * @a: First node
 * @b: Second node
 */
void swap_nodes(heap_t *a, heap_t *b)
{
    int tmp = a->n;
    a->n = b->n;
    b->n = tmp;
}

/**
 * sift_down - Restores the heap property by sifting a node down the tree
 * @root: Pointer to the heap root
 */
void sift_down(heap_t *root)
{
    heap_t *largest = root;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left != NULL && left->n > largest->n)
        largest = left;
    if (right != NULL && right->n > largest->n)
        largest = right;
    
    if (largest != root)
    {
        swap_nodes(root, largest);
        sift_down(largest);
    }
}

/**
 * find_last_node - Finds the last node in the heap
 * @root: Pointer to the root of the heap
 * @size: Size of the heap
 * Return: Pointer to the last node
 */
heap_t *find_last_node(heap_t *root, size_t size)
{
    size_t path = size;
    int height = log2(size);
    heap_t *last = root;
    
    for (int i = height; i > 0; i--)
    {
        if (path & (1 << (i - 1)))
            last = last->right;
        else
            last = last->left;
    }
    
    return last;
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 * Return: Value stored in the root node
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return 0;
    
    int root_value = (*root)->n;
    size_t size = binary_tree_size(*root);
    
    if (size == 1)
    {
        free(*root);
        *root = NULL;
        return root_value;
    }
    
    heap_t *last = find_last_node(*root, size);
    (*root)->n = last->n;
    
    if (last->parent->left == last)
        last->parent->left = NULL;
    else
        last->parent->right = NULL;
    
    free(last);
    sift_down(*root);
    
    return root_value;
}
