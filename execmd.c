#include "main.h"
/**
 * execmd - help us get path of commands
 * @argv: argument vector
*/
void execmd(char **argv)
{
	char *cmd = NULL, *actual_cmd = NULL;
	pid_t pid;

	if (argv)
	{
		cmd = argv[0];
		actual_cmd = get_location(cmd);
		if (actual_cmd == NULL)
		{
		fprintf(stderr, "Command not found: %s\n", cmd);
		return;
		}
		pid = fork();
		if (pid < 0)
		{
		perror("fork");
		return;
		}
		else if (pid == 0)
		{
		if (execve(actual_cmd, argv, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		}
		else
		{
		int status;
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return;
		}
		}
	}
}
