/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:29:37 by jdetre            #+#    #+#             */
/*   Updated: 2024/07/01 11:52:58 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_img(t_win *game)
{
	if (game->img.wall.img)
		mlx_destroy_image(game->mlx, game->img.wall.img);
	if (game->img.item.img)
		mlx_destroy_image(game->mlx, game->img.item.img);
	if (game->img.exit.img)
		mlx_destroy_image(game->mlx, game->img.exit.img);
	if (game->img.floor.img)
		mlx_destroy_image(game->mlx, game->img.floor.img);
	if (game->img.hero.img)
		mlx_destroy_image(game->mlx, game->img.hero.img);
	if (game->img.hero_left.img)
		mlx_destroy_image(game->mlx, game->img.hero_left.img);
	if (game->img.hero_right.img)
		mlx_destroy_image(game->mlx, game->img.hero_right.img);
	if (game->img.hero_back.img)
		mlx_destroy_image(game->mlx, game->img.hero_back.img);
}

int	close_window(t_win *game)
{
	free_img(game);
	ft_free_malloc2d((void **)game->map2d);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map.item == 0 && game->map.count_move != 0)
		printf("Congratulation, You won with %d moves !!!\n", \
				game->map.count_move);
	exit(game->map.err_map);
}

void	exit_failure(int err, char *str_err, t_win *game)
{
	game->map.err_map = err;
	printf("%s\n", str_err); 
	close_window(game);
}
