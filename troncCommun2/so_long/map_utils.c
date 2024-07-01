/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:59:39 by jdetre            #+#    #+#             */
/*   Updated: 2024/06/30 17:25:59 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**read_map(char *file)
{
	char	**map2d;

	check_ber_extension(file);
	map2d = ft_recover_fd(file);
	if (!map2d)
	{
		perror("Error map");
		exit(EXIT_FAILURE);
	}
	return (map2d);
}

/* Count hero position, number of items, and if an exit exists */
void	count_elem_map(t_win *game)
{
	char	**map2d;
	int		x;
	int		y;

	map2d = game->map2d;
	y = 0;
	while (map2d[y])
	{
		x = 0;
		while (map2d[y][x])
		{
			if (map2d[y][x] == 'C')
				game->map.item++;
			else if (map2d[y][x] == 'P')
			{
				game->map.hero_y = y;
				game->map.hero_x = x;
				game->map.hero++;
			}
			else if (map2d[y][x] == 'E')
				game->map.exit++;
			x++;
		}
		y++;
	}
}
