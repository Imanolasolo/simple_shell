#include "shell.h"
/*
 * File: "realloc.c"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */

/**
 * *_realloc -			Reallocates memory block and copies old->new
 * @ptr:				Points to old memory.
 * @old_size:			Size in bytes of old memory.
 * @new_size:			Size in bytes of new memory.
 * Return:				Pointer to new memory @new.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *temp;
	unsigned int i;

	if (ptr == NULL)
	{
		ptr = malloc(new_size);

		if (ptr == NULL)
			return (NULL);

		return (ptr);
	}

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);

	if (new == NULL)
		return (NULL);

	old_size = (new_size < old_size) ? new_size : old_size;

	temp = ptr;

	for (i = 0; i < old_size; i++)
	{
		*(new + i) = *(temp + i);
	}
	free(ptr);

	return (new);
}
