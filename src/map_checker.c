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

int	append_line_to_map(char ***map, char *line, int *h, int *w)
{
	char	**new_map;
	char	*dup_line;

	if (*w == -1)
		*w = ft_strlen(line);
	else if ((int)ft_strlen(line) != *w)
		return (error("Map not rectangular, YOU FOOL!!"), 0);
	new_map = realloc(*map, sizeof(char *) * (*h + 2));
	if (!new_map)
		return (error("Memory allocation failed, YOU FOOL!!"), 0);
	dup_line = ft_strdup(line);
	if (!dup_line)
		return (error("Line duplication failed, YOU FOOL!!"), 0);
	new_map[*h] = dup_line;
	new_map[*h + 1] = NULL;
	*map = new_map;
	(*h)++;
	return (1);
}

int	count_chars(char **map, char target)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == target)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	valid_map(char **map, int *p_out, int *e_out, int *c_out)
{
	int	p;
	int	e;
	int	c;
	int	i;
	int	j;

	p = count_chars(map, 'P');
	e = count_chars(map, 'E');
	c = count_chars(map, 'C');
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
				return (error("Invalid map character, YOU FOOL!!"), 0);
			j++;
		}
		i++;
	}
	*p_out = p;
	*e_out = e;
	*c_out = c;
	return (1);
}

int	validate_loaded_map(char **map, int height, int width)
{
	int	p;
	int	e;
	int	c;

	if (!valid_map(map, &p, &e, &c))
		return (0);
	if (p != 1 || e != 1 || c < 1)
		return (error("Missing P, E, or C in map, YOU FOOL!!!|"), 0);
	if (!check_border(map, height, width))
		return (error("Map not surrounded by walls, YOU FOOL!!"), 0);
	if (!is_path_valid(map, height, width))
		return (error("Invalid path, YOU FOOL!! \n"), 0);
	return (1);
}
