#include "shell.h"
/*
 * File: "std_funcs.c"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */

/**
 * _atoi -              Converts string to integer.
 * @s:                  String to convert from.
 * Return:              Integer from conversion.
 */
int _atoi(char *s)
{
	int          sign    = 1;
	unsigned int total   = 0;
	char         working = 0;

	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '-')
			sign = sign * -1;
		if (*s >= '0' && *s <= '9')
		{
			working = 1;
			total   = total * 10 + *s - '0';
		}
		else if (*s < '0' || *s > '9')
		{
			if (working)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-(total));
	return (total);
}

/**
 * _strlen -            Gets the length of a null byte terminated string.
 * @str:                String to check length of.
 * Return:              Length of string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}
