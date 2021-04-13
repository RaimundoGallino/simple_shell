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
