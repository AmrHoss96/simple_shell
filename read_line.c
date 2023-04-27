#include "main.h"
/**
 * read_line - read a line of input from the user
 * @lineptr: pointer to buffer where the line should be stored
 * @n: size of the buffer
 * Return: number of characters read, or -1 on failure
 */
ssize_t read_line(char **lineptr, size_t *n)
{
	ssize_t nchars_read;

	printf("(My_Shell)$ ");
	nchars_read = getline(lineptr, n, stdin);
	if (nchars_read == -1)
	{
		perror("getline");
	}
	return (nchars_read);
}
