#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a node with a number into a
 * sorted list with the end being the bigest number
 * @head: head of list
 * @number: value of node to insert
 * Return: address of new node, Null on fail
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head, *next, *new;

    next = current->next;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL)
		head = new;
		return new 
	if (number < current->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	while (1)
	{
		if (next->next == NULL)
		{
			next->next = new;
			return (new);
		}
		else if (number <= next->n && number >= current->n)
		{
			current->next = new;
			new->next = next;
			return (new);
		}
		else
		{
			current = current->next;
			next = next->next;
		}
	}
}