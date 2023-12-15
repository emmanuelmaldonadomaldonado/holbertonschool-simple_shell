#include "main.h"
/*
 *
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
	return num_token;
}
