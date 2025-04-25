/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:04:08 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/25 15:04:08 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	for (int i = 0; i < game->height; i++)
			ft_printf("Row %d length: %lu\n", i, ft_strlen(game->map[i]));
	if (!game->img_floor) ft_printf("❌ floor image failed\n");
	if (!game->img_wall) ft_printf("❌ wall image failed\n");
	if (!game->img_player) ft_printf("❌ player image failed\n");
	if (!game->img_exit) ft_printf("❌ exit image failed\n");
	if (!game->img_collectible) ft_printf("❌ collectible image failed\n");			
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			char tile = game->map[y][x];
			void *img = game->img_floor;
			if (tile == '1')
				img = game->img_wall;
			else if (tile == 'P')
				img = game->img_player;
			else if (tile == 'C')
				img = game->img_collectible;
			else if (tile == 'E')
				img = game->img_exit;
			else if (tile != '0')
				ft_printf("⚠ Unknown tile '%c' at [%d][%d]\n", tile, y, x);
			mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}


void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img_floor = mlx_xpm_file_to_image(game->mlx, "../assets/floor.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "../assets/wall.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "../assets/player.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "../assets/exit.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "../assets/star.xpm", &w, &h);
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_collectible);
}

void	start_game(char **map, int height, int width)
{
	t_game	game;
	int		w;
	int		h;

	w = width * TILE_SIZE;
	h = height * TILE_SIZE;
	ft_printf("starting game....\n");
	game.mlx = mlx_init();
	if (!game.mlx)
		return ;
	ft_printf("mlx initialized\n");
	game.win = mlx_new_window(game.mlx, w, h, "so_long");
	ft_printf("window created\n");
	if (!game.win)
		return ;
	game.map = map;
	game.width = width;
	game.height = height;
	load_images(&game);
	ft_printf("images loaded\n");
	render_map(&game);
	ft_printf("map rendered\n");
	mlx_loop(game.mlx);
	ft_printf("mlx loop started\n");
	free_images(&game);
}
