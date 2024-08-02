/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_near_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:30:06 by judetre           #+#    #+#             */
/*   Updated: 2024/07/31 16:42:15 by judetre          ###   ########.fr       */
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

void	lstadd_back(t_lst_near **lst, t_lst_near *new)
{
	t_lst_near	*last;

	if (!(*lst))
		*lst = new;
	else
	{
		last = lstlast(*lst);
		last->next = new;
	}
}

t_lst_near	*lstnew(int y, int x, int *value, t_win *game)
{
	t_lst_near	*list;

	list = (t_lst_near *)malloc(sizeof(t_lst_near));
	if (!list)
		exit_failure(ERR_MALLOC, STR_ERR_MALLOC, game);
	list->x = x;
	list->y = y;
	list->value = value;
	list->next = NULL;
	return (list);
}
