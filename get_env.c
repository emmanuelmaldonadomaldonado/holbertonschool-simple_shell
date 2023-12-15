#include "main.h"

/**
 * _getenv - function that gets an environment variable
 * @PATH: environment variable name
 *
 * Return: function returns the pointer to the extracted value
 */

char *_getenv(const char *PATH)
{
	char *result = NULL;
	char *current_var;
	char **env;
	size_t path_length = strlen(PATH); /* Storing the length of PATH */

	if (path_length == 0 || PATH == NULL)
	{
		fprintf(stderr, "Error: Invalid or empty PATH\n");
		return (NULL);
	}
	for (env = environ; *env != NULL; env++)
	{
		current_var = *env;
		if (strncmp(current_var, PATH, path_length) == 0 &&
				current_var[path_length] == '=')
			result = malloc(strlen(current_var) - path_length + 1);
		if (result == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		if (result != NULL)
		{
			strcpy(result, current_var + path_length + 1);
			break;
		}
	}
	return (result);
}
