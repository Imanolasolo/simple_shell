#include "shell.h"
/*
 * File: "tokenize_string.h"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */
/**
 * strtow -             Takes a string and seperates its words.
 * @str:                String to seperate into words.
 * @delims:             Delimitors to use to delimit words.
 * Return:              2D array of pointers to each word.
 */
char **strtow(char *str, char *delims)
{
	char **words;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);
	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
			str = get_next_word(str, delims);

		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /* set end of str */
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 * is_delim -           Checks if stream has delimitor char.
 * @ch:                 Character in stream.
 * @delims:             Pointer to null terminated array of delimitors.
 * Return:              1 for success or 0 for failure.
 */

int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length -    Gets the word length of cur word in str.
 * @str:                String to get word length from current word.
 * @delims:             Delimitors to use to delimit words.
 * Return:              Word length of current word.
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * get_word_count -     Gets the word count of a string.
 * @str:                String to get word count from.
 * @delims:             Delimitors to use to delimit words.
 * Return:              The word count of the string.
 */

int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_next_word -      Gets the next word in a string.
 * @str:                String to get next word from.
 * @delims:             Delimitors to use to delimit words.
 * Return:              Pointer to first char of next word.
 */

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int i       = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
