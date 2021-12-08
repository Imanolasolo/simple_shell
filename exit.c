#include "shell.h"
/*
 * File: "exit.c"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */

/**
 * exit_shell -			Frees the queue and return exit code.
 * @seq:				Pointer to the sequence.
 * @status:				Exit code to exit with.
 * @his_q:				History queue to free.
 * @environ:			Array of pointers to environmental variables.
 * Return:				See macro values.
 */

void exit_shell(his_q_t *his_q, sequence_t *seq, int status, char **environ)
{
	write_queue_to_file(his_q, environ);

	free_command_sequence(seq);
	free_history_queue(his_q);
	exit(status);
}
