#include "main.h"
/**
 * free_tokens - free allocated memory
 * @tokens: tokenized items
*/
void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
