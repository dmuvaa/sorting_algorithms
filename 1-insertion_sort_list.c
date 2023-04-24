#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * using insertion algorithm
 * @list: doubly linked list of integers
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;
	while (current != NULL)
	{
		listint_t *prev = current->prev, *next = current->next;
		while (prev != NULL && prev->n > current->n)
		{
			prev->next = next;
			if (next != NULL)
				next->prev = prev;
			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			prev = current->prev;
			print_list(*list);
		}
		current = next;
	}
}
