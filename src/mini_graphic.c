/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:04:08 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/03 15:52:47 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:04:08 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/02 18:45:00 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *game, int x, int y)
{
	char	tile;
	void	*img;

	tile = game->map[y][x];
	img = game->img_floor;
	if (tile == '1')
		img = game->img_wall;
	else if (tile == 'P')
		img = game->img_player;
	else if (tile == 'C')
		img = game->img_collectible;
	else if (tile == 'E')
		img = game->img_exit;
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	load_images(t_game *game)
{
	int	w;
	int	h;

	if (!game->mlx)
		return ;
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"./assets/floor.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall.xpm", &w, &h);
	game->img_player_down = mlx_xpm_file_to_image(game->mlx,
			"./assets/player.xpm", &w, &h);
	game->img_player_up = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_up.xpm", &w, &h);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_l.xpm", &w, &h);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_r.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./assets/exit.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./assets/star.xpm", &w, &h);
	game->img_player = game->img_player_down;
}

void	start_game(char **map, int height, int width)
{
	t_game	game;

	ft_printf("starting game....\n");
	init_game_struct(&game, map, height, width);
	if (!init_window(&game, width, height))
	{
		cleanup_game(&game);
		return ;
	}
	game.map = map;
	game.width = width;
	game.height = height;
	game.move_count = 0;
	load_images(&game);
	render_map(&game);
	find_player_position(&game);
	count_collectibles(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free_images(&game);
}
