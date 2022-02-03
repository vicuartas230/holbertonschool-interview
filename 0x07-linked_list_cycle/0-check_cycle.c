#include "lists.h"

/**
 * check_cycle - This function checks if
 * a singly linked list has a cycle in it.
 * @list: The head of the list.
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */

int check_cycle(listint_t *list)
{
	listint_t *fast = list, *slow = list;

	if (!list)
		return (0);
	fast = fast->next->next;
	while (fast)
	{
		if (fast == slow)
		{
			return (1);
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return (0);
}
