#include "lists.h"

/**
  * get_nodeint_at_index - returns the node at a certain index in a linked list
  * @head: first node at the head in linked list
  * @index: index of the node to be returning
  *
  * Return: pointer to the node we're looking for/NULL
  */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j = 0;
	listint_t *temp = head;

	while (temp && j < index)
	{
		temp = temp->next;
		j++;
	}

	return (temp ? temp : NULL);
}

