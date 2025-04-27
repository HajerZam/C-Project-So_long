/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:18:25 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/24 13:18:25 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (i > 0 && line[i - 1] == '\r')
		line[i - 1] = '\0';
	else
		line[i] = '\0';
}

void	error(char *msg)
{
	ft_printf("\033[1;35mERROR: %s\033[0m\n", msg);
	exit(1);
}

int	get_next_line_and_append(int fd, char ***map, int *h, int *w)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	remove_newline(line);
	if (!append_line_to_map(map, line, h, w))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

int	read_map_lines(int fd, char ***out_map, int *width, int *height)
{
	char	**map;
	int		h;
	int		w;

	map = NULL;
	h = 0;
	w = -1;
	while (get_next_line_and_append(fd, &map, &h, &w))
		;
	if (h == 0)
		error("Empty map file!! >:( you take me for a fool, wizard!");
	*out_map = map;
	*width = w;
	*height = h;
	return (1);
}

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}
