#include "main.h"

/**
 * get_endianness - This code checks if a machine is big or small endian
 * Return: If it is big 0, if it is small 1
 */

int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
