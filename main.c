/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:26:39 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/16 11:26:39 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include <stdio.h>

int	check_map(char *file, char ***out_map, int *out_h, int *out_w)
{
	int		fd;
	char	**map;
	int		width;
	int		height;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 0);
	if (!read_map_lines(fd, &map, &width, &height))
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (!validate_loaded_map(map, height, width))
		return (0);
	*out_map = map;
	*out_h = height;
	*out_w = width;
	return (1);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		height;
	int		width;

	if (argc != 2 || !ft_strnstr(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		error("Error: Invalid! I expected a .ber file >:(");
		return (1);
	}
	else if (check_map(argv[1], &map, &height, &width))
		start_game(map, height, width);
	else
		return (1);
	return (0);
}
