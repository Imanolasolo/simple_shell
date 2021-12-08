#include "shell.h"
/*
 * File: "path_finder.c"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */

int test_path(char *path_with_file);
char *get_correct_path(char *filename, char **paths);

/**
 * get_file_path -		Gets the path to a file from environmental var list
 * @filename:			Filename to find path for.
 * @envp:				Environmental variables to find PATH in with paths
 *						to check.
 * Return:				Pointer to newly malloced array containing correct
 *						path and fname, or (NULL) on failure.
 */

char *get_file_path(char *filename, char **envp)
{
	char **paths = NULL;
	char *path_env = NULL;
	char *_return = NULL;

	if (!filename || !envp)
		return (NULL);

	path_env = _getenv("PATH", envp);
	/* tokenize paths */
	paths = strtow(path_env, PATH_DELIMS);

	if (!paths)
	{
		if (test_path(filename))
			return (filename);
		return (NULL);
	}
	_return = get_correct_path(filename, paths);
	free_token_list(paths);
	return (_return);
}

/**
 * get_correct_path -	Gets the correct path from a list of tokenized dirs.
 * @filename:			Filename to find in list of paths.
 * @paths:				Pointer to an array of pointers that point to the
 *						paths in memory.
 * Return:				Pointer to new filename w/ correct path on success,
 *						or (NULL) failure.
 */

char *get_correct_path(char *filename, char **paths)
{
	char *new_tok = NULL;
	int fname_len = 0, cur_tok_len = 0, new_tok_len = 0;
	int tok_i = 0, new_tok_i = 0, fn_i = 0, path_i = 0;
	int is_file = 0;

	fname_len = _strlen(filename);
						/* loop through our tokens */
	while (paths[tok_i])
	{
		cur_tok_len = _strlen(paths[tok_i]);
		new_tok_len = cur_tok_len + fname_len + 1;
		new_tok = malloc(sizeof(char) * new_tok_len + 1);
		if (!new_tok)
			return (NULL);

						/* create new token by merging and adding '/' */
		new_tok_i = path_i = fn_i = 0;
		while (new_tok_i < new_tok_len)
		{
						/* copy path in */
			if (new_tok_i < cur_tok_len)
				new_tok[new_tok_i] = paths[tok_i][path_i++];
			else if (new_tok_i == cur_tok_len)
				new_tok[new_tok_i] = '/';
			else		/* copy file name in */
				new_tok[new_tok_i] = filename[fn_i++];
			new_tok_i++;
		}
		new_tok[new_tok_i] = '\0';

		is_file = test_path(new_tok);
		if (is_file)	/* succeeded in opening file at path */
			return (new_tok);
		else if (is_file < 0)
		{				/* succeeded in opening, but failed to close. */
			free(new_tok);
			return (NULL);
		}
						/* not a match, clean up and move to next one */
		free(new_tok);
		tok_i++;
	}
						/* didn't find in path, check if file name works */
	if (test_path(filename))
		return (filename);
	return (NULL);		/* didn't find file */
}

/**
 * test_path -			Tests if the path to a file exists or not.
 * @path_with_file:		Path to the file.
 * Return:				1 for succeeded in opening file, also closed it.
 *						or 0 file not found.
 *						-1 opened file but failed to close it.
 */

int test_path(char *path_with_file)
{
	int open_resp = 0;

	open_resp = open(path_with_file, O_RDONLY);
	if (open_resp < 0)
		return (0);
	if (close(open_resp) < 0)
		return (-1);
	return (1);
}
