/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:25:25 by judetre           #+#    #+#             */
/*   Updated: 2024/07/31 16:27:56 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_lst_lst	*lst_lstlast(t_lst_lst *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (0);
}

void	lstlstadd_back(t_lst_lst **lst, t_lst_lst *neW)
{
	t_lst_lst	*last;

	if (!(*lst))
		*lst = neW;
	else
	{
		last = lst_lstlast(*lst);
		last->next = neW;
	}
}

t_lst_lst	*lst_lstnew(t_lst_near **near, t_win *game)
{
	t_lst_lst	*lst;

	lst = (t_lst_lst *)malloc(sizeof(t_lst_lst));
	if (!lst)
	{
		free(*near);
		exit_failure(ERR_MALLOC, STR_ERR_MALLOC, game);
	}
	lst->near = *near ;
	lst->next = NULL;
	return (lst);
}
