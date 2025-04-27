/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:58:17 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/25 11:58:17 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_cell	*make_cell_list(char *line)
{
	t_cell	*head;
	t_cell	*tail;
	t_cell	*new;

	head = NULL;
	tail = NULL;
	while (*line && *line != '\n')
	{
		new = malloc(sizeof(t_cell));
		if (!new)
			return (NULL);
		new->value = *line;
		new->next = NULL;
		if (!head)
			head = new;
		else
			tail->next = new;
		tail = new;
		line++;
	}
	return (head);
}

t_row	*create_row(char *line, int expected_width)
{
	t_row	*row;
	int		len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	if (expected_width != -1 && len != expected_width)
	{
		error("Map not rectangular");
		return (NULL);
	}
	row = malloc(sizeof(t_row));
	if (!row)
		return (NULL);
	row->cells = make_cell_list(line);
	row->next = NULL;
	return (row);
}

void	append_row_to_map(t_maplist *map, t_row *new, t_row **last)
{
	if (!map->rows)
		map->rows = new;
	else
		(*last)->next = new;
	*last = new;
}

static int	get_trimmed_width(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	if (len > 0 && line[len - 1] == '\r')
		len--;
	return (len);
}

int	read_map_loop(t_maplist *map, int fd)
{
	t_row	*new;
	t_row	*last;
	char	*line;
	int		width;

	width = -1;
	last = NULL;
	line = get_next_line(fd);
	while (line)
	{
		new = create_row(line, width);
		if (!new)
		{
			free(line);
			return (0);
		}
		append_row_to_map(map, new, &last);
		width = get_trimmed_width(line);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	map->width = width;
	return (1);
}
