#include "main.h"
/*
 *
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
	return command_found;
}
