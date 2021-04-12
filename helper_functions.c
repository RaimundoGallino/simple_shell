#include "shellcito.h"

/**
 * _getenv - gets the enviroment variable sepcified by the name.
 * @name: name of the variable to get access
 * Return: Always 0.
 */

char *_getenv(const char *name)
{
	char **envPtr;/* pointer into list of environ. vars. */
	char *charPtr;/* point into one environment variable */
	const char *namePtr;/* pointer into name */

	for (envPtr = environ; *envPtr != NULL; envPtr++) {
		for (charPtr = *envPtr, namePtr = name; *charPtr == *namePtr; charPtr++, namePtr++) {
			if (*charPtr == '=') {
				break;
			}
		}
		if ((*charPtr == '=') && (*namePtr == 0)) {
			return charPtr+1;
		}
	}
	return(0);
}

/**
 * _strdup - copies a string to a new memory location
 * @str: the size of the memory to print
 *
 * Return: Nothing.
 */
char *_strdup(char *str)
{
	char *str2;
	unsigned int i, n;

	if (str == NULL)
		return (NULL);

	n = _strlen(str) + 1;

	str2 = malloc(sizeof(char) * n);

	if (str2 == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
		str2[i] = str[i];

	return (str2);
}

/**
 * _strcat - conctatenates two strings.
 *
 * @dest: first string to concatenate
 * @src: string to concatenate after the first one
 * Return: the concatenated string.
 */

char *_strcat(char *dest, char *src)
{
	int i, j, output = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
		output += 1;
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[output + j] = src[j];
	}
	dest[output + j] = '\0';
	return (dest);
}

/**
 * pathfinder - gets the the path to the executable
 * file of the command passed.
 * @cmd: command passed
 * Return: Always 0.ß
 */
void *pathfinder(char *cmd)
{
	char *path = _strdup(_getenv("PATH"));
	int i = 0, j = 0;
	char *path_tok;
	char *path_array[100];
	char *s2 = cmd;
	char *aux = NULL;
	char *new_path = NULL;
	struct stat buf;

	path_tok = strtok(path, ":");

	new_path = malloc(sizeof(char) * 100);

	if (_getenv("PATH")[0] == ':')
		if (stat(cmd, &buf) == 0)
			return (_strdup(cmd));

	if (stat(cmd, &buf) == 0)
		return (_strdup(cmd));

	while (path_tok != NULL)
	{
		path_array[i++] = path_tok;
		path_tok = strtok(NULL, ":");
	}

	path_array[i] = '\0';

	for (j = 0; path_array[j];)
	{
		aux = strtok(s2, "\n");
		_strcpy(new_path, path_array[j]);
		_strcat(new_path, "/");
		_strcat(new_path, aux);
		_strcat(new_path, "\0");

		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}
		else
			new_path[0] = 0;
		j++;
	}
	free(path);
	free(new_path);
	return(0);
}