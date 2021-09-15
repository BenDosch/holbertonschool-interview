#include "lists.h"

/**
 * check_cycle - 
 * @list: pointer to head of list.
 * 
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */

int check_cycle(listint_t *list)
{   
    int i = 0;
    listint_t *slow = list, *fast = list;

    for (; fast != NULL; i++) {
        if(i % 2 == 1)
            slow = slow->next;
        fast = fast->next;
        if (slow == fast) {return(1);}
    }
    return(0);
}
