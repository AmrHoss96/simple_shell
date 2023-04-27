#include "main.h"
/**
 * main - main function
 * Return: zero
*/
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("> ");
		line = read_line();
		args = tokenize_line(line);
		status = execute_builtin_command(args);
		if (status)
		{
			execute_external_command(args);
		}
		free(line);
		free_tokens(args);
	} while (status);

	return (EXIT_SUCCESS);
}
