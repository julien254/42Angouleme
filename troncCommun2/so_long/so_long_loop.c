/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:11:07 by jdetre            #+#    #+#             */
/*   Updated: 2024/06/30 18:01:13 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	choose_direction(t_win *game, int *x, int *y)
{
	if (game->map.hero_direction == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
				game->img.hero.img, *x * ELEM_SIZE_X, *y * ELEM_SIZE_Y);
	if (game->map.hero_direction == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
				game->img.hero_left.img, *x * ELEM_SIZE_X, *y * ELEM_SIZE_Y);
	if (game->map.hero_direction == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
				game->img.hero_back.img, *x * ELEM_SIZE_X, *y * ELEM_SIZE_Y);
	if (game->map.hero_direction == 3)
		mlx_put_image_to_window(game->mlx, game->win, \
				game->img.hero_right.img, *x * ELEM_SIZE_X, *y * ELEM_SIZE_Y);
}

void	update_map(t_win *game, int *x, int *y)
{
	*x = 0;
	while (game->map2d[*y][*x])
	{
		if (game->map2d[*y][*x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, \
				game->img.wall.img, *x * ELEM_SIZE_X, *y * ELEM_SIZE_Y);
		else if (game->map2d[*y][*x] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, \
				game->img.item.img, *x * ELEM_SIZE_X, *y * ELEM_SIZE_Y);
		else if (game->map2d[*y][*x] == 'P')
			choose_direction(game, x, y);
		else if (game->map2d[*y][*x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, \
				game->img.exit.img, *x * ELEM_SIZE_X, *y * ELEM_SIZE_Y);
		else if (game->map2d[*y][*x] == '0')
			mlx_put_image_to_window(game->mlx, game->win, \
				game->img.floor.img, *x * ELEM_SIZE_X, *y * ELEM_SIZE_Y);
		*x = *x + 1;
	}
	*y = *y + 1;
}

int	loop_print_map(t_win *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map2d[y])
	{
		update_map(game, &x, &y);
	}
	return (0);
}
