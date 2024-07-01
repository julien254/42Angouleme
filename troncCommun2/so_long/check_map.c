/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:42:15 by jdetre            #+#    #+#             */
/*   Updated: 2024/06/30 17:00:54 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_ber_extension(char *map)
{
	char	*ext;

	ext = map + ft_strlen(map) - 4;
	if (ft_strncmp(ext, ".ber", 4))
	{
		ft_printf("Error: The map isn't a .ber\n");
		exit(EXIT_FAILURE);
	}
}

void	check_size_map(t_win *game)
{
	char	**map2d;
	int		y;

	y = 0;
	map2d = game->map2d;
	game->map.map_size_y = ft_tab2dlen(map2d);
	game->map.map_size_x = ft_strlen(map2d[y++]);
	while (map2d[y])
	{
		if (ft_strlen(map2d[y++]) != game->map.map_size_x)
			exit_failure(ERR_SHAPE, STR_ERR_SHAPE, game);
	}
}

void	check_wall_map(t_win *game)
{
	int		size_line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	size_line = game->map.map_size_x;
	while (game->map2d[y][x])
	{
		if (game->map2d[y][x++] != '1')
			exit_failure(ERR_WALL, STR_ERR_WALL, game);
	}
	while (game->map2d[y])
	{
		if (game->map2d[y][0] != '1' || game->map2d[y][size_line - 1] != '1')
			exit_failure(ERR_WALL, STR_ERR_WALL, game);
		y++;
	}
	x = 0;
	while (game->map2d[y - 1][x])
	{
		if (game->map2d[y - 1][x++] != '1')
			exit_failure(ERR_WALL, STR_ERR_WALL, game);
	}
}

void	check_elem_map(t_win *game)
{
	if (game->map.item == 0)
		exit_failure(ERR_ITEM, STR_ERR_ITEM, game);
	if (game->map.hero != 1)
		exit_failure(ERR_HERO, STR_ERR_HERO, game);
	if (game->map.exit != 1)
		exit_failure(ERR_EXIT, STR_ERR_EXIT, game);
}
