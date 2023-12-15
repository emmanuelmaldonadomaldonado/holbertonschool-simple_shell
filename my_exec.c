#include "main.h"
/*
 *
 */
void execute_order_66(char *my_path, char **argv, char **environ)
{
	pid_t pid;
	int status;

	pid = fork(); /* Crear un nuevo proceso para la ejecución del comando */
	if (pid == -1)
	{
		perror("fork fallido");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) /* El proceso hijo ejecuta el comando */
	{
		/* Ejecutar el comando con los argumentos */
		if (execve(my_path, argv, environ) == -1)
		{
			printf("Fallo en la ejecución del comando\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{ /* El proceso padre espera a que el proceso hijo termine */
		waitpid(pid, &status, 0);
	}
}
