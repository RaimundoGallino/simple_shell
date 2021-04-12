#include "shellcito.h"

int main(int argc, char *argv[] __attribute__((unused)))
{
	size_t buffer = 0;
	char *string = NULL;
	ssize_t line = 0;

	(void) argc;
	signal(SIGINT, SIG_IGN);

	while (1)
	{
		RESET;
		if (isatty(STDIN_FILENO) == 1)
			write(1, ":$hellcito ", 11);

		line = getline(&string, &buffer, stdin);
		if (*string == '\0')
			continue;

		if (line == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}
		else if (not_empty(string) == -1)
		{
			reading(strtok(string, "\n"));
		}

	}
	return (0);
}

int reading(char *s)
{
	char *token = NULL;
	char *command_arr[100];
	int i = 0;

	token = strtok(s, " ");

	if (_strcmp(s, "exit") == 0)
	{
		free(s);
		exit(2);	
	}

	if (_strcmp(s, "env") == 0)
	{
		return(_printenv());
	}
	
	while (token)
	{
		command_arr[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	command_arr[i] = NULL;
	return (execute(command_arr));
}

int execute(char *cmd[])
{
	char *path = NULL;
	pid_t child;
	char *command = NULL;
	int status;
	const char *dir = cmd[1];

	command = cmd[0];
	if (_strcmp(command, "cd") == 0)
	{
		if (dir == NULL)
			return(chdir(_getenv("HOME")));
		if (chdir(dir) != 0)
			perror(dir);
		else
			return(chdir(dir));
	}

	path = pathfinder(command);

	if (path == NULL && _strcmp(command, "cd") != 0)
	{
		write (2, command, _strlen(command));
		write(2, ": command not found\n", 20);
		return (0);
	}

	child = fork();

	if (child != 0)
		wait(&status);

	else if (child == 0 && _strcmp(command, "cd") != 0)
	{
		execve(path, cmd, environ);
		perror("Error:");
		exit(1);
	}
	free(path);

	return (0);
}