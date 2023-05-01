#include "lists.h"

/**
  * sum_listint - operates the sum of all the data in a listint_t list
  * @head: first node as a head in the linked list
  *
  * Return: the resulting sum
  */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}

