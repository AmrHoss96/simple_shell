#include "main.h"
/**
 * parse_line - tokenize line
 * @line: inputted line
 * Return: line
*/
char **parse_line(char *line)
{
	int i = 0;
	char *token;
	char **args = malloc(MAX_INPUT_SIZE * sizeof(char *));

	if (args == NULL)
	{
	perror("malloc failed");
	exit(EXIT_FAILURE);
	}

	token = strtok(line, " ");
	while (token != NULL)
	{
		args[i] = token;
		i++;

		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
