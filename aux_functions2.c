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

int count_spaces( char *string)
{
    int len = _strlen(string);
    int i = 0;
    int count = 0;

    for (; i < len; i++)
    {
        if (string[i] == ' ' && string[i + 1])
            count += 1;
    }
    return(count);
}