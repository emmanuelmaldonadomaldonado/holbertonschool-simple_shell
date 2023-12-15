#include "main.h"
/*
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
		if (execve(my_path, argv, environ) == -1) /* Execute the command with arguments */
		{
			printf("Command execution failed\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0); /* Parent process waits for child process to complete */
	}
}
