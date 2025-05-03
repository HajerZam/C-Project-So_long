/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:18:27 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/03 15:51:32 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_struct(t_game *game, char **map, int h, int w)
{
	game->map = map;
	game->width = w;
	game->height = h;
	game->move_count = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->img_floor = NULL;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_player_down = NULL;
	game->img_player_up = NULL;
	game->img_player_left = NULL;
	game->img_player_right = NULL;
	game->img_exit = NULL;
	game->img_collectible = NULL;
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		return (close_game(game));
	else if (keycode == 'w' || keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 'a' || keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 's' || keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 'd' || keycode == 100)
		move_player(game, 1, 0);
	return (0);
}
