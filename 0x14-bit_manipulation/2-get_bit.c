#include "main.h"

/**
 * get_bit - this will return the value of a bit
 * at an index in a decimal number
 * @n: this is the number to search for
 * @index: this is the index of the bit
 * Return: this remains the value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
