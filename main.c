#include "main.h"

/**
 * _which - identifies the path of the command (fpath)
 * that is being passed to it
 * @fpath: the command that is being passed to it
 *
 * Return: an array of directories containing the command or NULL on failure
 */
char **_which(char *cmd)
{
	int size = 64;
	int i = 0;
	char *copy_path = NULL;
	char *delim = ":=";

	char **dirs =  calloc(sizeof(char *), size);
	char *token = NULL;

	if (cmd == NULL)
	{
		free(cmd);
		return (0);
	}
	if (dirs == NULL)
	{
		free(cmd);
		perror("Error allocated memory");
		return (NULL);
	}
	copy_path = strdup(cmd); /* Copy the fpath string */
	token = strtok(copy_path, delim); /* Split the string by the delimiter */

	while (token != NULL)
	{
		dirs[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	return (dirs);
}
