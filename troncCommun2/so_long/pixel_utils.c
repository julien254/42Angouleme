/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:00:42 by jdetre            #+#    #+#             */
/*   Updated: 2024/06/30 16:30:05 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

unsigned int	get_pixel_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	add_background_img(t_win *game, t_data *img)
{
	int				x;
	int				y;
	unsigned int	pixel_floor;
	unsigned int	pixel_img;

	y = 0;
	while (y < ELEM_SIZE_Y)
	{
		x = 0;
		while (x < ELEM_SIZE_X)
		{
			pixel_floor = get_pixel_color(&game->img.floor, x, y);
			pixel_img = get_pixel_color(img, x, y);
			if (pixel_img != pixel_floor && pixel_img == 4278190080)
			{
				my_mlx_pixel_put(img, x, y, pixel_floor);
			}
			x++;
		}
		y++;
	}
}
