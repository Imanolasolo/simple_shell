#include "shell.h"
/*
 * File: "signal_handler.c"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */

void signal_handler(int sig_num);

/**
 * register_signal_handlers - registers signal handlers for kernel.
 * Return:                    1 for succes or -1 for failure.
 */
int register_signal_handlers(void)
{
	if (signal(SIGINT, signal_handler) == SIG_ERR)
	{
		print_signal_reg_error();
		return (-1);
	}
	/* register more signals if needed */
	return (1);
}

/**
 * signal_handler -           Prevents CTRL-C EOD from interrupting shell.
 * @sig_num:                  Signal number.
 * Return:                    Void.
 */

void signal_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		print_newline();
		print_prompt();
	}
}
