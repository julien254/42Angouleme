/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:59:56 by julien            #+#    #+#             */
/*   Updated: 2022/10/09 06:21:32 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	choose_free(int errno, t_lst_img *boximg)
{
	if (errno == ERRFORM)
		free(boximg->map->strmap);
	if (errno == ERRWALL || errno == ERRCHAR || errno == ERRELEM)
	{
		free(boximg->map->strmap);
		free_map2d((void *)boximg->map2d, boximg->map->nbr_of_line);
	}
	if (errno == ERREXIT || errno == ERRITEM)
		end_game(boximg);
}

void	return_err(int errno, t_map *map, t_lst_img *boximg)
{
	if (errno == ERRFORM)
		write(2, "Error\nThe map is not a rectangle.\n", 34);
	else if (errno == ERRWALL)
		write(2, "Error\nThe map is not surrounded by walls.\n", 43);
	else if (errno == ERRCHAR)
		write(2, "Error\nthe map contains wrong characters.\n", 42);
	else if (errno == ERRELEM)
	{
		write(2, "Error\n", 6);
		if (map->pos != 1)
			write(2, "No or too many starting position.\n", 34);
		if (map->exit != 1)
			write(2, "No or too many exit.\n", 21);
		if (map->item == 0)
			write(2, "No item.\n", 9);
	}
	else if (errno == ERREXIT)
		write(2, "Error\nThe exit is not accessible.\n", 34);
	else if (errno == ERRITEM)
		write(2, "Error\nOne or more item is not accessible.\n", 42);
	else if (errno == ERRARGV)
		write(2, "Error\nToo few or more arguments.\n", 33);
	choose_free(errno, boximg);
	exit(EXIT_FAILURE);
}
