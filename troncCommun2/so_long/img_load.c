/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:06:22 by jdetre            #+#    #+#             */
/*   Updated: 2024/06/30 17:24:07 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	load_hero(t_win *game, int size_x, int size_y)
{
	game->img.hero.img = mlx_xpm_file_to_image(game->mlx, "sprite/hero.xpm", \
			&size_x, &size_y);
	game->img.hero.addr = mlx_get_data_addr(game->img.hero.img, \
			&game->img.hero.bits_per_pixel, &game->img.hero.line_length, \
			&game->img.hero.endian);
	game->img.hero_left.img = mlx_xpm_file_to_image(game->mlx, \
			"sprite/hero_left.xpm", &size_x, &size_y);
	game->img.hero_left.addr = mlx_get_data_addr(game->img.hero_left.img, \
		&game->img.hero_left.bits_per_pixel, &game->img.hero_left.line_length, \
			&game->img.hero_left.endian);
	game->img.hero_right.img = mlx_xpm_file_to_image(game->mlx, \
			"sprite/hero_right.xpm", &size_x, &size_y);
	game->img.hero_right.addr = mlx_get_data_addr(game->img.hero_right.img, \
			&game->img.hero_right.bits_per_pixel,
			&game->img.hero_right.line_length,
			&game->img.hero_right.endian);
	game->img.hero_back.img = mlx_xpm_file_to_image(game->mlx,
			"sprite/hero_back.xpm",
			&size_x, &size_y);
	game->img.hero_back.addr = mlx_get_data_addr(game->img.hero_back.img,
			&game->img.hero_back.bits_per_pixel,
			&game->img.hero_back.line_length,
			&game->img.hero_back.endian);
}

void	load_decor(t_win *game, int size_x, int size_y)
{
	game->img.wall.img = mlx_xpm_file_to_image(game->mlx, "tiles/wall.xpm", \
			&size_x, &size_y);
	game->img.wall.addr = mlx_get_data_addr(game->img.wall.img, \
			&game->img.wall.bits_per_pixel, &game->img.wall.line_length, \
			&game->img.wall.endian);
	game->img.item.img = mlx_xpm_file_to_image(game->mlx, "tiles/item.xpm", \
			&size_x, &size_y);
	game->img.item.addr = mlx_get_data_addr(game->img.item.img, \
			&game->img.item.bits_per_pixel, &game->img.item.line_length, \
			&game->img.item.endian);
	game->img.exit.img = mlx_xpm_file_to_image(game->mlx, "tiles/exit.xpm", \
			&size_x, &size_y);
	game->img.exit.addr = mlx_get_data_addr(game->img.exit.img, \
			&game->img.exit.bits_per_pixel, &game->img.exit.line_length, \
			&game->img.exit.endian);
	game->img.floor.img = mlx_xpm_file_to_image(game->mlx, "tiles/floor.xpm", \
			&size_x, &size_y);
	game->img.floor.addr = mlx_get_data_addr(game->img.floor.img, \
			&game->img.floor.bits_per_pixel, &game->img.floor.line_length, \
			&game->img.floor.endian);
}

void	load_img(t_win *game)
{
	load_hero(game, ELEM_SIZE_X, ELEM_SIZE_Y); 
	load_decor(game, ELEM_SIZE_X, ELEM_SIZE_Y); 
	add_background_img(game, &game->img.hero); 
	add_background_img(game, &game->img.hero_left); 
	add_background_img(game, &game->img.hero_right); 
	add_background_img(game, &game->img.hero_back);
	add_background_img(game, &game->img.item);
	add_background_img(game, &game->img.exit);
	add_background_img(game, &game->img.wall);
}
