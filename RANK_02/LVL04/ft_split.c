/* Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str); */

#include <stdlib.h>
#include <stdio.h>

int is_delim(char c)
{
	return (c == 32 || c == 9 || c == 10);
}

int ft_count_words(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if (!is_delim(str[i]))
		{
			count++;
			while (str[i] && !is_delim(str[i]))
				i++;
		}
		else
			i++;
	}
	return (count);
}

char **ft_split(char *str)
{
	char **split;
	int i = 0;
	int j = 0;
	int k;
	int len;

	split = malloc(sizeof(char *) * (ft_count_words(str) + 1));
	if (!split)
		return (NULL);
	while (str[i])
	{
		if (!is_delim(str[i]))
		{
			len = 0;
			while (str[i + len] && !is_delim(str[i + len]))
				len++;
			split[j] = malloc(sizeof(char) * (len + 1));
			if (!split[j])
				return (NULL);
			k = 0;
			while (str[i] && !is_delim(str[i]))
				split[j][k++] = str[i++];
			split[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}
