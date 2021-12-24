#include "binary_trees.h"

/**
 * heap_insert - This function inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the inserted node, or NULL on failure.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = NULL;

	node = binary_tree_node(*root, value);
	if (!*root)
		*root = node;
	else if (node->n > (*root)->n)
	{
		*root = node;
		binary_tree_node((*root)->left, value);
	}
	return (node);
}
