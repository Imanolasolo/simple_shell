#include "shell.h"
/*
 * File: "env.c"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */

/**
 * print_env -			Stores and prints the `env`.
 * @envp:               Double pointer to tokens.
 * Return:				0 for failure or 1 for success.
 */

int print_env(char *envp[])
{
	int i, j, char_counter, buff_index, check_write;

	char *buffer;

	i = j = char_counter = buff_index = check_write = 0;


	if (!envp)
		return (0);

	while (envp[i])
	{
		j = _strlen(envp[i]);

		char_counter += j + 1;
		i++;
	}

	buffer = malloc(sizeof(char) * char_counter + 1);
	if (!buffer)
		return (0);

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
			buffer[buff_index++] = envp[i][j++];

		buffer[buff_index++] = '\n';
		i++;
	}

	check_write = write(STDOUT_FILENO, buffer, char_counter);
	free(buffer);
	if (check_write < 0)
		return (0);

	return (1);
}

/**
 * _getenv -			Gets an environmental variable by name.
 * @env_name:			Name of environmental variable to find,
 *						e.g:'PATH', 'HOME', 'USER'.
 * @environ:			Array of pointers to environmental variables.
 * Return:				Pointer to char after equal sign in env,
 *						e.g: PATH= ->/bin:/usr/bin
 */

char *_getenv(char *env_name, char **environ)
{
	char *_return = NULL;
	int i = 0;

	if (!environ)
		return (NULL);
	while (*environ[i])
	{
		if (is_name_env(environ[i], env_name))
		{
			_return = environ[i];
			break;
		}
		i++;
	}
	/* advance pointer to after ENV=env_var */
	/*                              ^       */
	if (_return)
		advance_env(&_return);

	return (_return);
}

/**
 * is_name_env -		Checks if a token begins with PATH=
 * @token:				Token to check.
 * @env_name:			Name of environmental variable, e.g:'PATH','HOME', etc.
 * Return:				1 is path environmental variables, 0 is not path env.
 */

int is_name_env(char *token, char *env_name)
{
	int tok_i = 0, path_i = 0;

	if (!token)
		return (0);
	while (token[tok_i] && env_name[path_i])
	{
		if (token[tok_i++] != env_name[path_i++])
			return (0);
	}
	if (tok_i > 1)
		return (1);
	return (0);
}

/**
 * advance_env -		Takes a pointer to environmental variable and advances
 *						to the character beyond the equal sign.
 * @path_env:			Pointer to the pointer to path token.
 * Return:				Always void.
 */

void advance_env(char **path_env)
{
	char *token = NULL;

	if (!path_env)
		return;
	token = *path_env;
	while (*token != '=')
		token++;
	token++; /* set to character beyond equal sign */
	*path_env = token;
}
