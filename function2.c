#include "main.h"

/**
 * *str_copy - copies a string pointed to by src to dest
 * @src: variale where string will be copied from
 * @dest: variable that string will be copied to
 * Return: dest
 */
char *str_copy(char *dest, char *src)
{
	int p;

	for (p = 0; src[p] != '\0'; p++)
	{
		dest[p] = src[p];
	}
	dest[p] = '\0';

	return (dest);
}

/**
 * mem_cpy - copies bytes from src to dest
 *
 * @dest: memory to be transfereed to
 * @src: memory to be transferred from
 * @n: number of bytes to be transfered
 * Return:dest
 */
char *mem_cpy(char *dest, char *src, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++)
	{
		dest[i] = src[i];
		n--;
	}

	return (dest);
}

/**
 * strd_up - copies string and returns its pointer
 *
 * @str: string to be copied
 * Return: String
 */

char *strd_up(char *str)
{
	char *dup;
	unsigned int i, count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		i++;
		count++;
	}
	count++;
	dup = malloc(sizeof(char) * count);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < sizeof(char) * count; i++)
		dup[i] = str[i];

	return (dup);
}
/**
 * str_cmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: integer
 */

int str_cmp(char *s1, char *s2)
{
	int s;

	s = 0;
	while (s1[s] != '\0' && s2[s] != '\0')
	{
		if (s1[s] != s2[s])
			return (s1[s] - s2[s]);

		s++;
	}

	return (0);
}
/**
 * strgconct_ - concatenate two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the concatenated string
 */
char *_strconct(char *s1, char *s2)
{
	char *dest;
	unsigned int i, j, size;


	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";


	size = (strlen(s1) + strlen(s2) + 1);



	dest = (char *) malloc(size * sizeof(char));

	if (dest == 0)
	{
		return (NULL);
	}


	for (i = 0; *(s1 + i) != '\0'; i++)
		*(dest + i) = *(s1 + i);

	for (j = 0; *(s2 + j) != '\0'; j++)
	{
		*(dest + i) = *(s2 + j);
		i++;

	}
	dest[i] = '\0';
	return (dest);

}
