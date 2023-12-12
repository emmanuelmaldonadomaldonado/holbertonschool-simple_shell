/*int main (int argc, char *argv[])
{
	(void)argc;
	char *command = NULL;
	char *token;
	size_t buffer = 0;
	size_t length, i;

	while (1)
	{
		printf("$ ");
		if (getline(&command, &buffer, stdin) != -1)
		{
			length = strlen(command);
			for (i = 0; i < length; i++)
			{
				if (command[i] == '\n')
					command[i] = '\0';
			}
			if (strcmp(command, "exit") == 0)
			{
				free(command);
				return (0);
			}
			token = strtok(command, " ");
			while (token != NULL)
			{
				printf("%s\n", token);
				token = strtok(NULL, " ");
			}
		}
		else
		{
			break;
		}
	}
	while (*argv != NULL)
	{
		printf("%s ", *argv);
		argv++;
	}
	printf("\n");
	free(command);
	return (0);
}*/

/*#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 50  // Establece un límite máximo de tokens para el array

int main(void) {

    char *command = NULL;
    size_t buffer = 0;
    ssize_t input_length;

    while (1) {
        printf("$ ");

        if ((input_length = getline(&command, &buffer, stdin)) != -1) {
            // Elimina el carácter de nueva línea si está presente
            if (command[input_length - 1] == '\n') {
                command[input_length - 1] = '\0';
            }

            // Verifica si el comando es "exit"
            if (strcmp(command, "exit") == 0) {
                free(command);
                return 0;
            }

            // Tokenización
            char *token;
            char **tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
            if (tokens == NULL) {
                perror("Error al asignar memoria para tokens");
                exit(EXIT_FAILURE);
            }

            size_t token_count = 0;
            token = strtok(command, " ");
            while (token != NULL && token_count < MAX_TOKENS) {
                tokens[token_count] = strdup(token);
                if (tokens[token_count] == NULL) {
                    perror("Error al duplicar el token");
                    exit(EXIT_FAILURE);
                }

                token_count++;
                token = strtok(NULL, " ");
            }

            // Imprime los tokens
            printf("Tokens:\n");
            for (size_t i = 0; i < token_count; i++) {
                printf("%s\n", tokens[i]);
            }

            // Liberar memoria de tokens
            for (size_t i = 0; i < token_count; i++) {
                free(tokens[i]);
            }
            free(tokens);
        } else {
            break;
        }
    }

    free(command);
    return 0;
}*/

/*#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 50  // Establece un límite máximo de tokens para el array

int main(void) {
    char *command = NULL;
    size_t buffer = 0;
    ssize_t input_length;

    while (1) {
        printf("$ ");
        
        if ((input_length = getline(&command, &buffer, stdin)) != -1) {
            // Elimina el carácter de nueva línea si está presente
            if (input_length > 0 && command[input_length - 1] == '\n') {
                command[input_length - 1] = '\0';
            }

            // Verifica si el comando es "exit"
            if (strcmp(command, "exit") == 0) {
                free(command);
                return 0;
            }

            // Verifica si la entrada está vacía y continúa con la siguiente iteración
            if (strlen(command) == 0) {
                continue;
            }

            // Tokenización
            char *token;
            char **tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
            if (tokens == NULL) {
                perror("Error al asignar memoria para tokens");
                exit(EXIT_FAILURE);
            }

            size_t token_count = 0;
            token = strtok(command, " ");
            while (token != NULL && token_count < MAX_TOKENS) {
                tokens[token_count] = strdup(token);
                if (tokens[token_count] == NULL) {
                    perror("Error al duplicar el token");
                    exit(EXIT_FAILURE);
                }

                token_count++;
                token = strtok(NULL, " ");
            }

            // Imprime los tokens
            printf("Tokens:\n");
            for (size_t i = 0; i < token_count; i++) {
                printf("%s\n", tokens[i]);
            }

            // Liberar memoria de tokens
            for (size_t i = 0; i < token_count; i++) {
                free(tokens[i]);
            }
            free(tokens);
        } else {
            break;
        }
    }

    free(command);
    return 0;
}*/

