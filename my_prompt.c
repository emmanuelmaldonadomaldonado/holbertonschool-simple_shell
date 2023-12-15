#include "main.h"

/* Function to print the shell prompt */
void imprimir_prompt(int interactive)
{
	if (interactive)
	{
		char *dolar = "$";
		printf("%s ", dolar);
		fflush(stdout); /* Ensure prompt prints immediately */
	}
}
