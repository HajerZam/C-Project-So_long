/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:28:02 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/16 11:28:02 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

int	check_border(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int append_line_to_map(char ***map, char *line, int *height, int *width)
{
	char	**new_map;
	char	*dup_line;

	if (*width == -1)
		*width = ft_strlen(line);
	else if ((int)ft_strlen(line) != *width)
		return (perror("Map not rectangular"), 0);

	new_map = realloc(*map, sizeof(char *) * (*height + 2));
	if (!new_map)
		return (perror("Memory allocation failed"), 0);
	dup_line = ft_strdup(line);
	if (!dup_line)
		return (perror("Line duplication failed"), 0);

	new_map[*height] = dup_line;
	new_map[*height + 1] = NULL;
	*map = new_map;
	(*height)++;
	return (1);
}

int	valid_map(char **map, int *p_out, int *e_out, int *c_out)
{
	int	i = 0;
	int	p = 0;
	int	e = 0;
	int	c = 0;
	int	j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
				return (perror("Invalid map character"), 0);
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	*p_out = p;
	*e_out = e;
	*c_out = c;
	return (1);
}

int	check_map(char *file, char ***out_map, int *out_height, int *out_width)
{
	int		fd;
	char	**map;
	int		width;
	int		height;
	int		p, e, c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 0);
	else if (!read_map_lines(fd, &map, &width, &height))
		return (close(fd), 0);
	close(fd);
	if (!valid_map(map, &p, &e, &c))
		return (0);
	else if (p != 1 || e != 1 || c < 1)
		return (perror("Missing P, E, or C in map"), 0);
	else if (!check_border(map, height, width))
		return (perror("Map not surrounded by walls"), 0);
	else if (!is_path_valid(map, height, width))
		return (ft_putstr_fd("Error\nInvalid path\n", 2), 0);
	*out_map = map;
	*out_height = height;
	*out_width = width;
	return (1);
}
