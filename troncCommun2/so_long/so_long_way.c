/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:37:29 by judetre           #+#    #+#             */
/*   Updated: 2024/07/31 16:44:05 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_lst_near	*recup_near(int y, int x, t_win *game)
{
	int			i;
	t_lst_near	*near;
	t_lst_near	*next_near;
	t_lst_lst	*new;

	near = lstnew(y, x + 1, &game->way.map2d_int[y][x + 1], game);
	new = lst_lstnew(&near, game);
	lstlstadd_back(&game->lst, new);
	i = 0;
	while (i < 3)
	{
		if (i == 0)
			next_near = lstnew(y, x - 1, &game->way.map2d_int[y][x - 1], game);
		else if (i == 1)
			next_near = lstnew(y + 1, x, &game->way.map2d_int[y + 1][x], game);
		else if (i == 2)
			next_near = lstnew(y - 1, x, &game->way.map2d_int[y - 1][x], game);
		lstadd_back(&near, next_near);
		i++;
	}
	return (near);
}

int	make_way(t_win *game, int x, int y, int step)
{
	t_lst_near	*near;

	near = recup_near(y, x, game);
	while (near)
	{
		if (*near->value == 9996)
			game->way.item_found++;
		if (*near->value != 9999 && *near->value != 9997 && \
				*near->value > step + 1)
		{
			*near->value = step + 1;
			make_way(game, near->x, near->y, step + 1);
		}
		else if (*near->value == 9997)
			game->way.exit_found = 0;
		near = near->next;
	}
	if (game->way.exit_found == 0)
		return (0);
	return (1);
}

void	verif_way(t_win *game, int x, int y, int step)
{
	game->lst = NULL;
	game->way.exit_found = 1;
	if (make_way(game, x, y, step) == 1)
		exit_failure(ERR_WAY_EXIT, STR_ERR_WAY_EXIT, game);
	else if (game->way.item_found != game->map.item)
		exit_failure(ERR_WAY_ITEM, STR_ERR_WAY_ITEM, game);
}
