#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list in ascending order using
 * the insertion sort algorithm
 * @list: head node to the list to sort
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *current, *index;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	index = (*list)->next;
	while (index)
	{
		iterator = index;
		current = iterator->prev;
		swapped = 0;
		while (current->n > iterator->n)
		{
			if (current == *list)
			{
				current->next = iterator->next;
				if (iterator->next)
					current->next->prev = current;
				iterator->next = (*list);
				(*list)->prev = iterator;
				(*list) = iterator;
				print_list(*list);
				break;
			}
			else
				swap_nodes(current, iterator, list);
			current = current->prev;
			swapped = 1;
		}
		if (!swapped)
			index = index->next;
	}
}

/**
 * swap - swaps positions for two nodes in a doubly linked list
 * @left: node to swap
 * @right: node to swap
 * @list: pointer to a pointer to the head node of the list
*/

void swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
	listint_t *temp1, *temp2;

	temp1 = left->prev;
	temp2 = right->next;
	left->next = temp2;
	left->prev = right;
	temp1->next = right;
	if (temp2)
		temp2->prev = left;
	right->prev = temp1;
	right->next = left;
	print_list(*list);
}
