/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:14:46 by judetre           #+#    #+#             */
/*   Updated: 2024/02/25 10:19:58 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*ft_new_img(char *filename, void *mlx, void *win)
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
	}
}

int	main(int argc, char *argv[])
{
	/* void	*mlx; */
	/* void	*win; */
	/* t_img	*floor; */
	/* int	x; */
	/* int	y; */
	/* (void)argc; */
	/* (void)argv; */
	/* y = 0; */
	/* x = 0; */
	/* mlx = mlx_init(); */
	/* win = mlx_new_window(mlx, 1920, 1080, "So_long"); */
	/* floor = ft_new_img("sprite/hero.xpm", mlx, win); */
	/* while (y < 1080) */
	/* { */
	/* 	mlx_put_image_to_window(mlx, win, floor->img, x, y); */
	/* 	x += 60; */
	/* 	if (x > 1920) */
	/* 	{ */
	/* 		y += 60; */
	/* 		x = 0; */
	/* 	} */
	/* } */
	/* ft_put_img(floor); */
	/* mlx_loop(mlx); */
	char	**map_2d;

	/* void	*mlx; */
	/* void	*win; */
	(void)argc;
	(void)argv;
	/* mlx = mlx_init(); */
	/* win = mlx_new_window(mlx, 1920, 1080, "So_long"); */
	/* (void)win; */
	/* mlx_loop(mlx); */
	map_2d = ft_recover_fd(argv[1]);
	ft_puttab2_fd(map_2d, 1);
	return (0);
}
