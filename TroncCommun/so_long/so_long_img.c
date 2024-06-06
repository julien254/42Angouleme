/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:12:31 by julien            #+#    #+#             */
/*   Updated: 2024/06/06 12:38:53 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*ft_new_img(char *filename, void *mlx, void *win)
{
	t_img	*img;

	img = (t_img *)ft_calloc(sizeof(t_img), 1);
	//img = 0;
	ft_verif_malloc(img);
	img->img = mlx_xpm_file_to_image(mlx, filename, &img->size_x, &img->size_y);
	img->name = filename;
	img->mlx = mlx;
	img->win = win;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
			&img->line_length, &img->endian);
	return (img);
}

void	update_font_hero(t_img *below, t_img *above)
{
	int	i;

	i = 0;
	while (i < (TILESIZE_Y * TILESIZE_X))
	{
		if (*(unsigned int *)above->addr == 4278190080)
			*(unsigned int *)above->addr = \
										*(unsigned int *)below->addr;
		above->addr += 4;
		below->addr += 4;
		i++;
	}
	above->addr -= (TILESIZE_Y * TILESIZE_X) * 4;
	below->addr -= (TILESIZE_Y * TILESIZE_X) * 4;
}

void	print_img(t_lst_img *boximg, t_img *img, int x, int y)
{
	update_font_hero(boximg->floor, img);
	mlx_put_image_to_window(boximg->mlx, boximg->win, \
			img->img, x, y);
}

void	choose_img(t_lst_img *boximg, char *line_map2d, int y)
{
	int	x;
	int	j;

	x = 0;
	j = 0;
	while (line_map2d[j])
	{
		if (line_map2d[j] == 'P')
			print_img(boximg, boximg->hero, x, y);
		else if (line_map2d[j] == '1')
			print_img(boximg, boximg->wall, x, y);
		else if (line_map2d[j] == 'E')
			print_img(boximg, boximg->exit, x, y);
		else if (line_map2d[j] == 'C')
			print_img(boximg, boximg->item, x, y);
		else
			mlx_put_image_to_window(boximg->mlx, boximg->win, \
					boximg->floor->img, x, y);
		x += TILESIZE_X;
		j++;
	}
}

void	ft_put_img(t_img *img)
{
	int	i;

	if (img)
	{
		ft_printf("%s\n", img->name);
		ft_printf("%X\n", img->mlx);
		ft_printf("%X\n", img->win);
		i = 0;
		while (i < 2500)
		{
			ft_printf("%X, ", *(unsigned int *)img->addr);
			img->addr += 4;
			i++;
		}
		ft_printf(".\n");
		ft_printf("%d\n", img->bits_per_pixel);
		ft_printf("%d\n", img->line_length);
		ft_printf("%d\n", img->endian);
		ft_printf("%d\n", img->size_x);
		ft_printf("%d\n", img->size_y);
	}
}
