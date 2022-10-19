/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:23:09 by julien            #+#    #+#             */
/*   Updated: 2022/10/13 21:15:00 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	printmap(char **map2d, t_lst_img *boximg)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (map2d[i])
	{
		choose_img(boximg, map2d[i], y);
		y += TILESIZE_Y;
		i++;
	}
}

static void	loop1(char *line_map2d, t_map *map, t_lst_img *boximg)
{
	int	x;

	x = 0;
	while (line_map2d[x])
	{
		if (line_map2d[x++] != '1')
			return_err(ERRWALL, map, boximg);
	}
}

static void	loop2(char *line_map2d, t_map *map, t_lst_img *boximg, int *y)
{
	int	x;

	x = 0;
	while (line_map2d[x])
	{
		if ((x == 0 && line_map2d[x] != '1') || \
				(x == map->size_line && line_map2d[x] != '1'))
			return_err(ERRWALL, map, boximg);
		else if (line_map2d[x] == 'P')
		{
			map->pos++;
			boximg->pos_hero_x = x;
			boximg->map2d_int_x = x * TILESIZE_X;
			boximg->pos_hero_y = *y;
			boximg->map2d_int_y = *y * TILESIZE_Y;
		}
		else if (line_map2d[x] == 'C')
			map->item++;
		else if (line_map2d[x] == 'E')
			set_exit(map, x, *y);
		else if (line_map2d[x] != '0' && line_map2d[x] != '1')
			return_err(ERRCHAR, map, boximg);
		x++;
	}
}

void	make_map(char *map_name, t_map *map, t_lst_img *boximg)
{
	int		y;

	map->strmap = ft_recover_fd(map_name);
	if (!map->strmap)
	{
		write(2, "Error\nMap not found.\n", 21);
		exit(EXIT_FAILURE);
	}
	boximg->map = map;
	init_map(map, map->strmap, boximg);
	if (map->nbr_of_line < 2)
		return_err(ERRFORM, map, boximg);
	boximg->map2d = ft_split(map->strmap, '\n');
	y = 0;
	loop1(boximg->map2d[y], map, boximg);
	y++;
	while (y != map->nbr_of_line - 1)
	{
		loop2(boximg->map2d[y], map, boximg, &y);
		y++;
	}
	loop1(boximg->map2d[y], map, boximg);
	if (map->pos != 1 || map->exit != 1 || map->item == 0)
		return_err(ERRELEM, map, boximg);
	free(map->strmap);
}
