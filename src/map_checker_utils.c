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
	int i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	line[i] = '\0';
}

int	read_map_lines(int fd, char ***out_map, int *width, int *height)
{
	char	*line;
	char	**map;
	int		h;
	int		w;

	map = NULL;
	w = -1;
	h = 0;
	while ((line = get_next_line(fd)))
	{
		remove_newline(line);
		if (!append_line_to_map(&map, line, &h, &w))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (h == 0)
		return (perror("Empty map file!! >:( you take me for a fool, wizard!"), 0);
	*out_map = map;
	*width = w;
	*height = h;
	return (1);
}
