#include "shell.h"
/*
 * File: "history_queue.c"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */

/**
 * get_history -		Checks if there is a history file present, pulls from that
 *						or creates a new queue if no file is found.
 * Return:				Pointer to new queue in memory.
 */

his_q_t *get_history()
{
	/* check if history file exists, if it does read / build q from it */
	/* else */
	return (create_h_queue());
}

/**
 * create_h_queue -		Creates the queue of nodes.
 * Return:				Address of node.
 */

his_q_t *create_h_queue()
{
	his_q_t *seq = malloc(sizeof(his_q_t));

	if (!seq)
		return (NULL);

	seq->head = seq->tail = NULL;
	return (seq);
}

/**
 * h_enqueue -			Adds new node to the head.
 * @seq:				Pointer to sequence.
 * @command:			Points to the first char in the stream.
 * Return:				0 for failure or 1 success.
 */

int h_enqueue(his_q_t *seq, char *command)
{
	int p_no = 0;

	history_t *new_node;

	if (seq->tail)
		p_no = seq->tail->priority_number + 1;

	new_node = create_history_t(command, p_no);
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
 * h_dequeue -			Removes the node after executed.
 * @seq:				Pointer to the history sequence.
 * Return:				Node that was removed.
 */

history_t *h_dequeue(his_q_t *seq)
{
	history_t *old_node = NULL;

	if (!seq->head)
		return (NULL);

	old_node = seq->head;
	seq->head = seq->head->next;

	if (!seq->head)
		seq->tail = NULL;

	return (old_node);
}

/**
 * write_h_queue -		Writes the input node to a file descriptor.
 * @seq:					Pointer to the sequence.
 * @fd:					File descriptor.
 * Description:			4 bytes = \t + 2 spaces + \n
 *						3 bytes = \t + 2 spaces.
 * Return:				none.
 */

void write_h_queue(his_q_t *seq, int fd)
{
	int s_command = 0, s_number = 0, total = 0, i, j, k, s_i = 0;
	char *priority_n_s = NULL, *node_buffer = NULL;
	history_t *temp = NULL;

	if (!seq)
		return;
	temp = seq->head;
	while (temp)
	{
		priority_n_s = get_int(temp->priority_number);
		if (!priority_n_s)
			return;
		s_number = _strlen(priority_n_s);
		s_command = _strlen(temp->command);
		total = s_number + s_command + 4;
		s_i = s_number + 3;
		node_buffer = malloc(sizeof(char) * total);
		if (!node_buffer)
			return;
		i = j = k = 0;
		while (i < total)
		{
			if (i == 0)
				node_buffer[i] = '\t';
			else if (i < s_number + 1)
				node_buffer[i] = priority_n_s[j++];
			else if (i < s_i)
				node_buffer[i] = ' ';
			else if (i < total - 1)
				node_buffer[i] = temp->command[k++];
			else
				node_buffer[i] = '\n';
			i++;
		}
		free(priority_n_s); /* total - 1: forget \0 */
		write(fd, node_buffer, total - 1);
		free(node_buffer);
		temp = temp->next;
	}
}
