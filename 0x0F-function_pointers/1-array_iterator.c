#include <stdio.h>
#include "function_pointers.h"

/**
  * array_iterator - perfom an action on each element of an array
  * @array: array elements -> action.
  * @size: size of an array.
  * @action: function to run.
  * Return: void.
  */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}

}
