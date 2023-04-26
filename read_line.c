#include "main.h"
/**
 * read_line - reads line into stdin
*/
char* read_line(void)
{
	char* line = NULL;
	size_t bufsize = 0;
	ssize_t nread = getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	return (line);
}