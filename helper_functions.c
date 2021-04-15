#include "shellcito.h"

/**
 * stop_ctrl - Stops ctrl+c from doing its thing.
 * @s: string to be called. Rendered null and cast into the V O I D.
 * Return: V O I D
 */

void stop_ctrl(int s)
{
	(void)s;

	signal(SIGINT, stop_ctrl);
	write(1, "\n", 1);
	write(1, ":$hellcito ", 11);
}

/**
 * _getenv - gets the enviroment variable sepcified by the name.
 * @n: name of the variable to get access
 * Return: Always 0.
 */

char *_getenv(const char *n)
{
	char **ePtr;/* pointer into list of environ. vars. */
	char *cPtr;/* point into one environment variable */
	const char *nPtr;/* pointer into name */

	for (ePtr = environ; *ePtr != NULL; ePtr++)
	{
		for (cPtr = *ePtr, nPtr = n; *cPtr == *nPtr; cPtr++, nPtr++)
		{
			if (*cPtr == '=')
			{
				break;
			}
		}
		if ((*cPtr == '=') && (*nPtr == 0))
		{
			return (cPtr + 1);
		}
	}
	return (0);
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
	int i = 0, j = 0, count = count_paths(path), count_path = 0;
	char *path_tok, **path_array, *s2 = cmd, *aux = NULL, *new_path = NULL;
	char *return_path = NULL;
	struct stat buf;

	path_array = malloc(sizeof(char *) * (count + 1));
	if (path_array == NULL)
		return(NULL);
		
	path_tok = strtok(path, ":");
	if (_getenv("PATH")[0] == ':')
	{
		if (stat(cmd, &buf) == 0)
		{
			free(path_array);
			free(path);
			return (_strdup(cmd));
		}
	}
	if (stat(cmd, &buf) == 0)
	{
		free(path_array);
		free(path);
		return (_strdup(cmd));
	}
	while (path_tok != NULL)
	{
		path_array[i++] = path_tok;
		path_tok = strtok(NULL, ":");
	}
	path_array[i] = '\0';
	for (j = 0; path_array[j];)
	{
		return_path = paths_managment(s2, path_array, j);
		
		if (stat(return_path, &buf) == 0)
		{
			free(path);
			free(path_array);
			return (return_path);
		}
		else
			new_path[0] = 0;
		j++;
	}
	while (i < count)
		free(path_array[i++]);
	free(path_array);
	free(path);
	free(return_path);
	return (0);
}