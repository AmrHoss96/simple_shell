#include "main.h"
/**
 * main - main function
 * Return: zero
*/
int main(void)
{
	ssize_t line_length;
	char **args;
	char *line = NULL;
	size_t line_size = 0;

	while (1)
	{
		printf("simple_shell$ ");
		line_length = getline(&line, &line_size, stdin);

		if (line_length < 0)
		{
			perror("getline failed");
			exit(EXIT_FAILURE);
		}
		line[line_length - 1] = '\0'; /* remove newline character */
		args = parse_line(line);

		if (args != NULL)
		{
			if (is_builtin(args[0]))
			{
				execute_builtin(args);
			}
			else
			{
				execute_external_command(args);
			}
			free(args);
		}
	}
	free(line);
	return (0);
}
