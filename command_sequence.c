#include "shell.h"
/*
 * File: "command_sequence.c"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */

/**
 * make_sequence	-	Creates the sequence  of nodes.
 * Return:				Address of node.
 */

sequence_t *make_sequence()
{
	sequence_t *seq = malloc(sizeof(sequence_t));

	if (!seq)
		return (NULL);

	seq->head = seq->tail = NULL;
	return (seq);
}

/**
 * insequence -         Adds new node to the head.
 * @seq:				Pointer to sequence.
 * @separator:			Used for character that separates each command.
 * @command:			Points to the first char in the stream.
 * Return:				0 for failure or 1 for success.
 */

int insequence(sequence_t *seq, char separator, char **command)
{
	command_t *new_node = create_command(separator, command);

	if (!new_node)
		return (0);

	if (!seq->tail)
	{
		seq->head = new_node;
		seq->tail = new_node;
		return (1);
	}

	seq->tail->next = new_node;
	seq->tail = new_node;
	return (1);
}

/**
 * disequence	-		Removes the node after executed.
 * @seq:				Pointer to the sequence.
 * Return:				Node that was executed.
 */

command_t *disequence(sequence_t *seq)
{
	command_t *old_node = NULL;

	if (!seq->head)
		return (NULL);

	old_node = seq->head;
	seq->head = seq->head->next;

	if (!seq->head)
		seq->tail = NULL;


	return (old_node);
}
