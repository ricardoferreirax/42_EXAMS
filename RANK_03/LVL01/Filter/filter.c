/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:23:06 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/07/14 10:08:13 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filter.h"

int	main(int ac, char **av)
{
	int i;
	int rd;
	int len;
	int size;
	char *filter;
	char *line;
	char *new_line;

	if (ac != 2 || !av[1][0])
	{
		fprintf(stderr, "Error: %m\n");
		return (1);
	}
	i = 0;
	rd = 1;
	len = strlen(av[1]);
	size = 2;
	line = calloc(size, sizeof(char));
	if (!line)
	{
		fprintf(stderr, "Error: %m\n");
		return (1);
	}
	while (rd)
	{
		rd = read(0, &line[i++], 1);
		if (rd == -1)
		{
			fprintf(stderr, "Error: %m\n");
			return (free(line), 1);
		}
		if (rd > 0)
		{
			new_line = realloc(line, ++size);
			if (!new_line)
			{
				fprintf(stderr, "Error: %m\n");
				return (free(line), 1);
			}
			line = new_line;
		}
	}
	filter = memmem(line, strlen(line), av[1], len);
	while (filter)
	{
		i = 0;
		while (i++ < len)
			*filter++ = '*';
		filter = memmem(filter, strlen(filter), av[1], len);
	}
	printf("%s", line);
	return (free(line), 0);
}
