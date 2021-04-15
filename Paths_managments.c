
#include "shellcito.h"

char *paths_managment(char *s2, char **path_array, int j)
{
    char *aux = NULL, *new_path = NULL;
    int count_path = 0;

    free(new_path);
	aux = strtok(s2, "\n");
	count_path = (_strlen(path_array[j]) + _strlen(aux) + 2);
	new_path = malloc(sizeof(char) * count_path);
	if (new_path == NULL)
		return(NULL);
	_strcpy(new_path, path_array[j]);
	_strcat(new_path, "/");
	_strcat(new_path, aux);
	_strcat(new_path, "\0");

    return(new_path);
}