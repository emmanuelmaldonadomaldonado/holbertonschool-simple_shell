#include "main.h"
/**
 * i_path - function aims to find the full path of an executable file
 * @command: Input command string
 * @path: Default path for command execution
 * @my_path: Store the constructed path for command execution
 *
 * Return: returns 1 if the command is found and executable
 */
int i_path(char *command, char **path, char *my_path)
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
	return (command_found);
}
