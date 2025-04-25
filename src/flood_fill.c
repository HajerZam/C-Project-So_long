/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:01:59 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/24 14:01:59 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(visited[i++]);
	free(visited);
}

void	flood_fill(char **map, int **visited, t_point pos, t_point size)
{
	if (pos.x < 0 || pos.y < 0)
		return ;
	if (pos.x >= size.x || pos.y >= size.y)
		return ;
	if (visited[pos.y][pos.x] == 1 || map[pos.y][pos.x] == '1')
		return ;
	visited[pos.y][pos.x] = 1;
	if (map[pos.y][pos.x] == 'E')
		return ;
	flood_fill(map, visited, (t_point){pos.x + 1, pos.y}, size);
	flood_fill(map, visited, (t_point){pos.x - 1, pos.y}, size);
	flood_fill(map, visited, (t_point){pos.x, pos.y + 1}, size);
	flood_fill(map, visited, (t_point){pos.x, pos.y - 1}, size);
}

int	check_reachable(char **map, int **visited, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((map[i][j] == 'C' || map[i][j] == 'E') && !visited[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_path_valid(char **map, int height, int width)
{
	t_point	player;
	t_point	size;
	int		**visited;
	int		valid;

	player = find_player(map, height, width);
	if (player.x == -1 || player.y == -1)
		return (0);
	size.x = width;
	size.y = height;
	visited = init_visited(height, width);
	if (!visited)
		return (0);
	flood_fill(map, visited, player, size);
	valid = check_reachable(map, visited, height, width);
	free_visited(visited, height);
	return (valid);
}
