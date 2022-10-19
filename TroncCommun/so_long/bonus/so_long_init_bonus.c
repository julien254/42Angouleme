/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:03:42 by julien            #+#    #+#             */
/*   Updated: 2022/10/13 23:52:09 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_map *map, char *str, t_lst_img *boximg)
{
	map->line = 0;
	map->size_line = cmp_line_size(str, map, boximg);
	map->nbr_of_line = ft_count_line(str);
	map->pos = 0;
	map->exit = 0;
	map->item = 0;
	map->item_found = 0;
}

void	init_box(t_lst_img *boximg, t_map *map, char *map_name)
{
	boximg->exit_found = 1;
	boximg->item_found = 0;
	boximg->letsgo_up = 0;
	boximg->letsgo_down = 0;
	boximg->letsgo_left = 0;
	boximg->letsgo_right = 0;
	boximg->i = 0;
	boximg->msec = 0;
	make_map(map_name, map, boximg);
	boximg->map2d_int = tab2d_char_to_int(boximg->map2d);
	boximg->mlx = mlx_init();
	boximg->win = mlx_new_window(boximg->mlx, TILESIZE_X * map->size_line, \
			TILESIZE_Y * map->nbr_of_line, "So_long");
	boximg->count_move = 0;
	boximg->floor = ft_new_img("tiles/herbe.xpm", boximg->mlx, boximg->win);
	boximg->hero = ft_new_img("sprite/hero.xpm", boximg->mlx, boximg->win);
	boximg->hero_left = ft_new_img("sprite/hero_left.xpm", boximg->mlx, \
																boximg->win);
	boximg->hero_feet_left = ft_new_img("sprite/hero_feet_left.xpm", boximg->mlx, \
																boximg->win);
	boximg->hero_right = ft_new_img("sprite/hero_right.xpm", boximg->mlx, \
																boximg->win);
	boximg->hero_feet_right = ft_new_img("sprite/hero_feet_right.xpm", boximg->mlx, \
																boximg->win);
	boximg->hero_back = ft_new_img("sprite/hero_back.xpm", boximg->mlx, \
																boximg->win);
	boximg->wall = ft_new_img("tiles/arbre.xpm", boximg->mlx, boximg->win);
	boximg->exit = ft_new_img("tiles/exit.xpm", boximg->mlx, boximg->win);
	boximg->item = ft_new_img("tiles/pokeball.xpm", boximg->mlx, \
														boximg->win);
}

void	init_imgs(t_img *imgs[16], t_img *hero, t_img *hero_left, t_img *hero_right)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 2)
			imgs[i] = hero;
		else if (i < 8)
			imgs[i] = hero_left;
		else if (i < 10)
			imgs[i] = hero;
		else if (i < 16)
			imgs[i] = hero_right;
		i++;
	}
}

void	init_move(t_lst_img *boximg, struct timeval *time, int *y, int *x)
{
	gettimeofday(time, NULL);
	if (*x == 0 && *y == 0)
	{
		*x = boximg->pos_hero_x * TILESIZE_X;
		*y = boximg->pos_hero_y * TILESIZE_Y;
	}
}
