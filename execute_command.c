#include "main.h"
/**
 * execute_external_command - executes commands
 * @args: inputted arguments
*/
void execute_external_command(char **args)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");
	char *full_path = malloc(MAX_INPUT_SIZE * sizeof(char));

	while (token != NULL)
	{
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, args[0]);
		pid_t pid = fork();

		if (access(full_path, X_OK) == 0)
		{
			if (pid == 0)
			{
				execv(full_path, args);
				perror("execv failed");
				exit(EXIT_FAILURE);
			}
			else if (pid < 0)
			{
				perror("fork failed");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(pid, NULL, 0);
				return;
			}
		}
		token = strtok(NULL, ":");
	}

	free(full_path);
	printf("%s: command not found\n", args[0]);
}
