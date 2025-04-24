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

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

char	*get_next_line(int fd);
int		append_line_to_map(char ***map, char *line, int *height, int *width);
int		valid_map(char **map, int *p_out, int *e_out, int *c_out);
int		read_map_lines(int fd, char ***out_map, int *width, int *height);
int		check_border(char **map, int height, int width);
int		check_map(char *file, char ***out_map, int *out_height, int *out_width);
void	remove_newline(char *line);
int		is_path_valid(char **map, int height, int width);
t_point	find_player(char **map, int height, int width);
int		**init_visited(int height, int width);
void	free_visited(int **visited, int height);
int		check_reachable(char **map, int **visited, int height, int width);
void	flood_fill(char **map, int **visited, t_point pos, t_point size);

#endif