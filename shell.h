#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int _putchar(char c);
char *pathfinder(char *input);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_getenv(char *name);
int _strncmp(char *str1, char *str2, int n);
char *_strdup(char *string);
int _strcmp(char *s1, char *s2);
int _printenv(void);
int special_chars(char *argv, char *argv1);
void print_cwd(char *cwd);
int childcare(pid_t child_pid, char *exe_token, char **command_array);
void error_print(void);

#endif
