#include "main.h"

/**
 * main - Simple Shell main function. Creates a prompt that reads input,
 *            parses it, executes commands,
 * and waits for another command unless told to exit.
 * @ac: The number of arguments passed to the program.
 * @av: An array of arguments passed to the program.
 * @env: The environment variables.
 * Return: 0 upon successful execution.
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line;
	char **args, **path;
	int kotari = 0, huneta = 0;
	(void) av;
	signal(SIGINT, hdl_sig);

	for (;;)
	{
		prmp();
		line = _readinput();
		args = splt_str(line, env);
		if ((strncmp(args[0], "\n", 1) != 0) && (strcmp(args[0], "env") != 0))
		{
			kotari += 1;
			path = _search(env);
			huneta = stat_(args, path);
			execmd_(av, args, env, huneta, kotari);
		}
		else
		{
			free(args);
		}
		free(line);
	}
	return (0);
}

