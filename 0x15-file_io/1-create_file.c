#include "main.h"

/**
 * create_file - This will create a file.
 * @filename: This is a pointer to the name of the file tobe  created.
 * @text_content: This is a pointer to a string that writest to the file
 * * Return: If the function fails - -1. elese - 1.
 */

int create_file(const char *filename, char *text_content)
{
	int x, y, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	x = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	y = write(x, text_content, len);

	if (x == -1 || y == -1)
		return (-1);

	close(x);

	return (1);
}
