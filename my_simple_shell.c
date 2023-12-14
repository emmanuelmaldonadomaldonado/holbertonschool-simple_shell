#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define my_args 100 /* Define the maximum number of arguments */

/* Function to print the shell prompt */
void imprimir_prompt(int interactive)
{
	if (interactive)
	{
		char *dolar = "$";
		printf("%s ", dolar);
		fflush(stdout); /* Ensure prompt prints immediately */
	}
}

int main(void)
{
	int num_token, command_found;
	size_t i;
	char *argv[my_args]; /* Array to store command arguments */
	char *command = NULL; /* Input command string */
	char *token;
	size_t buffer = 0;
	size_t length;
	char *path[] = {"/usr/local/bin/", "/usr/bin/", "/bin/", "/usr/local/games/", "/usr/games/"}; /* Default path for command execution */
	char my_path[my_args]; /* Store the constructed path for command execution */
	int status;
	pid_t pid;
	extern char **environ; /* Copy of the environment variables */

	int interactive = isatty(fileno(stdin)); /* Check if shell is in interactive mode */

	while (1) /*interactive mode */
	{
		imprimir_prompt(interactive); /* Print the shell prompt */

		/* Read command from user input */
		if (getline(&command, &buffer, stdin) != -1)
		{
			length = strlen(command);
			if (command[length - 1] == '\n')
				command[length - 1] = '\0';

			if (strcmp(command, "") == 0) /* Check for empty command */
				continue;

			if (strcmp(command, "exit") == 0) /* Check for "exit" command to terminate the shell */
			{
				free(command);
				return 0;
			}

			num_token = 0;
			token = strtok(command, " ");
			while (token != NULL && num_token < my_args - 1) /* Tokenize the command into arguments */
			{
				argv[num_token++] = token;
				token = strtok(NULL, " ");
			}
			argv[num_token] = NULL;

			if (num_token == 0) /* Check for no arguments provided */
				continue;

			command_found = 0; /* Flag to check if the command is found */
			if (access(argv[0], X_OK) == 0) /* Check if the command is executable directly */
			{
				strcpy(my_path, argv[0]);
				command_found = 1;
			}
			else
			{
				for (i = 0; i < 5; i++)
				{
					strcpy(my_path, path[i]); /* Construct the full path for the command */
					strcat(my_path, argv[0]);
					if (access(my_path, X_OK) == 0) /* Check if the command is executable in this path */
					{
						command_found = 1;
						break;
					}
				}
			}
			/* If the command is not found, print an error and continue */
			if (!command_found)
			{
				printf("Command not found\n");
				continue;
			}
			pid = fork(); /* Fork a new process for command execution */
			if (pid == -1)
			{
				perror("fork failed");
				exit(EXIT_FAILURE);
			}
			if (pid == 0) /* Child process executes the command */
			{
				/* Execute the command with arguments */
				if (execve(my_path, argv, environ) == -1)
				{
					printf("Command execution failed\n");
					exit(EXIT_FAILURE);
				}
			}
			else /* Parent process waits for child process to complete */
			{
				waitpid(pid, &status, 0);
			}
		}
		else /* If input is not read properly, break the loop */
		{
			if (!interactive)
			{
				break;
			}
			printf("\n"); /* If it is interactive and input is not read properly, print a new line */
			break;
		}
	}
	free(command);
	return 0;
}
