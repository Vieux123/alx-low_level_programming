#include "lists.h"

/**
  * free_listint_safe - frees a linked list
  * @he: pointer to the first node in the linked list
  *
  * Return: the size of the list to be freed
  */
size_t free_listint_safe(listint_t **he)
{
	size_t len = 0;
	int diffe;
	listint_t *temp;

	if (!he || !*he)
		return (0);

	while (*he)
	{
		diffe = *he - (*he)->next;
		if (diffe > 0)
		{
			temp = (*he)->next;
			free(*he);
			*he = temp;
			len++;
		}
		else
		{
			free(*he);
			*he = NULL;
			len++;
			break;
		}
	}

	*he = NULL;

	return (len);
}

