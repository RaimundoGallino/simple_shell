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
	const char *path = "PATH";
	char *value, *tok;
	char *dir[8];
	struct stat statbuff;
	int num = 0;

	value = _getenv(path);
	tok = strtok(value, TOK_DELIM);
	do{
		dir[num] = NULL;
		dir[num] = _strdup(tok);
		dir[num] = strcat(dir[num], cmd);
		if (cmd[0] == '/')
			break;
		if (_strcmp(cmd, "./") == 0)
			break;
		if (stat(dir[num], &statbuff) == 0)
		{
			free(value);
			return(dir[num]);
		}
		else
			num++;
		tok = strtok(NULL, TOK_DELIM);
	} while (tok != NULL);
	free (dir[num]);
	free (value);
	return (cmd);
}