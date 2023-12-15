#include "main.h"
/**
 * i_path - function aims to find the full path of an executable file
 * @command: Input command string
 * @argv: Array to store command arguments
 * @path: Default path for command execution
 * @my_path: Store the constructed path for command execution
 *
 * Return: returns 1 if the command is found and executable
 */
int i_path(char *command, char **argv, char **path, char *my_path)
{
	int command_found = 0;
	size_t i;

	if (access(command, X_OK) == 0)
	{
		strcpy(my_path, command);
		command_found = 1;
	}
	else
	{
		for (i = 0; i < 5; i++)
		{
			strcpy(my_path, path[i]);
			strcat(my_path, command);
			if (access(my_path, X_OK) == 0)
			{
				command_found = 1;
				break;
			}
		}
	}
	if (!command_found) /* If the command is not found, print an error and exit */
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free(command);
		exit(127);
	}
	return (command_found);
}
