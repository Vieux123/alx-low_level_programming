#include "main.h"
#include <stdlib.h>

/**
  * read_textfile - reads a text file and print to the POSIX stdout.
  * @filename: a pointer to read in the name of the file
  * @letters: number of letters it should read and print
  *
  * Return: the actual number of letters it should read and print
  *         otherwise 0 if the fnct fails or filename is NULL
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t f, l, e;
	char *baf;

	if (filename == NULL)
		return (0);

	baf = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	f = open(filename, O_RDONLY);
	l = read(f, baf, letters);
	e = write(STDOUT_FILENO, baf, l);

	if (f == -1 || l == -1 || e != l)
	{
		free(baf);
		return (0);
	}

	free(baf);
	close(f);

	return (e);
}
