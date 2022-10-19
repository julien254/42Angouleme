/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:45:52 by julien            #+#    #+#             */
/*   Updated: 2022/10/18 18:57:03 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int	hook(int key, t_lst_img *boximg)
{
	if (key == 115 && boximg->letsgo_down == 0)
		boximg->letsgo_down = 1;
	else if (key == 119 && boximg->letsgo_up == 0)
		boximg->letsgo_up = 1;
	if (key == 65307)
	{
		end_game(boximg);
	}
	return (0);
}

unsigned long long int	return_msec(struct timeval *time)
{
	return (time->tv_sec * 1000000 + time->tv_usec);
}

void	put_in_mappix(t_lst_img *boximg, t_img *img, int y, int x)
{
	int	y_max;
	int	x_max;
	int	xtmp;

	y_max = y + img->size_y;
	x_max = x + img->size_x;
	while (y < y_max)
	{
		xtmp = x;
		while (xtmp < x_max)
		{
			if (ft_strncmp(img->name, "tiles/pokeball.xpm", 10) == 0)
				boximg->map2d_pix[y][xtmp] = 5;
			else if (ft_strncmp(img->name, "tiles/arbre.xpm", 10) == 0)
				boximg->map2d_pix[y][xtmp] = 1;
			else if (ft_strncmp(img->name, "tiles/exit.xpm", 10) == 0)
				boximg->map2d_pix[y][xtmp] = 9;
			else
				boximg->map2d_pix[y][xtmp] = 0;
			xtmp++;
		}
		y++;
	}
}

void	set_map_pix(t_lst_img *boximg, char **map2d)
{
	int	i;
	int	j;

	i = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == '0')
				put_in_mappix(boximg, boximg->floor, i * TILESIZE_Y, j * TILESIZE_X);
			else if (map2d[i][j] == 'C')
				put_in_mappix(boximg, boximg->item, i * TILESIZE_Y, j * TILESIZE_X);
			else if (map2d[i][j] == '1')
				put_in_mappix(boximg, boximg->wall, i * TILESIZE_Y, j * TILESIZE_X);
			else if (map2d[i][j] == 'E')
				put_in_mappix(boximg, boximg->exit, i * TILESIZE_Y, j * TILESIZE_X);
			else if (map2d[i][j] == 'P')
				put_in_mappix(boximg, boximg->hero, i * TILESIZE_Y, j * TILESIZE_X);
			j++;
		}
		i++;
	}
}

void	makemap_pixel(t_lst_img *boximg)
{
	int	i;

	boximg->map2d_pix = (int **)malloc(sizeof(int *) * (boximg->map->nbr_of_line * TILESIZE_Y));
	i = 0;
	while (i < boximg->map->nbr_of_line * TILESIZE_Y)
		boximg->map2d_pix[i++] = (int *)malloc(sizeof(int) * (boximg->map->size_line * TILESIZE_X));
}

int	move_loop(t_lst_img *boximg)
{
	move_down(boximg, &boximg->map2d_int_y, &boximg->map2d_int_x);
	move_up(boximg, &boximg->map2d_int_y, &boximg->map2d_int_x);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_lst_img	boximg;
	t_map		map;

	if (argc != 2)
		return_err(ERRARGV, &map, &boximg);
	init_box(&boximg, &map, argv[1]);
	if (verif_way(&boximg, boximg.pos_hero_x, boximg.pos_hero_y, 0) == 1)
		return_err(ERREXIT, &map, &boximg);
	else if (boximg.item_found != map.item)
		return_err(ERRITEM, &map, &boximg);
	printmap(boximg.map2d, &boximg);
	makemap_pixel(&boximg);
	set_map_pix(&boximg, boximg.map2d);
	mlx_hook(boximg.win, 2, 1L << 0, &hook, (void *)&boximg);
	mlx_hook(boximg.win, 17, 0, &end_game, (void *)&boximg);
	mlx_key_hook(boximg.win, &stop_move, (void *)&boximg);
	ft_printf("dsa%vlol");
	mlx_loop_hook(boximg.mlx, &move_loop, (void *)&boximg);
	mlx_loop(boximg.mlx);
	return (0);
}
