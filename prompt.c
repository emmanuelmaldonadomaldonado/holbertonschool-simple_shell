#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
	(void)argc;
	char *command = NULL;
	char *token;
	size_t buffer = 0;
	size_t length, i;

	while (1)
	{
		printf("$ ");
		if (getline(&command, &buffer, stdin) != -1)
		{
			length = strlen(command);
			for (i = 0; i < length; i++)
			{
				if (command[i] == '\n')
					command[i] = '\0';
			}
			if (strcmp(command, "exit") == 0)
			{
				free(command);
				return (0);
			}
			token = strtok(command, " ");
			while (token != NULL)
			{
				printf("%s\n", token);
				token = strtok(NULL, " ");
			}
		}
		else
		{
			break;
		}
	}
	while (*argv != NULL)
	{
		printf("%s ", *argv);
		argv++;
	}
	printf("\n");
	free(command);
	return (0);
}
