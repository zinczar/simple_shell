#include "shell.h"

/**
 * main - Simple Shell
 *
 * Return: 0
 */

int main(void)
{	int i, status = 0, count = 0;
	char *buffer = NULL;
	char *command_token = NULL, *command_array[100], *exe_token = NULL;
	size_t bufsize = 32;
	pid_t child_pid;
	char cwd[1024];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDIN_FILENO, "ᕙ(⇀‸↼‶)ᕗ  ", 21);
			getcwd(cwd, sizeof(cwd));
			print_cwd(cwd);
		}
		if (getline(&buffer, &bufsize, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 2);
			break;
		}
		if (buffer[_strlen(buffer) - 1] == '\n')
			buffer[_strlen(buffer) - 1] = '\0';
		command_token = strtok(buffer, " ");
		if (command_token == NULL)
			continue;
		i = 0;
		while (command_token != NULL)
		{
			command_array[i++] = command_token;
			command_token = strtok(NULL, " ");
		}
		command_array[i] = NULL;
		count++;
		if (special_chars(command_array[0], command_array[1]) == 0)
			continue;
		child_pid = fork();
		if (childcare(child_pid, exe_token, command_array) > 0)
			waitpid(child_pid, &status, WUNTRACED);
	}
	free(buffer);
	buffer = NULL;
	return (0);
}
