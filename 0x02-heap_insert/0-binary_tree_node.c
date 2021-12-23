#include "binary_trees.h"

/**
 * binary_tree_node - This function creates a binary tree node.
 * @parent: The first node of the tree.
 * @value: The integer inside the node.
 * Return: A pointer to the new node, or NULL on failure.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
