/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:32:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/07/14 10:32:09 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int putchar(int c);

static void draw_input(char *board, int w, int h)
{
	int x = 0;
	int y = 0;
	int pen = 0;
	char c;

	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			pen = !pen;
		else if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < h - 1)
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x < w - 1)
			x++;
		if (pen)
			board[y * w + x] = 1;
	}
}

static int	count_neighbors(char *board, int w, int h, int x, int y)
{
	int	count;
	int	dx;
	int	dy;
	int	nx;
	int	ny;

	count = 0;
	dy = -2;
	while (++dy <= 1)
	{
		dx = -2;
		while (++dx <= 1)
		{
			nx = x + dx;
			ny = y + dy;
			if ((dx || dy) && nx >= 0 && nx < w && ny >= 0 && ny < h)
				count += board[ny * w + nx];
		}
	}
	return (count);
}

static void	step(char *board, char *next, int w, int h)
{
	int	x;
	int	y;
	int	n;
	int	pos;

	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
		{
			pos = y * w + x;
			n = count_neighbors(board, w, h, x, y);
			if (board[pos] && (n == 2 || n == 3))
				next[pos] = 1;
			else if (!board[pos] && n == 3)
				next[pos] = 1;
			else
				next[pos] = 0;
		}
	}
}

static void print_board(char *board, int w, int h)
{
	int x;
	int y;

	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
		{
			if (board[y * w + x])
				putchar('O');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

int main(int ac, char **av)
{
	int w = atoi(av[1]);
	int h = atoi(av[2]);
	int iterations = atoi(av[3]);
	char *board;
	char *next;
	char *tmp;

	if (ac != 4)
		return (1);
	if (w <= 0 || h <= 0 || iterations < 0)
		return (1);
	board = calloc(w * h, 1);
	next = calloc(w * h, 1);
	if (!board || !next)
		return (free(board), free(next), 1);
	draw_input(board, w, h);
	while (iterations-- > 0)
	{
		step(board, next, w, h);
		tmp = board;
		board = next;
		next = tmp;
	}
	print_board(board, w, h);
	free(board);
	free(next);
	return (0);
}
