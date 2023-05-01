#include "lists.h"

/**
  * find_listint_loop - finds the loop in linked list
  * @head: linked list to search for
  *
  * Return: the address of the node where the loop starts, or NULL
  */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fas = head;

	if (!head)
		return (NULL);

	while (slow && fas && fas->next)
	{
		fas = fas->next->next;
		slow = slow->next;
		if (fas == slow)
		{
			slow = head;
			while (slow != fas)
			{
				slow = slow->next;
				fas = fas->next;
			}
			return (fas);
		}
	}

	return (NULL);
}