/*#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TOKENS 50  // Establece un límite máximo de tokens para el array

int main(void) {
    char *command = NULL;
    size_t buffer = 0;
    ssize_t input_length;

    while (1) {
        printf("$ ");
        
        if ((input_length = getline(&command, &buffer, stdin)) != -1) {
            // Elimina el carácter de nueva línea si está presente
            if (input_length > 0 && command[input_length - 1] == '\n') {
                command[input_length - 1] = '\0';
            }

            // Verifica si el comando es "exit"
            if (strcmp(command, "exit") == 0) {
                free(command);
                return 0;
            }

            // Verifica si la entrada está vacía y continúa con la siguiente iteración
            if (strlen(command) == 0) {
                continue;
            }

            // Tokenización
            char *token;
            char *tokens[MAX_TOKENS];  // Usa un array de punteros de tamaño fijo
            size_t token_count = 0;

            token = strtok(command, " ");
            while (token != NULL && token_count < MAX_TOKENS - 1) {
                tokens[token_count] = token;
                token_count++;
                token = strtok(NULL, " ");
            }
            tokens[token_count] = NULL;  // Añade NULL al final del array de tokens

            // Ejecución de comandos
            pid_t pid = fork();

            if (pid == -1) {
                perror("Error al crear el proceso hijo");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {  // Código del proceso hijo
                execvp(tokens[0], tokens);
                perror("Error al ejecutar el comando");  // Se ejecutará solo si execvp falla
                exit(EXIT_FAILURE);
            } else {  // Código del proceso padre
                waitpid(pid, NULL, 0);
            }
        } else {
            break;
        }
    }

    free(command);
    return 0;
}*/

/*#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TOKENS 50  // Establece un límite máximo de tokens para el array

int main(void) {
    char *command = NULL;
    size_t buffer = 0;
    ssize_t input_length;

    while (1) {
        printf("$ ");
        
        if ((input_length = getline(&command, &buffer, stdin)) != -1) {
            // Elimina el carácter de nueva línea si está presente
            if (input_length > 0 && command[input_length - 1] == '\n') {
                command[input_length - 1] = '\0';
            }

            // Verifica si el comando es "exit"
            if (strcmp(command, "exit") == 0) {
                free(command);
                return 0;
            }

            // Verifica si la entrada está vacía y continúa con la siguiente iteración
            if (strlen(command) == 0) {
                continue;
            }

            // Tokenización
            char *token;
            char *tokens[MAX_TOKENS];
            size_t token_count = 0;

            token = strtok(command, " ");
            while (token != NULL && token_count < MAX_TOKENS - 1) {
                tokens[token_count] = token;
                token_count++;
                token = strtok(NULL, " ");
            }
            tokens[token_count] = NULL;

            // Ejecución de comandos
            pid_t pid = fork();

            if (pid == -1) {
                perror("Error al crear el proceso hijo");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {  // Código del proceso hijo
                // Utiliza execve en lugar de execvp
                execve(tokens[0], tokens, NULL);
                perror("Error al ejecutar el comando");
		printf("Comando: %s\n", tokens[0]);
                exit(EXIT_FAILURE);
            } else {  // Código del proceso padre
                waitpid(pid, NULL, 0);
            }
        } else {
            break;
        }
    }

    free(command);
    return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define my_args 100

int main(void)
{
	int num_token;
	char *argv[my_args];
	char *command = NULL;
	char *token;
	size_t buffer = 0;
	size_t length;
	char *path = "/usr/bin/";
	char my_path[my_args];

	while (1)
	{
		printf("$ ");
		if (getline(&command, &buffer, stdin) != -1)
		{
			length = strlen(command);
			if (command[length - 1] == '\n')
				command[length - 1] = '\0';

			if (strcmp(command, "") == 0)
				continue;

			if (strcmp(command, "exit") == 0) {
				free(command);
				return 0;
			}

			num_token = 0;
			token = strtok(command, " ");
			while (token != NULL && num_token < my_args - 1)
			{
				argv[num_token++] = token;
				token = strtok(NULL, " ");
			}
			argv[num_token] = NULL;

			if (num_token == 0)
				continue;

			pid_t pid = fork();

			if (pid == -1)
            		{
                	perror("Error al crear el proceso hijo");
                	exit(EXIT_FAILURE);
          	 	}
            		else if (pid == 0) // Código del proceso hijo
			{
			strcpy(my_path, path);
			strcat(my_path, argv[0]);

			if (execve(my_path, argv, NULL) == -1)
			{
				printf("command not found\n");
			}
			else // Código del proceso padre
            		{
               			waitpid(NULL);
				{
                		printf("Comando ejecutado en un proceso hijo.\n");
            		}
		}
	}
	free(command);
	return 0;
    }
}*/


