#include "main.h"

/**
 * clear_bit - This code sets the value of a bit to 0
 * @n: THis is the pointer to the number being changed
 * @index: This is the index of the bit to clear
 * Return: 1 if it is  successful, -1 if it fails
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
