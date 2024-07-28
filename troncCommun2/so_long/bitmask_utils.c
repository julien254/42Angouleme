/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmask_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:19:15 by jdetre            #+#    #+#             */
/*   Updated: 2024/07/11 12:46:54 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	mark_visited(int y, int x, long int bitmask, t_win *game)
{
	game->way.visited[y][x][bitmask] = 1;
}

int	is_visited(int y, int x, long int bitmask, t_win *game)
{
	return (game->way.visited[y][x][bitmask]);
}

int	get_item_bitmask(t_win *game, int y, int x)
{
	int			i;
	int			j;
	int			index;
	long int	bitmask;

	bitmask = 0;
	i = -1;
	index = 0;
	while (++i < game->map.map_size_y)
	{
		j = -1;
		while (++j < game->map.map_size_x)
		{
			if (game->map2d[i][j] == 'C')
			{
				if (i == y && j == x)
				{
					bitmask = 1L << index;
					return (bitmask);
				}
				index++;
			}
		}
	}
	return (0);
}
