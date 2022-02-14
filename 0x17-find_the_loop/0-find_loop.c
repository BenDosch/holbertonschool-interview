#include "lists.h"
#include <stdio.h>

/**
* find_listint_loop - finds the loop in a linked list
*
* @head: pointer to the head of the list
*
* Return: the node at the beginigng of the loop starts, or NULL if no loop
* exists.
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head, *hare = head;

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (tortoise);
		}
	}
	return (NULL);
}
