/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:59:24 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/26 16:59:24 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	update_player_direction(t_game *game, int dx, int dy)
{
	if (dx == 1)
		game->img_player = game->img_player_right;
	else if (dx == -1)
		game->img_player = game->img_player_left;
	else if (dy == 1)
		game->img_player = game->img_player_down;
	else if (dy == -1)
		game->img_player = game->img_player_up;
}

int	handle_player_destination(t_game *game, int new_x, int new_y)
{
	char	dest;

	dest = game->map[new_y][new_x];
	if (dest == '1')
		return (0);
	if (dest == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	else if (dest == 'E')
	{
		if (game->collected == game->total_collectibles)
		{
			ft_printf("\033[32mYOU MADE IT WIZAAARD!\033[0m\n");
			close_game(game);
		}
		else
		{
			ft_printf("\033[1;35mCOLLECT ALL THE STARS, KITTY!\033[0m\n");
			return (0);
		}
	}
	return (1);
}

void	finalize_player_move(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
	render_map(game);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	update_player_direction(game, dx, dy);
	if (!handle_player_destination(game, new_x, new_y))
		return ;
	finalize_player_move(game, new_x, new_y);
}
