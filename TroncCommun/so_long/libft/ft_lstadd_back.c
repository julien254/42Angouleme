/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:08:23 by julien            #+#    #+#             */
/*   Updated: 2022/04/12 20:35:00 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *neW)
{
	t_list	*last;

	if (!(*lst))
		*lst = neW;
	else
	{
		last = ft_lstlast(*lst);
		last->next = neW;
	}
}
