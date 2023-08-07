#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- This will read text file and print.
 * @filename: This is the text file to be read
 * @letters: These are the number of letters to be read
 * Return: c - This is the actual number of bytes printed after being read.
 * If the function fails 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *a;
	ssize_t b;
	ssize_t c;
	ssize_t d;

	b = open(filename, O_RDONLY);
	if (b == -1)
		return (0);
	a = malloc(sizeof(char) * letters);
	d = read(b, a, letters);
	c = write(STDOUT_FILENO, a, d);

	free(a);
	close(b);
	return (c);
}
