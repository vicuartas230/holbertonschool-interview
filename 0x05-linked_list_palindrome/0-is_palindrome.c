#include "lists.h"

/**
 * is_palindrome - This function checks if
 * a singly linked list is a palindrome.
 * @head: The start of the list.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */

int is_palindrome(listint_t **head)
{
	listint_t *aux = *head, *head2 = NULL, *aux2 = NULL;

	while (aux)
	{
		add_nodeint(&head2, aux->n);
		aux = aux->next;
	}
	aux2 = head2;
	while (aux)
	{
		if (aux->n != aux2->n)
		{
			free_listint(head2);
			return (0);
		}
	}
	free_listint(head2);
	return (1);
}

/**
 * add_nodeint - This function adds a new node at the start of a list.
 * @head: The start of the list.
 * @n: The value of the node.
 * Return: The new node.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new = NULL;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		new->next = *head;
		*head = new;
	}
	return (new);
}
