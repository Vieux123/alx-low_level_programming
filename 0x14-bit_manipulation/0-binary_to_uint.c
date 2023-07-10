#include "main.h"

/**
  * binary_to_uint - converts a binary number to an unsigned int
  * @b: string containing the binary number
  *
  * Return: the converted number, or 0
  */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int dec_va = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		dec_va = 2 * dec_va + (b[i] - '0');
	}

	return (dec_va);
}
