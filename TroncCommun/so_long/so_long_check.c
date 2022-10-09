/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:23:09 by julien            #+#    #+#             */
/*   Updated: 2022/10/09 05:16:55 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_if_is_wall(char *hero_pos)
{
	if (*hero_pos == '1')
		return (1);
	return (0);
}

static void	check_if_is_item(t_map *map, char *hero_pos)
{
	if (*hero_pos == 'C')
	{
		map->item_found++;
		*hero_pos = '0';
	}
}

static int	check_if_is_exit(t_map *map, char *hero_pos, t_lst_img *boximg)
{
	if (*hero_pos == 'E' && map->item == map->item_found)
		end_game(boximg);
	else if (*hero_pos == 'E')
		return (1);
	return (0);
}

int	check_if_is(t_lst_img *boximg, t_map *map, char *hero_pos)
{
	check_if_is_item(map, hero_pos);
	if (check_if_is_exit(map, hero_pos, boximg))
		return (1);
	return (check_if_is_wall(hero_pos));
}
