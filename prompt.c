#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define my_args 100

int main(void)
{
	int num_token, k;
	char *argv[my_args];
	char *command = NULL;
	char *token;
	size_t buffer = 0;
	size_t length;
	char *path = "/usr/bin/";
	char my_path[my_args];

	while (1)
	{
		printf("$ ");
		if (getline(&command, &buffer, stdin) != -1)
		{
			length = strlen(command);
			if (command[length - 1] == '\n')
				command[length - 1] = '\0';

			if (strcmp(command, "") == 0)
				continue;

			if (strcmp(command, "exit") == 0) {
				free(command);
				return 0;
			}

			num_token = 0;
			token = strtok(command, " ");
			while (token != NULL && num_token < my_args - 1)
			{
				argv[num_token++] = token;
				token = strtok(NULL, " ");
			}
			argv[num_token] = NULL;

			if (num_token == 0)
				continue;

			for (k = 0; k < num_token; k++)
			{
				printf("%s ", argv[k]);
			}
			printf("\n");

			strcpy(my_path, path);
			strcat(my_path, argv[0]);

			if (execve(my_path, argv, NULL) == -1)
			{
				printf("command not found\n");
			}
		}
	}
	free(command);
	return 0;
}
