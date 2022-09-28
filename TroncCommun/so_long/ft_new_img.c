/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:12:31 by julien            #+#    #+#             */
/*   Updated: 2022/09/26 16:06:32 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*ft_lst_new_img(char *filename, void *mlx, void *win)
{
	t_img	*img;

	img = (t_img *)ft_calloc(sizeof(t_img), 1);
	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(mlx, filename, &img->size_x, &img->size_y);
	img->name = filename;
	img->mlx = mlx;
	img->win = win;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
											&img->line_length, &img->endian);
	img->pos_x = 0;
	img->pos_y = 0;
	return (img);
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
		ft_printf("%d\n", img->pos_x);
		ft_printf("%d\n", img->pos_y);
	}
}
