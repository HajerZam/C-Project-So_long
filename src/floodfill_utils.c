/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:16:06 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/24 14:16:06 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	find_player(char **map, int height, int width)
{
	t_point	pos;
	int		i;
	int		j;

	pos.x = -1;
	pos.y = -1;
	i = 0;
	while (i < height && pos.x == -1)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (pos);
}

int	**init_visited(int height, int width)
{
	int	**visited;
	int	i;
	int	j;

	visited = malloc(sizeof(int *) * height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = malloc(sizeof(int) * width);
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		j = 0;
		while (j < width)
			visited[i][j++] = 0;
		i++;
	}
	return (visited);
}
