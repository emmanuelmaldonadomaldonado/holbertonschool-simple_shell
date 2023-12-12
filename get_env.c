#include "main.h"
#include <stdio.h>

char *_getenv(const char *name)
{
	char *result = NULL;
	char *current_var;
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		current_var = *env;
		if (strncmp(current_var, name, strlen(name)) == 0 && current_var[strlen(name)] == '=')
			result = malloc(strlen(current_var) - strlen(name));
		if (result != NULL)
		{
			strcpy(result, current_var + strlen(name) + 1);
			break;
		}
	}
	return (result);
}
