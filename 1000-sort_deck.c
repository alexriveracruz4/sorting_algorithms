#include "deck.h"
#include <string.h>
#include <stdlib.h>

/**
 * swap - swap joined nodes of a double linked list
 * @deck: doubly linked list
 * @node: node to swap
 *
 * Return: void
 */
void swap(deck_node_t **deck, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*deck = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * getValue - get the value of the card in number
 * @str: string value of card
 *
 * Return: value of card
 */
int getValue(const char *str)
{
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			   "10", "Jack", "Queen", "King"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, array[i]) == 0)
			return (i);
	}
	exit(1);
}

/**
 * sort_deck - function that sorts a deck of cards
 * @deck: deck to sort
 *
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	int c1, c2, flag = 1;
	deck_node_t *tmp;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	tmp = *deck;
	while (flag)
	{
		flag = 0;
		while (tmp->next)
		{
			c1 = getValue(tmp->card->value) + 13 * tmp->card->kind;
			c2 = getValue(tmp->next->card->value) +
				13 * tmp->next->card->kind;
			if (c1 > c2)
			{
				swap(deck, tmp);
				flag = 1;
			}
			else
				tmp = tmp->next;
		}
		if (flag == 0)
			break;
		flag = 0;
		while (tmp->prev != NULL)
		{
			c1 = getValue(tmp->card->value) + 13 * tmp->card->kind;
			c2 = getValue(tmp->prev->card->value) +
				13 * tmp->prev->card->kind;
			if (c1 < c2)
			{
				swap(deck, tmp->prev);
				flag = 1;
			}
			else
				tmp = tmp->prev;
		}
	}
}
