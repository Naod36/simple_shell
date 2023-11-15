#include "main.h"

/**
 * prmp - prints prompt
 * Return: void
 */
void prmp(void)
{
	char *buffer = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
		prints("$ ");
	free(buffer);
}
