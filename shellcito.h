#ifndef SHELLCITO_H
#define SHELLCITO_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include <dirent.h>

extern char **environ;

void *pathfinder(char *cmd);

int reading(char *s);

int not_empty(char *input_buffer);

int execute(char *cmd[]);

char *_getenv(const char *name);

int _setenv(const char *name, const char *value, int overwrite);

int _unsetenv(const char *name);

int _printenv(void);

int _strcmp(char *s1, char *s2);

int _strlen(const char *s);

char *_strcpy(char *dest, char *src);

char *_strcat(char *dest, char *src);

#endif /* SHELLCITO_H */
