#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

#define my_args 100

char *_getenv(const char *name);
void imprimir_prompt(int interactive);
void execute_order_66(char *my_path, char **argv, char **environ);
int tokenizer(char *command, char **argv);
int i_path(char *command, char **argv, char **path, char *my_path);
int main(void);

#endif /* MAIN_H */
