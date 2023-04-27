#include "main.h"
/**
 * main - main function
 * Return: zero
*/
int main(void)
{
	char *line = NULL;
	char **args;

	while (1)
	{
		printf("simple_shell$ ");
		line = read_line();
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
		free(line);
		line = NULL;
	}
	return (0);
}
