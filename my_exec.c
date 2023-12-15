#include "main.h"
/**
 * execute_order_66 - function to create fork and execute commands
 *
 * @my_path: store the constructed path for command execution
 * @argv: array to store arguments
 * @environ: variable that manipulate the environment variables
 *
 */
void execute_order_66(char *my_path, char **argv, char **environ)
{
	pid_t pid;
	int status;

	pid = fork(); /* Fork a new process for command execution */
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) /* Child process executes the command */
	{
		/* Execute the command with arguments */
		if (execve(my_path, argv, environ) == -1)
		{
			printf("Command execution failed\n");
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process waits for child process to complete */
	{
		waitpid(pid, &status, 0);
	}
}
