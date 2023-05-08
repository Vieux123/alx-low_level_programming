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
	char *buff;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	t = read(fd, buff, letters);
	w = write(STDOUT_FILENO, buff, t);

	free(buff);
	close(fd);
	return (w);
}

