/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 00:42:00 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/07/14 10:32:29 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define _POSIX_C_SOURCE 200809L

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>

typedef struct s_info
{
	int		lines;
	char	empty;
	char	obstacle;
	char	full;
}	t_info;

typedef struct s_map
{
	char	**tab;
	int		h;
	int		w;
}	t_map;

typedef struct s_square
{
	int	size;
	int	i;
	int	j;
}	t_square;

int	bsq(FILE *file);

#endif
