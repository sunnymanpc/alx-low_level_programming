#include "main.h"

/**
 * set_bit - Thhis will set one bit at an index to 1
 * @n: This is the pointer to the number for change
 * @index: This is the index of the bit set to 1
 *
 * Return:If successful 1, If it fails -1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}

