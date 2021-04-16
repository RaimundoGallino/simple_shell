#include "shellcito.h"

/**
 * changing_tab - changes tabs for spaces
 * @string: input string passed
 * Return: 0
 */

void changing_tab(char *string)
{
	int len = _strlen(string);
	int i = 0;

	for (; i < len; i++)
	{
		if (string[i] == '\t')
			string[i] = ' ';
	}
}

/**
 * count_spaces - count spaces
 * @string: input string passed
 * Return: count
 */

int count_spaces(char *string)
{
	int len = _strlen(string);
	int i = 0;
	int count = 1;

	for (; i < len; i++)
	{
		if (string[i] == ' ' && string[i + 1] != ' ' && string[i + 1] != '\n')
			count += 1;
	}
	return (count);
}

/**
 * count_paths - count spaces
 * @string: input string passed
 * Return: count + 1
 */

int count_paths(char *string)
{
	int len = _strlen(string);
	int i = 0;
	int count = 0;

	for (; i < len; i++)
	{
		if (string[i] == ':')
			count += 1;
	}
	return (count + 1);
}

/**
 * count_spaces - count spaces
 * @buffer: input string passed
 * Return: count + 1
 */

char *clean_spaces(char *buffer)
{
	int len, first_char_position, i = 0;
	char *new_buffer, *true_buffer;

	new_buffer = _strdup(buffer);
	if (new_buffer[0] != ' ')
		return (new_buffer);
	while (new_buffer[i] == ' ')
		i++;
	first_char_position = i;
	while (new_buffer[i])
		i++;
	len = i - first_char_position;
	true_buffer = malloc(sizeof(char) * (len + 1));
	i = first_char_position;
	while (new_buffer[i])
	{
		true_buffer[i - first_char_position] = new_buffer[i];
		i++;
	}
	true_buffer[i - first_char_position] = '\0';
	free(new_buffer);
	return (true_buffer);
}

/**
 * parent_wait - count spaces
 * @child_pid: child id number
 * @status: int status of the process
 * Return: 0 if it fails 1 if not
 */

int parent_wait(int child_pid, int *status)
{
	if (waitpid(child_pid, status, 0) == -1)
	{
		perror("Waitpid failed");
		return (0);
	}
	if (WIFEXITED(*status))
	{
		return (WEXITSTATUS(*status));
	}
	return (1);
}
