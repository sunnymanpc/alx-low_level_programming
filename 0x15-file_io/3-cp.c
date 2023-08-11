#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * create_buffer - This will allocate 1024 bytes a buffer.
 * @f: The file name buffer for storing characters.
 *
 * Return: This the pointer to the new buffer.
 */

char *create_buffer(char *f);
void close_file(int a);

char *create_buffer(char *f)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Cannot write to %s\n", f);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - This will close the descriptor file.
 * @a: This is the file descriptor to be closed.
 */
void close_file(int a)
{
	int x;

	x = close(a);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot close a %d\n", a);
		exit(100);
	}
}

/**
 * main - This will copy contents of one file into another file.
 * @argc: These are the number of arguments available to the program.
 * @argv: These are an array of pointers to the arguments.
 * Return: Success 0.
 *
 * Description: For inccorrect argument count - exit code 97.
 * For none existing or cannot be read from file_from - exit code 98.
 * For file_to cannot be written into or created - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int b, c, d, e;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	b = open(argv[1], O_RDONLY);
	d = read(b, buffer, 1024);
	c = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);

	do {
		if (b == -1 || d == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Cannot read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		e = write(c, buffer, d);
		if (c == -1 || e == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Cannot write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		d = read(b, buffer, 1024);
		c = open(argv[2], O_WRONLY | O_APPEND);

	} while (d > 0);

	free(buffer);
	close_file(b);
	close_file(c);

	return (0);
}
