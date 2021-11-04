#include "search.h"

/**
* linear_list - function that searches for a value in a
* sorted list of integers using the Linear search algorithm.
*
* @start: Pointer to the starting node of the sorted linked list that
* is the subject of search
* @end: Ending node for search
* @value: Value to find
*
* Return: On sucess, pointer to the first node containing value
* On failure, NULL.
*/

skiplist_t *linear_list(skiplist_t *start, skiplist_t *end, int value)
{
	skiplist_t *curr = start;

	if (curr != NULL)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
				   start->index, end->index);
		for (; curr->next != NULL && curr != end; curr = curr->next)
		{
			printf("Value checked at index [%lu] = [%d]\n",
			   curr->index, curr->n);
			if (curr->n == value)
				return (curr);
		}
		printf("Value checked at index [%lu] = [%d]\n",
			   curr->index, curr->n);
		if (curr->n == value)
			return (curr);
	}
	return (NULL);
}

/**
* linear_skip - Function that searches for a
* value in a sorted skip list of integers
*
* @list: Pointer to the sorted linked list that is the subject of search
* @value: Value to find
*
* Return: On sucess, pointer to the first node containing value
* On failure, NULL.
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr = list, *last;

	while (curr != NULL)
	{
	    printf("Value checked at index [%lu] = [%d]\n",
			curr->index, curr->n);
		if (curr->n == value)
			return (curr);
		else if (curr->express != NULL && curr->express->n > value)
			return (linear_list(curr, curr->express, value));
		else if (curr->express == NULL)
		{
			for (last = curr; last->next != NULL; last = last->next)
				continue;
			return (linear_list(curr, last, value));
		}
		curr = curr->express;
	}
	return (NULL);
}
