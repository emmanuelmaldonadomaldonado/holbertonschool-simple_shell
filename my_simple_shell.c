#include "main.h"

extern char **environ;

#define my_args 100 /*Define the maximum number of arguments*/


void imprimir_prompt(int interactive)
{
	if (interactive)
	{
		char *dolar = "$";
		printf("%s ", dolar);
		/*fflush(stdout);*/
	}
}

int main(void)
{
	int num_token, k;
	size_t i;
	char *argv[my_args]; /*Array to store command arguments*/
	char *command = NULL; /*Input command string*/
	char *token;
	size_t buffer = 0;
	size_t length;
	char *path[] = {"/usr/local/bin/", "/usr/bin/", "/bin/", "/usr/local/games/", "/usr/games/"}; /*Default path for command execution*/
	char my_path[my_args]; /*Store the constructed path for command execution*/
	int status;
	pid_t pid;
	char **env = environ; /*Copy of the environment variables*/

	int interactive = isatty(fileno(stdin));

	while (1) /*interactive*/
	{
		imprimir_prompt(interactive);
		if (getline(&command, &buffer, stdin) != -1) /*Read command from user input*/
		{
			length = strlen(command);
			if (command[length - 1] == '\n')
				command[length - 1] = '\0';

			if (strcmp(command, "") == 0) /*Check for empty command*/
				continue;

			if (strcmp(command, "exit") == 0) /*Check for "exit" command to terminate the shell*/
			{
				free(command);
				return 0;
			}

			num_token = 0;
			token = strtok(command, " ");
			while (token != NULL && num_token < my_args - 1) /*Tokenize the command into arguments*/
			{
				argv[num_token++] = token;
				token = strtok(NULL, " ");
			}
			argv[num_token] = NULL;

			if (num_token == 0) /*Check for no arguments provided*/
				continue;

			for (k = 0; k < num_token; k++)
				;

			if (access(argv[0], X_OK) == 0) /*Check if the command is executable*/
			{
				for (i = 0; i < 5; i++)
				{
					execve(command, argv, env);
					break;
				}
			}
			else
			{
				for (i = 0; i < 5; i++)
				{
					strcpy(my_path, path[i]); /*Construct the full path for the command*/
					strcat(my_path, argv[0]);

					if (access(my_path, X_OK) == 0) /*Check if the command is executable*/
						break;
				}
			}

			if (access(my_path, X_OK) == -1)
			{
				printf("Command not found1\n");
				continue;
			}
			pid = fork(); /*Fork a new process for command execution*/
			if (pid == -1)
			{
				perror("fork failed");
				exit(EXIT_FAILURE);
			}

			if (pid == 0) /*Child process executes the command*/
			{
				if (execve(my_path, argv, env) == -1)
				{
					printf("command not found\n");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				waitpid(pid, &status, 0); /* Parent process waits for child process to complete */
			}
		}
		else /* If input is not read properly, break the loop */
		{
			if (!interactive) /*Si no es interactivo, no imprimas una nueva línea*/
			{
				break;
			}
			printf("\n"); /* Si es interactivo y la entrada no se lee correctamente, imprime una nueva línea*/
			break;
		}
	}
	free(command);
	return 0;
}
