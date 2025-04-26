/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:45:29 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/15 14:45:29 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
# include "../lib/GNL/get_next_line.h"

# ifndef TILE_SIZE
# define TILE_SIZE 64
# endif

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_cell
{
	char			value;
	struct s_cell	*next;
}	t_cell;

typedef struct s_row
{
	t_cell			*cells;
	struct s_row	*next;
}	t_row;

typedef struct s_maplist
{
	t_row	*rows;
	int		height;
	int		width;
}	t_maplist;

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_player_up;
	void	*img_player_down;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_exit;
	void	*img_collectible;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		move_count;
	int		collected;
	int		total_collectibles;
}	t_game;

char		*get_next_line(int fd);
void		start_game(char **map, int height, int width);
void		render_map(t_game *game);
void		load_images(t_game *game);
void		free_images(t_game *game);
t_maplist	*read_map_as_linked_list(int fd);
int			append_line_to_map(char ***map, char *line, int *height, int *width);
int			valid_map(char **map, int *p_out, int *e_out, int *c_out);
int			read_map_lines(int fd, char ***out_map, int *width, int *height);
int			check_border(char **map, int height, int width);
int			check_map(char *file, char ***out_map, int *out_height, int *out_width);
void		remove_newline(char *line);
int			is_path_valid(char **map, int height, int width);
t_point		find_player(char **map, int height, int width);
int			**init_visited(int height, int width);
void		free_visited(int **visited, int height);
int			check_reachable(char **map, int **visited, int height, int width);
void		flood_fill(char **map, int **visited, t_point pos, t_point size);
void		error(char *msg);
t_cell		*make_cell_list(char *line);
int			read_map_loop(t_maplist *map, int fd);
t_row		*create_row(char *line, int expected_width);
void		append_row_to_map(t_maplist *map, t_row *new, t_row **last);
int			validate_loaded_map(char **map, int height, int width);
int			is_valid_char(char c);
void		find_player_position(t_game *game);
void		count_collectibles(t_game *game);
int			handle_keypress(int keycode, t_game *game);
void		move_player(t_game *game, int dx, int dy);
void		close_game(t_game *game);



#endif