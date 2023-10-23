#include <stdio.h>
#include "sort.h"


void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *current, *index, *temp;
	int swap;

	if (!(*list))
		return;

	index = (*list)->next;
	while (index)
	{
		iterator = index;
		current = iterator->prev;
		swap = 0;
		if (!(current->n < iterator->n))
			while (current)
			{
				if (current->n < iterator->n)
				{
					swap = 1;
					break;
				}
				current = current->prev;
				if (!current)
					swap = 2;
			}
		if (swap == 1)
		{
			temp = iterator->prev, temp->next = iterator->next, temp->next->prev = temp;
			iterator->next = current->next, iterator->next->prev = iterator;
			current->next = iterator, iterator->prev = current;
			print_list(*list);
		}
		else if (swap == 2)
		{
			temp = iterator->prev;
			if (iterator->next)
				temp->next = iterator->next, temp->next->prev = temp;
			else
				temp->next = NULL;
			iterator->next = *list, iterator->prev = NULL;
			(*list)->prev = iterator, (*list) = iterator;
			print_list(*list);
		}
		index = index->next;
	}
}
