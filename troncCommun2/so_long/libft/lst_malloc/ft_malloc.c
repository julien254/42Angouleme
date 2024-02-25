/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:28:32 by judetre           #+#    #+#             */
/*   Updated: 2024/02/25 22:02:00 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(t_list_malloc **lst_malloc, char *function, ...)
{
	void	*ptr;

	if (!lst_malloc)
		return (NULL);
	ptr = (void *)malloc(size);
	if (!ptr)
		return (NULL); 
	return (ptr);
}
