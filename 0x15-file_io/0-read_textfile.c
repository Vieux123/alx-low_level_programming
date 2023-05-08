#include <stdlib.h>
#include <stdlib.h>
#include "main.h"

/**
  * read_textfile- Read a text file&print to POSIX STDOUT.
  * @filename: the text file to be read
  * @letters: number of letters which is read
  * Return: the actual number to be read and print
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fide, l, w;
	char *tex;

	tex = malloc(letters);
	if (tex == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	fide = open(filename, O_RDONLY);

	if (fide == -1)
	{
		free(tex);
		return (0);
	}

	l = read(fide, tex, letters);

	w = write(STDOUT_FILENO, tex, l);

	close(fide);

	return (w);
}

