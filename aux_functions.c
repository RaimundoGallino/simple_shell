#include "shellcito.h"
/**
 * not_empty - checks if the input buffer is empty or not
 *
 * @input_buffer: the input buffer passed to the function
 * Return: 0 if is empty -1 if not
 */

int not_empty(char *input_buffer)
{
	int i = 0;
	int boolean = 0;

	while (input_buffer[i])
	{
		if (input_buffer[i] != ' ')
			break;
		i++;
	}
	if (input_buffer[i] && input_buffer[i] != '\n')
		boolean = -1;

	return (boolean);
}

/**
 * _printenv - prints the enviroments variables
 *
 * @void 
 * Return: 0
 */

int _printenv(void)
{
	char *s = environ[0];
	int i = 0;

	while (s)
	{
		write(1, s, strlen(s));
		write(1, "\n", 1);
		s = environ[++i];
	}
	return (0);
}

/**
 * _strcmp - compare two strings with it respectively ASCII values
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: the concatenated string.
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}

	else
	{
		return (*s1 - *s2);
	}
}

/**
 * _strlen - gets the string lenght.
 * @s: string to check
 * Return: the lenght of the string.
 */

int _strlen(const char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	else
		return (1 + _strlen(s + 1));
}

/**
 * *_strcpy - check the code for Holberton School students.
 * @dest: save the copied string
 * @src: the string to be copied
 * Return: the saved string --> dest
 */

char *_strcpy(char *dest, char *src)
{
	char *saved = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = 0;
	return (saved);
}
