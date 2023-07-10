#include "main.h"

/**
  * get_bit - returns the value of a bit at a given index in a decimal number
  * @n: number to search
  * @index: index of bit
  *
  * Return: value of the bit
  */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_va;

	if (index > 63)
		return (-1);

	bit_va = (n >> index) & 1;

	return (bit_va);
}
