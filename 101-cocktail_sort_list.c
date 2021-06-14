#include "sort.h"
#include<stdbool.h>

/**
 * swap - swap between nodes
 * @list: list
 * @node: node to be swapped
 *
 * Return: void
 */
void swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list to be sorted
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped = true;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	tmp = *list;
	while (swapped)
	{
		swapped = false;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap(list, tmp);
				swapped = true;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (swapped == false)
			break;
		swapped = false;
		while (tmp->prev)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap(list, tmp->prev);
				swapped = true;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
