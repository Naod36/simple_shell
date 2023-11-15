#include "main.h"

/**
 *call_oc -allocated memoria for nmeb elemn de zise bytes
 *@nmemb: number of element in the array
 *@size: bytes for each position in the array
 *Return: pointer void
 */


void *call_oc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		p[i] = 0;

	return (p);

}
/**
 * str_len - returns a string
 * @s: integer to be used
 * Return: length of string
 */
int str_len(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return ((i + 1));
}

/**
 *_puts - prints a string
 *@str: A to be printed
 *
 *Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0 ; str[i] != '\0' ; i++)
	{
		  putchar(str[i]);
	}
	  putchar('\n');
}

/**
 * _search - gets the path to execute commands
 * @environ: Environment variable
 * Return: kalat_path (array of directories containing the command)
 *	or NULL on failure
 **/
char **_search(char **environ)
{
	int position = 0;
	char **kalat_path;

	for (; environ[position] != NULL ; position++)
	{
		if (environ[position][0] == 'P' && environ[position][2] == 'T')
		{
			kalat_path = _which(environ[position]);
		}
	}
	return (kalat_path);
}

/**
 * i_toa - converts an integer to ASCII
 * @num: number
 * @base: base
 * reference: geeksforgeeks
 * Return: character string
 **/
char *i_toa(int num, int base)
{
	static char *digits = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = (unsigned long)num;

	if (num < 0)
	{
		n = (unsigned long)(-num);
		sign = '-';
	}

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = digits[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}
