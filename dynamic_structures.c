#include "shell.h"
/*
 * File: "dynamic_structs.c"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */

/**
 * create_command -		Creates space for command structure containing
 *						data passed.
 * @command:			Array of pointers to tokens used in command including
 *						command itself.
 * @separator:			The character separator, either
 *						';', '|', '&', or '\0'(none).
 * Return:				Pointer to the newly allocated command.
 */

command_t *create_command(char separator, char **command)
{
	command_t *_return;

	_return = malloc(sizeof(command_t));
	if (!_return)
		return (NULL);
	_return->separator = separator;
	_return->command = command;
	_return->prev_valid = 1; /* default validity of previous command is true */
	_return->next = NULL;
	return (_return);
}

/**
 * free_command_sequence - Frees a sequence_t of command_t's.
 * @seq:				Pointer to our sequence containing commands.
 * Return:				Always void.
 */

void free_command_sequence(sequence_t *seq)
{
	command_t *temp = NULL;

	if (!seq)
		return;
	temp = seq->head;
	while (temp)
	{
		free_command(temp);
		temp = temp->next;
	}
	seq->head = seq->tail = NULL;
	free(seq);
}

/**
 * free_token_list -	Frees an array of tokens previously malloced.
 * @tokens:				2D array of tokens.
 * Return:				Always void.
 */

void free_token_list(char **tokens)
{
	int i = 0;

	if (!tokens)
		return;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/**
 * free_command -		Frees a command pointer of its token list and itself.
 * @command:			Command to free.
 * Return:				Always void.
 */
void free_command(command_t *command)
{
	if (command)
	{
		free_token_list(command->command);
		free(command);
	}
}
