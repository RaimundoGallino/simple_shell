#include "shellcito.h"

/**
 * main - main function of shell program.
 * @argc: int saving arguments
 * @argv: char storing arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	size_t buffer = 0;
	char *string = NULL;
	ssize_t line = 0;
	(void) argc;

	signal(SIGINT, stop_ctrl);

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, ":$hellcito ", 11);

		line = getline(&string, &buffer, stdin);

		if (line == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
				
			free(string);
			break;
		}
		changing_tab(string);
		
		if (*string == '\0')
			continue;

		if (not_empty(string) == -1)
		{
			reading(strtok(string, "\n"), argv[0]);
		}
	}
	return (0);
}

/**
 * reading - parser whatever you just wrote on the shell
 * @s: statement to be read
 * @shellname: name of the shell (previously declared on struct)
 * Return: 0.
 */

int reading(char *s, char *shellname)
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
		return (_printenv());
	}

	while (token)
	{
		command_arr[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	command_arr[i] = NULL;
	return (execute(command_arr, shellname));
}

/**
 * execute - Runs function
 * @cmd: command to be ran.
 * @shellname: name of the shell (previously declared on struct)
 * Return: 0
 */

int execute(char *cmd[], char *shellname)
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
			return (chdir(_getenv("HOME")));
		if (chdir(dir) != 0)
		{
			perror(dir);
			return (1);
		}
		else
			return (chdir(dir));
	}
	path = pathfinder(command);
	if (path == NULL && _strcmp(command, "cd") != 0)
	{
		write(2, shellname, _strlen(shellname));
		write(2, " :1 ", 5);
		write(2, command, _strlen(command));
		write(2, ": not found\n", 12);
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
