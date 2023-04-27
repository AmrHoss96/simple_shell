#include "main.h"
/**
 * execute_builtin - executes buildtin
 * @args: inputted arguments
*/
void execute_builtin(char **args)
{
	char **env = environ;

	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
}
