/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:21:12 by judetre           #+#    #+#             */
/*   Updated: 2024/08/07 01:16:53 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

void fill(char **tab, t_point size, char car, t_point current)
{
	if (current.x < 0 || current.y < 0 || current.x >= size.x || current.y >= size.y || tab[current.y][current.x] != car)
		return ;
	else
		tab[current.y][current.x] = 'F';
	fill(tab, size, car, (t_point){current.x + 1,current.y});
	fill(tab, size, car, (t_point){current.x ,current.y + 1});
	fill(tab, size, car, (t_point){current.x - 1, current.y});
	fill(tab, size, car, (t_point){current.x ,current.y - 1});
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char car;
	car = tab[begin.y][begin.x];
	fill(tab , size, car, begin);
}
