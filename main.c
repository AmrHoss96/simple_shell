#include "main.h"
/**
 * main - main function
 * Return: zero
*/
int main(void)
{
	char *line = NULL;
	size_t line_size = 0;

	while (1)
	{
		printf("simple_shell$ ");
		ssize_t line_length = getline(&line, &line_size, stdin);

		if (line_length < 0)
		{
			perror("getline failed");
			exit(EXIT_FAILURE);
		}
		line[line_length - 1] = '\0'; /* remove newline character */
		char **args = parse_line(line);

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
