/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:10:44 by julien            #+#    #+#             */
/*   Updated: 2022/10/09 04:21:33 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_exit(t_map *map, int x, int y)
{
	map->exit++;
	map->x_exit = x;
	map->y_exit = y;
}

int	cmp_line_size(char *str, t_map *map, t_lst_img *boximg)
{
	int	i;
	int	size_line;
	int	j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	size_line = i;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != '\n' && str[i])
		{
			j++;
			i++;
		}
		if (str[i] == '\n')
			i++;
		if (j != size_line)
			return_err(ERRFORM, map, boximg);
	}
	return (size_line);
}
