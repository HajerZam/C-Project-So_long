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

int main(int argc, char **argv)
{
	char	**map;
	int		height;
	int		width;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	else if (check_map(argv[1], &map, &height, &width))
	{
		printf("Map is valid!\nDimensions: %dx%d\n", width, height);
		// Optional: print the map
		for (int i = 0; i < height; i++)
			printf("%s\n", map[i]);
	}
	else
	{
		fprintf(stderr, "Map is invalid.\n");
		return (1);
	}
	return (0);
}