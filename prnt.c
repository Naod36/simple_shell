#include "main.h"

/**
 * put_chr - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int put_chr(char c)
{
	return (write(1, &c, 1));
}



/**
 * print_s - Prints a string
 * @str: Pointer to the string to print
 *
 * Return: void
 */
void prints(char *str)
{
	int i = 0;

	while (str[i])
	{
		put_chr(str[i]);
		i++;
	}
}
