#include "main.h"
/**
 * free_tokens - free allocated memory
 * @tokens: tokenized items
*/
void free_tokens(char **tokens)
{
	for (int i = 0; i < MAX_NUM_TOKENS; i++)
	{
		if (tokens[i] != NULL)
		{
			free(tokens[i]);
		}
		else
		{
			break;
		}
	}
	free(tokens);
}
