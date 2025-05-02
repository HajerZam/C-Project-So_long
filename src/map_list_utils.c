/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:37:11 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/25 13:37:11 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_maplist	*read_map_as_linked_list(int fd)
{
	t_maplist	*map;

	map = malloc(sizeof(t_maplist));
	if (!map)
		return (NULL);
	map->rows = NULL;
	map->height = 0;
	map->width = 0;
	if (!read_map_loop(map, fd))
		return (NULL);
	return (map);
}

int	init_window(t_game *game, int width, int height)
{
	int	w;
	int	h;

	w = width * TILE_SIZE;
	h = height * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, w, h, "so_long");
	if (!game->win)
		return (0);
	return (1);
}
