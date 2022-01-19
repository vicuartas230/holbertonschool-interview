#include "lists.h"

/**
 * is_palindrome - This function checks if
 * a singly linked list is a palindrome.
 * @head: The start of the list.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */

int is_palindrome(listint_t **head)
{
	int *values = NULL, size = 0, i = 0, j = 0;

	size = check_size(*head);
	values = check_list(*head, size);
	j = size - 1;
	while (i < size)
	{
		if (values[i] != values[j])
			return (0);
		i++, j--;
	}
	return (1);
}

/**
 * check_list - This function fill array with values of the list.
 * @head: The start of the list.
 * @size: The lenght of the list.
 * Return: An array with values of the list.
 */

int *check_list(listint_t *head, int size)
{
	listint_t *aux = head;
	int *values = NULL, i = 0;

	values = malloc(size * sizeof(int));
	if (!values)
		return (NULL);
	while (aux)
	{
		values[i] = aux->n;
		aux = aux->next;
		i++;
	}
	return (values);
}

/**
 * check_size - This function returns the length of the list.
 * @head: The start of the list.
 * Return: The number of nodes that list has.
 */

int check_size(listint_t *head)
{
	listint_t *aux = head;
	int counter = 0;

	while (aux)
	{
		counter++;
		aux = aux->next;
	}
	return (counter);
}
