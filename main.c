#include "shell.h"
/*
 * File: "main.c"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */

/**
 * main -				Starts the shell CLI.
 * @argc:				Number of CLI args (index starts at 1).
 * @argv:				Pointer to the first CLI arg.
 * Return:				0 for success.
 */

int main(int argc, char **argv)
{
	(void)argc;

	return (start_shell(environ, argv[0]));
}
