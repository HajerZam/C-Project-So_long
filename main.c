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

int	check_map(char *file, char ***out_map, int *out_height, int *out_width)
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
	*out_height = height;
	*out_width = width;
	return (1);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		height;
	int		width;

	if (argc != 2 || !ft_strnstr(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_printf("\033[31mError: Invalid argument. Expected a .ber file.\033[0m\n");
		return (1);
	}
	else if (check_map(argv[1], &map, &height, &width))
	{
		ft_printf("\033[32m✔ Map is valid!\033[0m\nDimensions: %dx%d\n", width, height);
		start_game(map, height, width);
	}
	else
	{
		ft_printf("\033[31m✘ Map is invalid.\033[0m\n");
		return (1);
	}
	return (0);
}