/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define my_args 100

int main(void)
{
	int num_token, k;
	char *argv[my_args];
	char *command = NULL;
	char *token;
	size_t buffer = 0;
	size_t length;
	char *path = "/usr/bin/";
	char my_path[my_args];
	int status;
	pid_t pid;

	while (1)
	{
		printf("$ ");
		if (getline(&command, &buffer, stdin) != -1)
		{
			length = strlen(command);
			if (command[length - 1] == '\n')
				command[length - 1] = '\0';

			if (strcmp(command, "") == 0)
				continue;

			if (strcmp(command, "exit") == 0)
			{
				free(command);
				return 0;
			}

			num_token = 0;
			token = strtok(command, " ");
			while (token != NULL && num_token < my_args - 1)
			{
				argv[num_token++] = token;
				token = strtok(NULL, " ");
			}
			argv[num_token] = NULL;

			if (num_token == 0)
				continue;

			for (k = 0; k < num_token; k++)
			{
				printf("%s ", argv[k]);
			}
			printf("\n");
			
			strcpy(my_path, path);
			strcat(my_path, argv[0]);
			
			if (access(my_path, X_OK) == -1)
            		{
                		perror("access");
                		printf("Command not found or lack of execute permissions\n");
                		continue;
            		}

			pid = fork();
			if (pid == -1)
			{
				perror("fork failed");
				exit(EXIT_FAILURE);
			}

			if (pid == 0)
			{
				if (execve(my_path, argv, NULL) == -1)
				{
					printf("command not found\n");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				waitpid(pid, &status, 0);
			}
		}
		else
		{
			printf("\n");
			break;
		}
	}
	free(command);
	return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define my_args 100

int main(void)
{
    int num_token, k;
    char *argv[my_args];
    char *command = NULL;
    char *token;
    size_t buffer = 0;
    size_t length;
    char *path = "/usr/bin/";
    char my_path[my_args];
    int status;
    pid_t pid;

    while (1)
    {
        // Verificar si la entrada estándar está conectada a un terminal
        if (!isatty(fileno(stdin))) {
            printf("stdin is not connected to a terminal.\n");
            break;
        }

        printf("$ ");
        if (getline(&command, &buffer, stdin) != -1)
        {
            length = strlen(command);
            if (command[length - 1] == '\n')
                command[length - 1] = '\0';

            if (strcmp(command, "") == 0)
                continue;

            if (strcmp(command, "exit") == 0)
            {
                free(command);
                return 0;
            }

            num_token = 0;
            token = strtok(command, " ");
            while (token != NULL && num_token < my_args - 1)
            {
                argv[num_token++] = token;
                token = strtok(NULL, " ");
            }
            argv[num_token] = NULL;

            if (num_token == 0)
                continue;

            for (k = 0; k < num_token; k++)
            {
                printf("%s ", argv[k]);
            }
            printf("\n");

            strcpy(my_path, path);
            strcat(my_path, argv[0]);

            if (access(my_path, X_OK) == -1)
            {
                printf("Command not found or lack of execute permissions\n");
                continue;
            }

            pid = fork();
            if (pid == -1)
            {
                perror("fork failed");
                exit(EXIT_FAILURE);
            }

            if (pid == 0)
            {
                if (execve(my_path, argv, NULL) == -1)
                {
                    printf("command not found\n");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                waitpid(pid, &status, 0);
            }
        }
        else
        {
            printf("\n");
            break;
        }
    }
    free(command);
    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

#define my_args 100 Define the maximum number of arguments

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

void imprimir_prompt(int interactive) {
    
	if (interactive) {
	
		char *dolar = "$";    
		printf("%s ", dolar);
        fflush(stdout);
    }
}

int main(void) {
    int num_token, k;
    size_t i;
    char *argv[my_args];
    char *command = NULL;
    char *token;
    size_t buffer = 0;
    size_t length;
    char *path = {"/usr/local/bin/", "/usr/bin/", "/bin/", "/usr/local/games/", "/usr/games/"};
    char my_path[my_args];
    int status;
    pid_t pid;
    char **env = environ; Copy of the environment variables
    size_t path_size = sizeof(path) / sizeof(path[0]);


    int is_interactive = isatty(fileno(stdin));

    while (1) {
        imprimir_prompt(is_interactive);

        if (getline(&command, &buffer, stdin) != -1) {
            length = strlen(command);

	    if (length > 0 && command[length - 1] == '\n')
            if (command[length - 1] == '\n')
                command[length - 1] = '\0';

            if (strcmp(command, "") == 0)
                continue;

            if (strcmp(command, "exit") == 0) {
                free(command);
                return 0;
            }

            num_token = 0;
            token = strtok(command, " ");
            while (token != NULL && num_token < my_args - 1) {
                argv[num_token++] = token;
                token = strtok(NULL, " ");
            }
            argv[num_token] = NULL;

            if (num_token == 0)
                continue;
		
	    for (k = 0; k < num_token; k++)

            strcpy(my_path, path);
            strcat(my_path, argv[0]);

            if (access(my_path, X_OK) == -1) {
                printf("Command not found or lack of execute permissions\n");
                continue;
            }

            pid = fork();
            if (pid == -1) {
                perror("fork failed");
                exit(EXIT_FAILURE);
            }

            if (pid == 0) {
                if (execve(my_path, argv, NULL) == -1) {
                    printf("Command not found\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                waitpid(pid, &status, 0);
            }
        } else{
	
		if(!is_interactive)
		{
			break;
		}
                printf("\n");
                break;
        }
    }

    free(command);
    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define my_args 100

void imprimir_prompt() {
    if (isatty(fileno(stdin))) {
        printf("$ ");
        fflush(stdout);
    }
}

int main(void) {
    int num_token, k;
    char *argv[my_args];
    char *command = NULL;
    char *token;
    size_t buffer = 0;
    size_t length;
    char *path = "/bin/";
    char my_path[my_args];
    int status;
    pid_t pid;

    while (1) {
        imprimir_prompt();

        if (getline(&command, &buffer, stdin) != -1) {
            length = strlen(command);
            if (length > 0 && command[length - 1] == '\n') {
                command[length - 1] = '\0';
            }

            if (strcmp(command, "") == 0)
                continue;

            if (strcmp(command, "exit") == 0) {
                free(command);
                return 0;
            }

            num_token = 0;
            token = strtok(command, " ");
            while (token != NULL && num_token < my_args - 1) {
                argv[num_token++] = token;
                token = strtok(NULL, " ");
            }
            argv[num_token] = NULL;

            if (num_token == 0)
                continue;

            for (k = 0; k < num_token; k++) {
                strcpy(my_path, path);
                strcat(my_path, argv[0]);
            }

            if (access(my_path, X_OK) == -1) {
                printf("Command not found or lack of execute permissions\n");
                continue;
            }

            int pipefd[2];
            pipe(pipefd);

            pid = fork();
            if (pid == -1) {
                perror("fork failed");
                exit(EXIT_FAILURE);
            }

            if (pid == 0) {
                close(pipefd[0]);
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[1]);

                if (execve(my_path, argv, NULL) == -1) {
                    printf("Command not found\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                close(pipefd[1]);
                waitpid(pid, &status, 0);

                char buffer[1024];
                ssize_t bytesRead;
                while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
                    write(STDOUT_FILENO, buffer, bytesRead);
                }

                close(pipefd[0]);
            }
        } else {
            printf("\n");
            break;
        }
    }

    free(command);
    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

#define my_args 100

char *_getenv(const char *name) {
    char *result = NULL;
    char *current_var;
    char **env;

    for (env = environ; *env != NULL; env++) {
        current_var = *env;
        if (strncmp(current_var, name, strlen(name)) == 0 && current_var[strlen(name)] == '=') {
            result = malloc(strlen(current_var) - strlen(name) + 1);
            if (result != NULL) {
                strcpy(result, current_var + strlen(name) + 1);
                break;
            }
        }
    }
    return result;
}

666void imprimir_prompt(int interactive) {
    if (interactive) {
        char *dolar = "$";
        printf("%s ", dolar);
        fflush(stdout);
    }
}

int main(void) {
    int num_token, k;
    char *argv[my_args];
    char *command = NULL;
    char *token;
    size_t buffer = 0;
    size_t length;
    char *path[] = {"/usr/local/bin/", "/usr/bin/", "/bin/", "/usr/local/games/", "/usr/games/"};
    char my_path[my_args];
    int status;
    pid_t pid;

    int is_interactive = isatty(fileno(stdin));

    while (1) {
        imprimir_prompt(is_interactive);

        if (getline(&command, &buffer, stdin) != -1) {
            length = strlen(command);

            if (length > 0 && command[length - 1] == '\n')
                command[length - 1] = '\0';

            if (strcmp(command, "") == 0)
                continue;

            if (strcmp(command, "exit") == 0) {
                free(command);
                return 0;
            }

            num_token = 0;
            token = strtok(command, " ");
            while (token != NULL && num_token < my_args - 1) {
                argv[num_token++] = token;
                token = strtok(NULL, " ");
            }
            argv[num_token] = NULL;

            if (num_token == 0)
                continue;

            for (k = 0; k < num_token; k++) {
                printf("%s ", argv[k]);
            }
            printf("\n");

            int command_found = 0;
            for (size_t i = 0; i < sizeof(path) / sizeof(path[0]); i++) {
                strcpy(my_path, path[i]);
                strcat(my_path, argv[0]);

                if (access(my_path, X_OK) == 0) {
                    command_found = 1;
                    break;
                }
            }

            if (!command_found) {
                printf("Command not found or lack of execute permissions\n");
                continue;
            }

            pid = fork();
            if (pid == -1) {
                perror("fork failed");
                exit(EXIT_FAILURE);
            }

            if (pid == 0) {
                if (execve(my_path, argv, environ) == -1) {
                    printf("Command not found\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                waitpid(pid, &status, 0);
            }
        } else{

                if(!is_interactive)
                {
                        break;
                }
                printf("\n");
                break;
        }
    }

    free(command);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

#define my_args 100 /*Define the maximum number of arguments*/

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


void imprimir_prompt(int interactive)
{
	if (interactive)
	{
		char *dolar = "$";
		printf("%s ", dolar);
		/*fflush(stdout);*/
	}
}

int main(void)
{
	int num_token, k;
	size_t i;
	char *argv[my_args]; /*Array to store command arguments*/
	char *command = NULL; /*Input command string*/
	char *token;
	size_t buffer = 0;
	size_t length;
	char *path[] = {"/usr/local/bin/", "/usr/bin/", "/bin/", "/usr/local/games/", "/usr/games/"}; /*Default path for command execution*/
	char my_path[my_args]; /*Store the constructed path for command execution*/
	int status;
	pid_t pid;
	char **env = environ; /*Copy of the environment variables*/
	size_t path_size = sizeof(path) / sizeof(path[0]);

	int interactive = isatty(fileno(stdin));

	while (1)
	{
		imprimir_prompt(interactive);
		if (getline(&command, &buffer, stdin) != -1) /*Read command from user input*/
		{
			length = strlen(command);
			if (command[length - 1] == '\n')
				command[length - 1] = '\0';

			if (strcmp(command, "") == 0) /*Check for empty command*/
				continue;

			if (strcmp(command, "exit") == 0) /*Check for "exit" command to terminate the shell*/
			{
				free(command);
				return 0;
			}

			num_token = 0;
			token = strtok(command, " ");
			while (token != NULL && num_token < my_args - 1) /*Tokenize the command into arguments*/
			{
				argv[num_token++] = token;
				token = strtok(NULL, " ");
			}
			argv[num_token] = NULL;

			if (num_token == 0) /*Check for no arguments provided*/
				continue;

			for (k = 0; k < num_token; k++)
				;

			for (i = 0; i < path_size; i++)
			{
				strcpy(my_path, path[i]); /*Construct the full path for the command*/
				strcat(my_path, argv[0]);

				if (access(my_path, X_OK) == 0) /*Check if the command is executable*/
				{
					break;
				}
			}

			if (access(my_path, X_OK) == -1)
			{
				printf("Command not found1\n");
				continue;
			}
			pid = fork(); /*Fork a new process for command execution*/
			if (pid == -1)
			{
				perror("fork failed");
				exit(EXIT_FAILURE);
			}

			if (pid == 0) /*Child process executes the command*/
			{
				if (execve(my_path, argv, env) == -1)
				{
					printf("command not found\n");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				waitpid(pid, &status, 0); /* Parent process waits for child process to complete */
			}
		}
		else /* If input is not read properly, break the loop */
		{
			if (!interactive) /*Si no es interactivo, no imprimas una nueva línea*/
			{
				break;
			}
			printf("\n"); /* Si es interactivo y la entrada no se lee correctamente, imprime una nueva línea*/
			break;
		}
	}
	free(command);
	return 0;
}
