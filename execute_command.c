#include "main.h"
/**
 * execute_external_command - executes commands
 * @args: inputted arguments
*/
void execute_external_command(char **args)
{
	char *path, *dir;
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		char *path_env = getenv("PATH");
		if (path_env == NULL)
		{
		fprintf(stderr, "Error: PATH environment variable not set\n");
		exit(EXIT_FAILURE);
		}

		path = strdup(path_env);
		dir = strtok(path, ":");

		while (dir != NULL)
		{
		char *cmd_path = malloc(strlen(dir) + strlen(args[0]) + 2);
		sprintf(cmd_path, "%s/%s", dir, args[0]);
		execv(cmd_path, args);
		free(cmd_path);
		dir = strtok(NULL, ":");
		}

		fprintf(stderr, "%s: command not found\n", args[0]);
		free(path);
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
		int exit_status = WEXITSTATUS(status);
		if (exit_status != 0)
		{
			fprintf(stderr, "Command failed with exit code %d\n", exit_status);
		}
		}
		else if (WIFSIGNALED(status))
		{
		int sig = WTERMSIG(status);
		fprintf(stderr, "Command terminated by signal %d\n", sig);
		}
	}
}
