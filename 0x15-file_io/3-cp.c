#include "main.h"

#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fde);

/**
  * create_buffer - Allocates 1024 bytes for a buffer.
  * @file: file name buffer is storing char(s) for.
  *
  * Return: A pointer to the newly-allocated buffer.
  */
char *create_buffer(char *file)
{
	char *baf;

	baf = malloc(sizeof(char) * 1024);

	if (baf == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (baf);
}

/**
  * close_file - Close file descriptors.
  * @fde: The file descriptor being closed.
  */
void close_file(int fde)
{
	int p;

	p = close(fde);

	if (p == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fde);
		exit(100);
	}
}

/**
  * main - Copies the content of a file to another file.
  * @argc: The number of arguments supplied to program.
  * @argv: an array of pointers to the arguments.
  * Return: 0 on success.
  *
  * Description: If the argument count is incorrect - exit code 97.
  *              If file_from does not exist or can not read it- exit code 98.
  *              If you cannot create or write to file_to fails- exit code 99.
  *              If file descriptor cannot be closed - exit code 100.
  */
int main(int argc, char *argv[])
{
	int from, to, l, e;
	char *baf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	baf = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	l = read(from, baf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || l == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(baf);
			exit(98);
		}

		e = write(to, baf, l);
		if (to == -1 || e == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(baf);
			exit(99);
		}

		l = read(from, baf, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (l > 0);

	free(baf);
	close_file(from);
	close_file(to);

	return (0);
}
