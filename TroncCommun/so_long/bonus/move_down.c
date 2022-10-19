/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:39:24 by julien            #+#    #+#             */
/*   Updated: 2022/10/13 23:17:09 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	if_you_can_down(t_lst_img *boximg, int y, int x)
{
	int	x_max;

	x_max = x + boximg->hero->size_x;
	while (x < x_max)
	{
		if (boximg->map2d_pix[y + TILESIZE_Y][x] == 1)
			return (0);
		x++;
	}
	return (1);
}

int	move_down(t_lst_img *boximg, int *y, int *x)
{
	struct timeval	time;

	t_img		*imgs[16];

	init_imgs(imgs, boximg->hero, boximg->hero_feet_left, boximg->hero_feet_right);
	init_move(boximg, &time, y, x);
	if (return_msec(&time) - boximg->msec > 25000 && if_you_can_down(boximg, *y, *x) && boximg->letsgo_down)
	{
		print_img(boximg, imgs[boximg->i++], *x, *y);
		ft_printf("%d\n", boximg->i);
		*y = *y + 1;
		if (*y % TILESIZE_Y == 0)
			boximg->pos_hero_y++;
		boximg->msec = return_msec(&time);
	}
	if (boximg->i > 15 && boximg->letsgo_down)
		boximg->i = 0;
	return (0);
}
