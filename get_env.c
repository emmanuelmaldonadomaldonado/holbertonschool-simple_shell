#include "main.h"
#include <stdio.h>

char *_getenv(const char *PATH)
{
	char *result = NULL;
	char *current_var;
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		current_var = *env;
		if (strncmp(current_var, PATH, strlen(PATH)) == 0 && current_var[strlen(PATH)] == '=')
			result = malloc(strlen(current_var) - strlen(PATH));
		if (result == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		if (result != NULL)
		{
			strcpy(result, current_var + strlen(PATH) + 1);
			break;
		}
	}
	return (result);
}
