/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:18:27 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/02 18:19:44 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
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
