#include "shell.h"

/**
 * pathfinder - Tokenizes PATH and matches with command
 * @input: CLI argument
 *
 * Return: Concatinated PATH on success or input on failure
 */

char *pathfinder(char *input)
{
	size_t i = 0, j = 0, k = 0;
	char *test_path = _strdup(_getenv("PATH="));
	char *path_token = strtok(test_path, ":");
	char *token_array[100];
	char *concat_token = NULL;

	concat_token = malloc(sizeof(char) * 100);

	while (path_token != NULL)
	{
		token_array[i++] = path_token;
		path_token = strtok(NULL, ":");
	}
	token_array[i] = NULL;

	while (token_array[j])
	{
		_strcpy(concat_token, token_array[j]);
		_strcat(concat_token, "/");
		_strcat(concat_token, input);
		j++;
		if (access(concat_token, F_OK) == 0)
			return (concat_token);
	}

	while (token_array[k])
		free(token_array[k++]);

	free(concat_token);

	return (input);
}
