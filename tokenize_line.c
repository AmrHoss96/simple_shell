#include "main.h"
/**
 * tokenize_line - tokenize line
 * @line: inputed line
 * Return: tokens
*/
char **tokenize_line(char *line)
{
	int i = 0;
	char **tokens = malloc(MAX_NUM_TOKENS * sizeof(char *));
	char *token = strtok(line, " \t\n\r");

	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \t\n\r");
	}
	tokens[i] = NULL;
	return (tokens);
}
