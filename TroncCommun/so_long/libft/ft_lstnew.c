/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:00:41 by julien            #+#    #+#             */
/*   Updated: 2022/10/08 16:49:51 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)ft_calloc(sizeof(t_list), 1);
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
