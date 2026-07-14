#include "bsq.h"

static void	free_map(char **map, int rows)
{
	while (rows--)
		free(map[rows]);
	free(map);
}

static int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

static int	parse_header(char *line, t_info *info)
{
	int	i;
	int	rows;

	i = 0;
	rows = 0;
	if (line[i] < '0' || line[i] > '9')
		return (1);
	while (line[i] >= '0' && line[i] <= '9')
		rows = rows * 10 + line[i++] - '0';
	if (rows <= 0)
		return (1);
	info->lines = rows;
	if (line[i++] != ' ' || !line[i])
		return (1);
	info->empty = line[i++];
	if (line[i++] != ' ' || !line[i])
		return (1);
	info->obstacle = line[i++];
	if (line[i++] != ' ' || !line[i])
		return (1);
	info->full = line[i++];
	if (line[i] != '\n' && line[i] != '\0')
		return (1);
	if (!is_printable(info->empty) || !is_printable(info->obstacle)
		|| !is_printable(info->full)
		|| info->empty == info->obstacle
		|| info->empty == info->full
		|| info->obstacle == info->full)
		return (1);
	return (0);
}

static int	read_header(FILE *file, t_info *info)
{
	char	*line;
	size_t	len;
	ssize_t	ret;

	line = NULL;
	len = 0;
	ret = getline(&line, &len, file);
	if (ret <= 0 || line[ret - 1] != '\n' || parse_header(line, info))
		return (free(line), 1);
	free(line);
	return (0);
}

static int	copy_line(t_map *map, char *line, int row, t_info info)
{
	int	col;

	map->tab[row] = malloc(sizeof(char) * (map->w + 1));
	if (!map->tab[row])
		return (1);
	col = -1;
	while (++col < map->w)
	{
		if (line[col] != info.empty && line[col] != info.obstacle)
			return (free(map->tab[row]), 1);
		map->tab[row][col] = line[col];
	}
	map->tab[row][col] = '\0';
	return (0);
}

static int	read_map(FILE *file, t_info info, t_map *map)
{
	char	*line;
	size_t	len;
	ssize_t	ret;
	int		row;

	line = NULL;
	len = 0;
	map->h = info.lines;
	map->w = 0;
	map->tab = malloc(sizeof(char *) * map->h);
	if (!map->tab)
		return (1);
	row = -1;
	while (++row < map->h)
	{
		ret = getline(&line, &len, file);
		if (ret <= 0 || line[ret - 1] != '\n')
			return (free(line), free_map(map->tab, row), 1);
		ret--;
		if (!row)
		{
			map->w = ret;
			if (map->w <= 0)
				return (free(line), free_map(map->tab, row), 1);
		}
		else if (ret != map->w)
			return (free(line), free_map(map->tab, row), 1);
		if (copy_line(map, line, row, info))
			return (free(line), free_map(map->tab, row), 1);
	}
	if (getline(&line, &len, file) != -1)
		return (free(line), free_map(map->tab, map->h), 1);
	free(line);
	return (0);
}

static int	minimum(int top, int left, int diagonal)
{
	int	min;

	min = top;
	if (left < min)
		min = left;
	if (diagonal < min)
		min = diagonal;
	return (min);
}

static void	update_square(t_square *sq, int size, int row, int col)
{
	if (size > sq->size)
	{
		sq->size = size;
		sq->i = row - size + 1;
		sq->j = col - size + 1;
	}
}

static int	find_square(t_map map, t_info info, t_square *sq)
{
	int	*square_sizes;
	int	row;
	int	col;
	int	prev_diag;
	int	old_value;

	square_sizes = calloc(map.w, sizeof(int));
	if (!square_sizes)
		return (1);
	row = -1;
	while (++row < map.h)
	{
		col = -1;
		prev_diag = 0;
		while (++col < map.w)
		{
			old_value = square_sizes[col];
			if (map.tab[row][col] == info.obstacle)
				square_sizes[col] = 0;
			else if (!row || !col)
				square_sizes[col] = 1;
			else
				square_sizes[col] = minimum(square_sizes[col],
						square_sizes[col - 1], prev_diag) + 1;
			update_square(sq, square_sizes[col], row, col);
			prev_diag = old_value;
		}
	}
	free(square_sizes);
	return (0);
}

static void	print_result(t_map map, t_info info, t_square sq)
{
	int	row;
	int	col;

	row = sq.i - 1;
	while (++row < sq.i + sq.size)
	{
		col = sq.j - 1;
		while (++col < sq.j + sq.size)
			map.tab[row][col] = info.full;
	}
	row = -1;
	while (++row < map.h)
		fprintf(stdout, "%s\n", map.tab[row]);
}

int	bsq(FILE *file)
{
	t_info		info;
	t_map		map;
	t_square	sq;

	sq.size = 0;
	sq.i = 0;
	sq.j = 0;
	if (read_header(file, &info) || read_map(file, info, &map))
		return (1);
	if (find_square(map, info, &sq))
		return (free_map(map.tab, map.h), 1);
	print_result(map, info, sq);
	free_map(map.tab, map.h);
	return (0);
}

int	main(int ac, char **av)
{
	FILE	*file;
	int		arg;

	if (ac == 1)
	{
		if (bsq(stdin))
			fprintf(stderr, "map error\n");
		return (0);
	}
	arg = 0;
	while (++arg < ac)
	{
		file = fopen(av[arg], "r");
		if (!file || bsq(file))
			fprintf(stderr, "map error\n");
		if (file)
			fclose(file);
		if (arg < ac - 1)
			fprintf(stdout, "\n");
	}
	return (0);
}
