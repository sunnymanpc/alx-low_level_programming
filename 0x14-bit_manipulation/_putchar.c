#include "main.h"
#include <unistd.h>

/**
 * _putchar -This code writes the character c to stdout
 * @c: This is the character to print
 *
 * Return: 1 if successful
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

