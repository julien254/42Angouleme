/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:18:20 by jdetre            #+#    #+#             */
/*   Updated: 2024/07/11 12:16:41 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_up(t_win *game)
{
	game->map.hero_direction = 2;
	if (game->map2d[game->map.hero_y - 1][game->map.hero_x] == '1')
		return ;
	if (game->map2d[game->map.hero_y - 1][game->map.hero_x] == 'E' \
			&& game->map.item == 0)
	{
		game->exit_success = 1;
		game->map.count_move++;
		close_window(game);
	}
	else if (game->map2d[game->map.hero_y - 1][game->map.hero_x] == 'E')
		return ;
	if (game->map2d[game->map.hero_y - 1][game->map.hero_x] == 'C')
		game->map.item--;
	ft_printf("Move : %d \n", ++game->map.count_move);
	game->map2d[game->map.hero_y][game->map.hero_x] = '0';
	game->map2d[--game->map.hero_y][game->map.hero_x] = 'P';
}

void	move_down(t_win *game)
{
	game->map.hero_direction = 0;
	if (game->map2d[game->map.hero_y + 1][game->map.hero_x] == '1')
		return ;
	if (game->map2d[game->map.hero_y + 1][game->map.hero_x] == 'E' \
			&& game->map.item == 0)
	{
		game->exit_success = 1;
		game->map.count_move++;
		close_window(game);
	}
	else if (game->map2d[game->map.hero_y + 1][game->map.hero_x] == 'E')
		return ;
	if (game->map2d[game->map.hero_y + 1][game->map.hero_x] == 'C')
		game->map.item--;
	ft_printf("Move : %d\n", ++game->map.count_move);
	game->map2d[game->map.hero_y][game->map.hero_x] = '0';
	game->map2d[++game->map.hero_y][game->map.hero_x] = 'P';
}

void	move_left(t_win *game)
{
	game->map.hero_direction = 1;
	if (game->map2d[game->map.hero_y][game->map.hero_x - 1] == '1')
		return ;
	if (game->map2d[game->map.hero_y][game->map.hero_x - 1] == 'E' \
			&& game->map.item == 0)
	{
		game->exit_success = 1;
		game->map.count_move++;
		close_window(game);
	}
	else if (game->map2d[game->map.hero_y][game->map.hero_x - 1] == 'E')
		return ;
	if (game->map2d[game->map.hero_y][game->map.hero_x - 1] == 'C')
		game->map.item--;
	ft_printf("Move : %d\n", ++game->map.count_move);
	game->map2d[game->map.hero_y][game->map.hero_x] = '0';
	game->map2d[game->map.hero_y][--game->map.hero_x] = 'P';
}

void	move_right(t_win *game)
{
	game->map.hero_direction = 3;
	if (game->map2d[game->map.hero_y][game->map.hero_x + 1] == '1')
		return ;
	if (game->map2d[game->map.hero_y][game->map.hero_x + 1] == 'E' \
			&& game->map.item == 0)
	{
		game->exit_success = 1;
		game->map.count_move++;
		close_window(game);
	}
	else if (game->map2d[game->map.hero_y][game->map.hero_x + 1] == 'E')
		return ;
	if (game->map2d[game->map.hero_y][game->map.hero_x + 1] == 'C')
		game->map.item--;
	ft_printf("Move : %d\n", ++game->map.count_move);
	game->map2d[game->map.hero_y][game->map.hero_x] = '0';
	game->map2d[game->map.hero_y][++game->map.hero_x] = 'P';
}

int	key_hook(int keycode, t_win *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_W)
		move_up(game);
	if (keycode == KEY_S)
		move_down(game);
	if (keycode == KEY_A)
		move_left(game);
	if (keycode == KEY_D)
		move_right(game);
	return (0);
}
