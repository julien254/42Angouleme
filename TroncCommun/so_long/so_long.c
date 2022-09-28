/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:45:52 by julien            #+#    #+#             */
/*   Updated: 2022/09/28 08:36:23 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	update_font_hero(t_img *below, t_img *above)
{
	int	i;

	i = 0;
	while (i < (TILESIZE * TILESIZE))
	{
		if (*(unsigned int *)above->addr == 4278190080)
			*(unsigned int *)above->addr = \
										*(unsigned int *)below->addr;
		above->addr += 4;
		below->addr += 4;
		i++;
	}
	above->addr -= (TILESIZE * TILESIZE) * 4;
	below->addr -= (TILESIZE * TILESIZE) * 4;
}

void	printmap(int size_x, int size_y, t_lst_img *boximg)
{
	int	x;
	int	y;

	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			mlx_put_image_to_window(boximg->mlx, boximg->win, \
											boximg->floor->img, x, y);
			if (x == 0 || y == 0 || x == (size_x - 50) || y == (size_y - 50))
			{
				update_font_hero(boximg->floor, boximg->wall);
				mlx_put_image_to_window(boximg->mlx, boximg->win, \
											boximg->wall->img, x, y);
			}
			x += 50;
		}
		y += 50;
	}
}

void	move(int key, t_lst_img *boximg)
{
	static int	x = 0;
	static int	y = 0;

	mlx_put_image_to_window(boximg->mlx, boximg->win, boximg->floor->img, x, y);
	if (key == 100)
		x += 50;
	else if (key == 97)
		x -= 50;
	else if (key == 115)
		y += 50;
	else if (key == 119)
		y -= 50;
	update_font_hero(boximg->floor, boximg->hero);
	mlx_put_image_to_window(boximg->mlx, boximg->win, boximg->hero->img, x, y);
}

int	ft_hook(int keycode, t_lst_img *boximg)
{
	move(keycode, boximg);
	ft_printf("%d\n", keycode);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_lst_img	boximg;

	(void)argc;
	(void)argv;
	boximg.mlx = mlx_init();
	boximg.win = mlx_new_window(boximg.mlx, 1000, 600, "So_long");
	boximg.floor = ft_lst_new_img("tiles/herbe.xpm", boximg.mlx, boximg.win);
	boximg.hero = ft_lst_new_img("sprite/test.xpm", boximg.mlx, \
																boximg.win);
	boximg.wall = ft_lst_new_img("tiles/arbre.xpm", boximg.mlx, boximg.win);
	printmap(1000, 600, &boximg);
	update_font_hero(boximg.floor, boximg.hero);
	mlx_put_image_to_window(boximg.mlx, boximg.win, boximg.hero->img, 50, 50);
	mlx_hook(boximg.win, 2, 1L << 0, ft_hook, (void *)&boximg);
	mlx_loop(boximg.mlx);
	return (0);
}
