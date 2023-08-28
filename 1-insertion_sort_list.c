#include "sort.h"

/**
 * swap_nodes - to Swap 2 nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @nd1: A pointer to the first node to swap.
 * @nd2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **nd1, listint_t *nd2)
{
	(*nd1)->next = nd2->next;
	if (nd2->next != NULL)
		nd2->next->prev = *nd1;
	nd2->prev = (*nd1)->prev;
	nd2->next = *nd1;
	if ((*nd1)->prev != NULL)
		(*nd1)->prev->next = nd2;
	else
		*h = nd2;
	(*nd1)->prev = nd2;
	*nd1 = nd2->prev;
}

/**
 * insertion_sort_list - to sort a DLL of integers in
 * ascending order using the insertion sort
 * algorithm
 *
 * @list: doubly linked list
 * Return: no return
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insert = current->prev;
		while (insert != NULL && current->n < insert->n)
		{
			swap_nodes(list, &insert, current);
			print_list((const listint_t *)*list);
		}
	}
}
