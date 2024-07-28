/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:44:20 by jdetre            #+#    #+#             */
/*   Updated: 2024/07/11 12:33:58 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	is_valid_move(int x, int y, t_win *game, int bitmask)
{
	if (game->map2d[y][x] == 'E' && bitmask != (1 << game->map.item) - 1)
		return (0);
	if (x < game->map.map_size_x - 1 && y < \
			game->map.map_size_y - 1 && game->map2d[y][x] != '1')
		return (1);
	return (0);
}

int	add_good_way_in_queue(t_win *game, t_position *pos, int *new_y, int *new_x)
{
	int			i;
	long int	new_bitmask;

	i = -1;
	while (++i < 4)
	{
		*new_x = pos->x + game->way.movements.x[i];
		*new_y = pos->y + game->way.movements.y[i];
		if (is_valid_move(*new_x, *new_y, game, pos->bitmask))
		{
			new_bitmask = pos->bitmask;
			if (game->map2d[*new_y][*new_x] == 'C')
				new_bitmask |= get_item_bitmask(game, *new_y, *new_x);
			if (is_visited(*new_y, *new_x, new_bitmask, game))
				continue ;
			game->way.queue[game->way.next_way].x = *new_x;
			game->way.queue[game->way.next_way].y = *new_y;
			game->way.queue[game->way.next_way].steps = pos->steps + 1;
			game->way.queue[game->way.next_way].bitmask = new_bitmask;
			game->way.next_way++;
			mark_visited(*new_y, *new_x, new_bitmask, game);
		}
	}
	return (0);
}

int	verif_way(t_win *game, int start_x, int start_y)
{
	t_position	pos;
	int			new_x;
	int			new_y;
	int			steps;

	initialize_way(game, start_x, start_y);
	while (game->way.current_way < game->way.next_way)
	{
		pos = game->way.queue[game->way.current_way];
		game->way.current_way++;
		if (game->map2d[pos.y][pos.x] == 'E' && pos.bitmask == \
											(1L << game->map.item) - 1)
		{
			steps = pos.steps;
			free(game->way.queue);
			game->way.queue = NULL;
			game->way.visited = ft_free_malloc3d((void ***)game->way.visited);
			return (steps);
		}
		add_good_way_in_queue(game, &pos, &new_y, &new_x);
	}
	free(game->way.queue);
	game->way.queue = NULL;
	game->way.visited = ft_free_malloc3d((void ***)game->way.visited);
	return (-1);
}

void	check_way(t_win *game)
{
	game->map.shortest_way = verif_way(game, game->map.hero_x, \
													game->map.hero_y);
	if (game->map.shortest_way == -1)
		exit_failure(ERR_WAY, STR_ERR_WAY, game);
}
