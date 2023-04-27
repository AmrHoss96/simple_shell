#include "main.h"
/**
 * is_builtin - checks if builtin
 * @command: inputed command
 * Return: 1 if the command is a built-in command, 0 otherwise.
*/
int is_builtin(char *command)
{
	return (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0);
}
