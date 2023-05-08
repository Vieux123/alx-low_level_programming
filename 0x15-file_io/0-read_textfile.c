#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
  * read_textfile- which reads a text file and printsto STDOUT
  * @filename: text file type as variable pointer
  * @letters: size of letters to be read in numbers
  *
  *Return: the actual number of letters it could read and print, otherwise 0
  */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fil, let, wr;
	char *buff;


	buff - malloc(letters);
	if (text == NULL)
		return (0);

	if (filename == NULL)
		return (0);
	fil = open(filename, ORDONLY);

	if (fil == -1)
	{
		free(buff);
		return (0);
	}

	let  = read(file, buff, letters);

	wr = write(STDOUT_FILENO, buff, let);

	close(fil);

	return (wr);
}
