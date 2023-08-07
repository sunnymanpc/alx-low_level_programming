#include "main.h"

/**
 * append_text_to_file - At the end of a file this appends a text.
 * @filename: This will point to the name the file.
 * @text_content: This is a string to be added at the end of the file.
 * Return: -1 If the function fails,Otherwise 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a, b, c = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (c = 0; text_content[c];)
			c++;
	}

	a = open(filename, O_WRONLY | O_APPEND);
	b = write(a, text_content, c);

	if (a == -1 || b == -1)
		return (-1);

	close(a);

	return (1);
}
