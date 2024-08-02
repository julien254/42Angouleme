/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:29:37 by jdetre            #+#    #+#             */
/*   Updated: 2024/07/31 16:39:13 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_lst(t_lst_lst *lst)
{
	t_lst_lst	*lst_tmp;
	t_lst_near	*near_tmp;

	if (lst)
	{
		while (lst)
		{
			if (lst->near)
			{
				while (lst->near)
				{
					near_tmp = lst->near->next;
					free(lst->near);
					lst->near = near_tmp;
				}
			}
			lst_tmp = lst->next;
			free(lst);
			lst = lst_tmp;
		}
	}
}

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

void	print_victory_str(t_win *game)
{
	ft_printf("Congratulation, You won ");
	ft_printf("in %d moves !!!\n", game->map.count_move);
}

int	close_window(t_win *game)
{
	free_img(game);
	ft_free_malloc2d((void **)game->map2d);
	ft_free_malloc2d((void **)game->way.map2d_int);
	free_lst(game->lst);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map.item == 0 && game->map.count_move != 0 && \
			game->exit_success)
		print_victory_str(game);
	exit(game->map.err_map);
}

void	exit_failure(int err, char *str_err, t_win *game)
{
	game->map.err_map = err;
	ft_putendl_fd(str_err, 2);
	close_window(game);
}
