#include "main.h"
/**
 * execute_builtin - executes buildtin
 * @args: inputted arguments
 * Return: 1
*/
int execute_builtin(char **args)
{
	if (args[0] == NULL)
	{
		return (0);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		return (0);
	}
	if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
		return (1);
	}
	return (1);
}
