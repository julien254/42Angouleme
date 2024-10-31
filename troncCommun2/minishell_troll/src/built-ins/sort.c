/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:42:16 by gcannaud          #+#    #+#             */
/*   Updated: 2024/06/19 13:04:41 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_sort	*ft_sortnew(char *content)
{
	t_sort	*p;

	p = 0;
	p = malloc(sizeof(t_sort) * 1);
	if (p == NULL)
		return (NULL);
	p->content = ft_strdup(content);
	p->index = 0;
	p->next = NULL;
	return (p);
}

t_sort	*ft_sortlast(t_sort *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_sortadd_back(t_sort **lst, t_sort *new)
{
	t_sort	*tmp;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		tmp = ft_sortlast(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
}

void	ft_sortfree(t_sort **lst)
{
	t_sort	*current;
	t_sort	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	r;

	i = 0;
	while (s1[i] == s2[i])
	{
		i++;
		if (s1[i] == 0 || s2[i] == 0)
		{
			return (0);
		}
	}
	r = s1[i] - s2[i];
	return (r);
}
