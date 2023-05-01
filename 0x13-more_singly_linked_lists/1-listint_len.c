#include "lists.h"

/**
  * listint_len - return the number of elements in a linked lists
  * @h: linked list of type listint_t to reverse like
  *
  * Return: the number of nodes
  */
size_t listint_len(const listint_t *h)
{
	size_t num0 = 0;

	while (h)
	{
		num0++;
		h = h->next;
	}

	return (num0);
}

