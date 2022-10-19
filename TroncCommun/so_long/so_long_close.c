/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:59:01 by julien            #+#    #+#             */
/*   Updated: 2022/10/18 14:16:28 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_lst_img *boximg)
{
	mlx_destroy_image(boximg->mlx, boximg->floor->img);
	mlx_destroy_image(boximg->mlx, boximg->hero->img);
	mlx_destroy_image(boximg->mlx, boximg->hero_back->img);
	mlx_destroy_image(boximg->mlx, boximg->hero_left->img);
	mlx_destroy_image(boximg->mlx, boximg->hero_right->img);
	mlx_destroy_image(boximg->mlx, boximg->item->img);
	mlx_destroy_image(boximg->mlx, boximg->exit->img);
	mlx_destroy_image(boximg->mlx, boximg->wall->img);
	free(boximg->floor);
	free(boximg->hero);
	free(boximg->hero_back);
	free(boximg->hero_left);
	free(boximg->hero_right);
	free(boximg->item);
	free(boximg->exit);
	free(boximg->wall);
}

void	free_map2d(void **map2d, int sizeof_line)
{
	int	i;

	i = 0;
	while (i < sizeof_line)
	{
		free(map2d[i]);
		i++;
	}
	free(map2d);
}

void	free_mlx(t_lst_img *boximg)
{
	mlx_destroy_window(boximg->mlx, boximg->win);
	mlx_destroy_display(boximg->mlx);
	free(boximg->mlx);
}

int	end_game(t_lst_img *boximg)
{
	free_map2d((void *)boximg->map2d, boximg->map->nbr_of_line);
	free_map2d((void *)boximg->map2d_int, boximg->map->nbr_of_line);
	free_img(boximg);
	free_mlx(boximg);
	exit(EXIT_SUCCESS);
}
