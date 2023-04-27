#include "main.h"
/**
 * run_shell - main loop of the shell
 */
void run_shell(void)
{
	char *line = NULL, *line_copy = NULL, *token;
	const char *delim = " \n";
	size_t n = 0;
	int i, num_tokens = 0;

	while (1)
	{
		ssize_t nchars_read = read_line(&line, &n);

		if (nchars_read == -1)
			break;
		line_copy = malloc(sizeof(char) * nchars_read);
		if (line_copy == NULL)
		{
			perror("malloc");
			break;
		}
		strcpy(line_copy, line);
		token = strtok(line, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		char **argv = malloc(sizeof(char *) * num_tokens);

		token = strtok(line_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmd(argv);
		free(line_copy);
		free(argv);
	}
	free(line);
}
