#include "main.h"
/**
 * tokenizer - function to split the command string into tokens
 * @command: Input command string
 * @argv: Array to store command arguments
 *
 * Return: total of tokens
 */
int tokenizer(char *command, char **argv)
{
	int num_token = 0;
	char *token = strtok(command, " ");

	while (token != NULL && num_token < my_args - 1)
	{
		argv[num_token++] = token;
		token = strtok(NULL, " ");
	}
	argv[num_token] = NULL;
	if (num_token == 0) /* Check for no arguments provided */
	{
		return (main());
	}

	return (num_token);
}
