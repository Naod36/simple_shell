#include "main.h"

/**
 * execmd_ - executes a command as a child process
 * @av: array of arguments
 * @args: array of parsed arguments
 * @env: environment variables
 * @ymh: status of the main function
 * @kotari: command count
 *
 * Return: 1 on success
 */

int execmd_(char **av, char **args, char **env, int ymh, int kotari)
{
	pid_t pid;
	int status;

	if (args == NULL)
		return (-1);

	pid = fork();
	if (pid  < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
		        err_or(av[0], kotari, args[0]);
			free(args);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (ymh == 1)
			free(args[0]);

		free(args);
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
