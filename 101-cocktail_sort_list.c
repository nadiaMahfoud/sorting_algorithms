#include "sort.h"

/**
 * swap - to swap the nodes themselves.
 * @current: pointer.
 * @current_old: pointer.
 * @list: doubly linked list
 */
void swap(listint_t *current, listint_t *current_old, listint_t **list)
{
	listint_t *tmp1 = current->next;
	listint_t *tmp2 = current_old->prev;

	if (tmp1 != NULL)
		tmp1->prev = current_old;
	if (tmp2 != NULL)
		tmp2->next = current;
	current->prev = tmp2;
	current_old->next = tmp1;
	current->next = current_old;
	current_old->prev = current;
	if (*list == current_old)
		*list = current;
	print_list(*list);
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: head of list to be sortered (Double Linked List)
 *
 * Return: No Return
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list, *first = NULL, *last = NULL;

	if (!list)
		return;
	if (!(*list))
		return;
	if (!(*list)->next)
		return;
	do {
		while (check->next)
		{
			if (check->n > check->next->n)
				swap(check->next, check, list);
			else
				check = check->next;
		}
		last = check;
		while (check->prev != first)
		{
			if (check->n < check->prev->n)
				swap(check, check->prev, list);
			else
				check = check->prev;
		}
		first = check;
	} while (first != last);
}
