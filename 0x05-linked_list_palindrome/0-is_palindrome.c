#include "lists.h"


/**
 * list_len - returns the lenght of a list
 * @h: list to get lenght of.
 * Return: the size of the list
 */

size_t list_len(const listint_t *h)
{
	size_t i;

	if (h == NULL)
		return (0);
	for (i = 1; h->next != NULL; i++)
		h = h->next;
	return (i);
}


/**
 * is_palindrome - checks if a list is a palindrome
 * @head: head of list
 * Return: 1 if palindrome or empty, else 0
 */

int is_palindrome(listint_t **head)
{
	size_t len, i, j;
	listint_t *start = *head;
	int *nlist;

	len = list_len(start);

	if (len == 0 || len == 1 || !head || !start)
		return (1);
	nlist = malloc(sizeof(size_t) * len);

	for (i = 0; i < len; i++, start = start->next)
		nlist[i] = start->n;

	for (i = 0, j = (len - 1); i < j; i++, j--)
		if (nlist[i] != nlist[j])
		{
			free(nlist);
			return (0);
		}

	free(nlist);
	return (1);
}
