/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 02:01:47 by julien            #+#    #+#             */
/*   Updated: 2022/10/18 18:13:45 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lst_near	*lstlast(t_lst_near *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (0);
}

void	lstadd_back(t_lst_near **lst, t_lst_near *neW)
{
	t_lst_near	*last;

	if (!(*lst))
		*lst = neW;
	else
	{
		last = lstlast(*lst);
		last->next = neW;
	}
}

t_lst_near	*lstnew(int y, int x, int *value)
{
	t_lst_near	*list;

	list = (t_lst_near *)malloc(sizeof(t_lst_near));
	ft_verif_malloc(list);
	list->x = x;
	list->y = y;
	list->value = value;
	list->next = NULL;
	return (list);
}

t_lst_near	*recup_near(int **map2d_int, int y, int x)
{
	int			i;
	t_lst_near	*near;
	t_lst_near	*next_near;

	near = lstnew(y, x + 1, &map2d_int[y][x + 1]);
	i = 0;
	while (i < 3)
	{
		if (i == 0)
			next_near = lstnew(y, x - 1, &map2d_int[y][x - 1]);
		else if (i == 1)
			next_near = lstnew(y + 1, x, &map2d_int[y + 1][x]);
		else if (i == 2)
			next_near = lstnew(y - 1, x, &map2d_int[y - 1][x]);
		lstadd_back(&near, next_near);
		i++;
	}
	return (near);
}

int	verif_way(t_lst_img *boximg, int x, int y, int step)
{
	t_lst_near	*near;
	t_lst_near	*tmp;

	near = recup_near(boximg->map2d_int, y, x);
	while (near)
	{
		if (*near->value == 9996)
			boximg->item_found++;
		if (*near->value != 9999 && *near->value != 9997 && \
				*near->value > step + 1)
		{
			*near->value = step + 1;
			verif_way(boximg, near->x, near->y, step + 1);
		}
		else if (*near->value == 9997)
			boximg->exit_found = 0;
		tmp = near;
		near = near->next;
		free(tmp);
	}
	if (boximg->exit_found == 0)
		return (0);
	return (1);
}
