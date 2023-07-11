#include <stdio.h>
#include "main.h"

/**
  * append_text_to_file - function that append at the of a file
  * @filename: the pointer to the naming of the file
  * @text_content: writing tex to the file
  * Return: On success 1; -1 on failure
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int f, e, i = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (i = 0; text_content[i];)
			i++;
	}

	f = open(filename, O_WRONLY | O_APPEND);
	e = write(f, text_content, i);

	if (f == -1 || e == -1)
		return (-1);

	close(f);

	return (1);
}
