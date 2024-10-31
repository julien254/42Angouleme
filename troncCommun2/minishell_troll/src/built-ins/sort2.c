/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:42:23 by gcannaud          #+#    #+#             */
/*   Updated: 2024/06/19 13:04:41 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_sort	*indexsort(t_sort *lst)
{
	int		c;
	t_sort	*first;
	t_sort	*index;

	c = 0;
	first = lst;
	index = lst;
	while (lst)
	{
		while (index)
		{
			if (ft_strcmp(index->content, lst->content) <= 0)
				c++;
			index = index->next;
		}
		lst->index = c;
		c = 0;
		index = first;
		lst = lst->next;
	}
	return (first);
}

t_sort	*ft_tabtolst(char **tab)
{
	t_sort	*lst;
	int		i;

	i = 0;
	lst = ft_sortnew(tab[i]);
	i++;
	while (tab[i])
	{
		ft_sortadd_back(&lst, ft_sortnew(tab[i]));
		i++;
	}
	return (lst);
}

void	ft_freetab_content(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

char	**ft_sort_export(char **tab)
{
	t_sort	*lst;
	t_sort	*lst_first;
	int		i;
	int		x;

	x = 1;
	i = 0;
	lst = ft_tabtolst(tab);
	ft_freetab_content(tab);
	lst = indexsort(lst);
	lst_first = lst;
	while (lst)
	{
		if (lst->index == x)
		{
			tab[i++] = ft_strdup(lst->content);
			x++;
			lst = lst_first;
		}
		else
			lst = lst->next;
	}
	lst = lst_first;
	ft_sortfree(&lst);
	return (tab);
}
