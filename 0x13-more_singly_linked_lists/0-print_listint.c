#include "lists.h"

/**
  * print_listint - print the elements of linked list
  * @h: linked list of type listint_t for printing
  *
  * Return: the number of nodes
  */
size_t print_listint(const listint_t *h)
{
	size_t num0 = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num0++;
		h = h->next;
	}

	return (num0);
}
