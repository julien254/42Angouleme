/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:29:11 by jdetre            #+#    #+#             */
/*   Updated: 2024/07/11 12:50:11 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	init_way_mouvements(t_win *game)
{
	game->way.movements.x[0] = -1;
	game->way.movements.x[1] = 1;
	game->way.movements.x[2] = 0;
	game->way.movements.x[3] = 0;
	game->way.movements.y[0] = 0;
	game->way.movements.y[1] = 0;
	game->way.movements.y[2] = -1;
	game->way.movements.y[3] = 1;
}

void	init_way_queue(t_win *game, int start_y, int start_x)
{
	game->way.queue = (t_position *)malloc(sizeof(t_position) * \
			(game->map.map_size_y * game->map.map_size_x * \
			1L << game->map.item));
	if (!game->way.queue)
		exit_failure(ERR_MALLOC, STR_ERR_MALLOC, game);
	game->way.queue[game->way.next_way].x = start_x;
	game->way.queue[game->way.next_way].y = start_y;
	game->way.queue[game->way.next_way].steps = 0;
	game->way.queue[game->way.next_way].bitmask = 0;
}

void	init_way_visited(t_win *game, int start_y, int start_x)
{
	int			y;
	int			x;
	long int	bitmask;

	game->way.visited = ft_tab3d_int(game->map.map_size_y, \
			game->map.map_size_x, 1 << game->map.item);
	if (!game->way.visited)
		exit_failure(ERR_MALLOC, STR_ERR_MALLOC, game);
	y = -1;
	while (++y < game->map.map_size_y)
	{
		x = -1;
		while (++x < game->map.map_size_x)
		{
			bitmask = -1;
			while (++bitmask < 1L << game->map.item)
				game->way.visited[y][x][bitmask] = 0;
		}
	}
	mark_visited(start_y, start_x, 0, game);
}

void	initialize_way(t_win *game, int start_x, int start_y)
{
	game->way.current_way = 0;
	game->way.next_way = 0;
	init_way_queue(game, start_y, start_x);
	game->way.next_way++;
	init_way_visited(game, start_y, start_x);
	init_way_mouvements(game);
}
