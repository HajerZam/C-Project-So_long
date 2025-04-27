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

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC
		return (close_game(game));
	else if (keycode == 'w' || keycode == 119)
	{
		game->img_player = game->img_player_up;
		move_player(game, 0, -1);
	}
	else if (keycode == 'a' || keycode == 97)
	{
		game->img_player = game->img_player_left;
		move_player(game, -1, 0);
	}
	else if (keycode == 's' || keycode == 115)
	{
		game->img_player = game->img_player_down;
		move_player(game, 0, 1);
	}
	else if (keycode == 'd' || keycode == 100)
	{
		game->img_player = game->img_player_right;
		move_player(game, 1, 0);
	}
	return (0);
}

void	find_player_position(t_game *game)
{
	int x;
	int y;

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

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x = game->player_x + dx;
	int	new_y = game->player_y + dy;
	char	dest = game->map[new_y][new_x];

	if (dest == '1') // Wall
		return ;
	if (dest == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	if (dest == 'E')
	{
		if (game->collected == game->total_collectibles)
		{
			ft_printf("\033[32mYOU MADE IT WIZAAARD!\033[0m\n");
			close_game(game);
		}
		else
		{
			ft_printf("\033[31mYOU NEED TO COLLECT ALL THE STARS FIRST, KITTYYY!\033[0m\n");
			return ;
		}
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
	render_map(game);
}

int	close_game(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);

	return (0);
}
