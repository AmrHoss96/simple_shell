#include "main.h"
/**
 * execute_builtin_command - executes buildtin
 * @args: inputted arguments
 * Return: 1 if success
*/
int execute_builtin_command(char **args)
{
	char **env = environ;

	if (args[0] == NULL)
	{
		return (1);
	} 
	else if (strcmp(args[0], "exit") == 0)
	{
		return (0);
	} 
	else if (strcmp(args[0], "env") == 0)
	{
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		return (1);
	}
	else
		return (1);
}
