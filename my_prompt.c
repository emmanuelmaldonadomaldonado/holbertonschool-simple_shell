#include "main.h"
/**
 * imprimir_prompt - Function to print the shell prompt
 * @interactive: variable to enter interactive mode
 */
void imprimir_prompt(int interactive)
{
	if (interactive)
	{
		char *dolar = "$";

		printf("%s ", dolar);
		fflush(stdout); /* Ensure prompt prints immediately */
	}
}
