#include "main.h"
/**
 * main - simple shell
 * Return: 0 if is successful
 */
int main(void)
{
	char *path[] = {"/usr/local/bin/", "/usr/bin/",
		"/bin/", "/usr/local/games/", "/usr/games/"};
	char my_path[my_args]; /* Store the constructed path for command execution */
	char *command = NULL; /* Input command string */
	char *argv[my_args]; /* Array to store command arguments */
	size_t buffer = 0;
	size_t length;
	int interactive = isatty(fileno(stdin));

	while (1) /*interactive mode */
	{
		imprimir_prompt(interactive); /* Print the shell prompt */
		if (getline(&command, &buffer, stdin) != -1)/*Read command from user input*/
		{
			length = strlen(command);
			if (command[length - 1] == '\n')
				command[length - 1] = '\0';
			if (strcmp(command, "") == 0) /* Check for empty command */
				continue;
			if (strcmp(command, "exit") == 0)
			{
				free(command);
				exit(0);
			}
			tokenizer(command, argv);
			i_path(argv[0], argv, path, my_path);
			execute_order_66(my_path, argv, environ);
		}
		else /* If input is not read properly, break the loop */
		{
			if (!interactive)
			{
				break;
			}
			printf("\n");
			break;
		}
	}
	free(command);
	return (0);
}
