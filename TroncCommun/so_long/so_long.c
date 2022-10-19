/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:45:52 by julien            #+#    #+#             */
/*   Updated: 2022/10/18 15:02:22 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int key, t_lst_img *boximg)
{
	if (key == 100 && \
			check_if_is(boximg, boximg->map, \
			&boximg->map2d[boximg->pos_hero_y][boximg->pos_hero_x + 1]) == 0)
		refresh_win(&boximg->pos_hero_x, key, boximg, boximg->hero_right);
	else if (key == 97 && \
			check_if_is(boximg, boximg->map, \
			&boximg->map2d[boximg->pos_hero_y][boximg->pos_hero_x - 1]) == 0)
		refresh_win(&boximg->pos_hero_x, key, boximg, boximg->hero_left);
	else if (key == 115 && \
			check_if_is(boximg, boximg->map, \
			&boximg->map2d[boximg->pos_hero_y + 1][boximg->pos_hero_x]) == 0)
		refresh_win(&boximg->pos_hero_y, key, boximg, boximg->hero);
	else if (key == 119 && \
			check_if_is(boximg, boximg->map, \
			&boximg->map2d[boximg->pos_hero_y - 1][boximg->pos_hero_x]) == 0)
		refresh_win(&boximg->pos_hero_y, key, boximg, boximg->hero_back);
	else if (key == 65307)
	{
		end_game(boximg);
	}
}

int	hook(int keycode, t_lst_img *boximg)
{
	move(keycode, boximg);
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
	mlx_hook(boximg.win, 2, 1L << 0, &hook, &boximg);
	mlx_hook(boximg.win, 17, 0, &end_game, &boximg);
	mlx_loop(boximg.mlx);
	return (0);
}
