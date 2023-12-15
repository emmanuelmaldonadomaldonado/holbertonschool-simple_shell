#include "main.h"
/*
 */
int main(void)
{
	char *path[] = {"/usr/local/bin/", "/usr/bin/", "/bin/", "/usr/local/games/", "/usr/games/"}; /* Ruta predeterminada para la ejecución de comandos */
	char my_path[my_args];
	char *command = NULL; /* Cadena de comando de entrada */
	char *argv[my_args];
	extern char **environ; /* Copia de las variables de entorno */
	size_t buffer = 0;
	size_t length;
	int num_token;
	int command_found;
	int interactive = isatty(fileno(stdin)); /* Verificar si la terminal está en modo interactivo */

	while (1)
	{
		imprimir_prompt(interactive); /* Imprimir el prompt de la terminal */
		if (getline(&command, &buffer, stdin) != -1)
		{
			length = strlen(command);
			if (command[length - 1] == '\n')
				command[length - 1] = '\0';
			if (strcmp(command, "") == 0) /* Verificar comando vacío */
				continue;
			if (strcmp(command, "exit") == 0) /* Comprobar comando "exit" para terminar la terminal */
			{
				free(command);
				exit(0);
			}
			num_token = tokenizer(command, argv);
			if (num_token == 0) /* Verificar si no se proporcionaron argumentos */
				continue;
			command_found = i_path(argv[0], path, my_path);
			if (!command_found)
			{
				fprintf(stderr, "./hsh: 1: %s: no se encontró\n", argv[0]);
				free(command);
				exit(127);
			}
			execute_order_66(my_path, argv, environ);
		}
		else
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
	return 0;
}
