#include "lists.h"

/**
  * pop_listint - pops the head node of a linked list
  * @head: pointer to the first element in the linked list
  *
  * Return: the data inside the elements deleted/0 if the list is empty
  */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num0;

	if (!head || !*head)
		return (0);

	num0 = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (num0);
}

