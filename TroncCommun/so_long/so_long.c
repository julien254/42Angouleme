/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:45:52 by julien            #+#    #+#             */
/*   Updated: 2022/09/20 01:09:26 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_win(int key, t_img *img)
{
	static int x = 0;
	size_t	i;

	if (key == 65307)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(EXIT_SUCCESS);
	}
	if (key == 100)
	{
		i = 0;
		while (i < 10)
		{
			mlx_put_image_to_window(img->mlx, img->win, img->img, x++, 0);
			i++;
		}
	}
	ft_printf("l'id de la touche est : %d.\n", key);
	return (0);
}


int	main(int argc, char *argv[])
{
	t_img	img;

	(void)argc;
	(void)argv;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 750, 650, "So_long");
	mlx_key_hook(img.win, ft_close_win, (void *)&img);
	img.img = mlx_xpm_file_to_image(img.mlx, "pokeball.xpm", &img.size_x, &img.size_y);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
