#include "sort.h"

/**
 * swap - Swaps tow nodes in a doubly linked list.
 * @node1: First node to be swapped.
 * @node2: Second node to be swapped
 */
void swap(listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = npde1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the Insertion sort.
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *k;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	i = (*list)->next;
	while (i != NULL)
	{
		k = i;
		i = i->next;
		while (k != NULL && k->prev != NULL)
		{
			if (k->prev->n > k->n)
			{
				swap(k->prev, k);
				if (!k->prev)
					*list = k;
				print_list((const listint_t *)*list);
			}
			else
				k = k->prev;
		}
	}
}

