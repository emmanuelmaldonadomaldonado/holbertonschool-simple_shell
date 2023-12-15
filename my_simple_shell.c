#include "main.h"
/**
 * main - simple shell
 */
int main(void)
{
	char *path[] = {"/usr/local/bin/", "/usr/bin/", "/bin/", "/usr/local/games/", "/usr/games/"}; /* Default path for command execution */
	char my_path[my_args]; /* Store the constructed path for command execution */
	char *command = NULL; /* Input command string */
	char *argv[my_args]; /* Array to store command arguments */
	size_t buffer = 0;
	size_t length;
	int num_token;
	int command_found;
	int interactive = isatty(fileno(stdin)); /* Check if my_simple_shell is in interactive mode */

	while (1) /*interactive mode */
	{
		imprimir_prompt(interactive); /* Print the shell prompt */
		if (getline(&command, &buffer, stdin) != -1) /* Read command from user input */
		{
			length = strlen(command);
			if (command[length - 1] == '\n')
				command[length - 1] = '\0';
			if (strcmp(command, "") == 0) /* Check for empty command */
				continue;
			if (strcmp(command, "exit") == 0) /* Check for "exit" command to terminate the shell */
			{
				free(command);
				exit(0);
			}
			num_token = tokenizer(command, argv);
			if (num_token == 0) /* Check for no arguments provided */
				continue;
			command_found = i_path(argv[0], path, my_path);
			if (!command_found) /* If the command is not found, print an error and exit */
			{
				fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
				free(command);
				exit(127);
			}
			execute_order_66(my_path, argv, environ); /* Execute the command with arguments */
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
