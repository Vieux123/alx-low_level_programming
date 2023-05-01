#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
  * looped_listint_len - Counts the number of unique nodes
  * @head: A pointer to the head of the listint_t to check.
  *
  * Return: list that is not looped 0.
  * the number of unique nodes in the list.
  */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *torto, *har;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	torto = head->next;
	har = (head->next)->next;

	while (har)
	{
		if (torto == har)
		{
			torto = head;
			while (torto != har)
			{
				nodes++;
				torto = torto->next;
				har = har->next;
			}

			torto = torto->next;
			while (torto != har)
			{
				nodes++;
				torto = torto->next;
			}

			return (nodes);
		}

		torto = torto->next;
		har = (har->next)->next;
	}

	return (0);
}

/**
  * print_listint_safe - Prints a listint_t list safely.
  * @head: A pointer to the head of the listint_t list.
  *
  * Return: the number of nodes in the list.
  */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}

