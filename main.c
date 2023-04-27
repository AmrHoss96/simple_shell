#include "main.h"
/**
 * main - main function
 * Return: zero
*/
int main(void)
{
	char **args;
	char *line = NULL;
	int status;

	while (1)
	{
		printf("simple_shell$ ");
		line = read_line();
		args = tokenize_line(line);
		status = execute_builtin(args);
		if (status)
		{
			execute_external_command(args);
		}
		free(line);
		free(args);
	}

	return (EXIT_SUCCESS);
}
