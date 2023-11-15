#include "main.h"

void handle_exit(char **kalat, char *line);

/**
 * splt_str - splits string
 * @line: string to be tokenized
 * @env: environment variables
 *
 * Return: array of tokens
 */
char **splt_str(char *line, char **env)
{
	char *tokenized_sentence, *separator = " \t\r\n\a";
	char **kalat;
	int max_kalat = 64, kotari = 0;

	if (line == NULL)
	{
		return (0);
	}
	kalat =  calloc(sizeof(char *), max_kalat);
	if (kalat == NULL)
	{
		prints("error");
		exit(EXIT_FAILURE);
	}

	tokenized_sentence = strtok(line, separator);
	while (tokenized_sentence != NULL)
	{
		kalat[kotari] = tokenized_sentence;
		kotari++;
		tokenized_sentence = strtok(NULL, separator);
	}

	if (kalat[0] == NULL)
		kalat[kotari] = "\n";

	if (strncmp(kalat[0], "exit", strlen(kalat[0])) == 0)
	{
		if (kalat[1] != NULL)
			handle_exit(kalat, line);

		else
			handle_exit(kalat, line);
	}
	if ((strcmp(kalat[0], "env") == 0) && kalat[1] == NULL)
		_printenv(env);

	return (kalat);

}


/**
 * handle_exit - exit handler
 * @kalat:  kalat which is nice
 * @line: line line in the mirrori
 * Returns: nothing
 *
 */

void handle_exit(char **kalat, char *line)
{
	int status = 0;

	if (kalat[1] != NULL)
	{
		status =  a_toi(kalat[1]);
		if (status == 0 && strcmp(kalat[1], "0") != 0)
			status = 2;
	}

	free(line);
	free(kalat);
	exit(status);
}

/**
 *  a_toi - converts char to int
 * @a: char to be converted
 * Return: int
 */

int  a_toi(char *a)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (a[i] == ' ')
	{
		i++;
	}

	if (a[i] == '-' || a[i] == '+')
	{
		sign = (a[i] == '-') ? -1 : 1;
		i++;
	}

	while (a[i] > '\0' && a[i] <= '9')
	{
		result = result * 10 + (a[i] - '0');
		i++;
	}

	return (result * sign);
}
