/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:22:14 by julien            #+#    #+#             */
/*   Updated: 2022/10/18 18:11:12 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size > 4294967295 || nmemb > 4294967295)
		return (NULL);
	ptr = malloc(nmemb * size);
	ft_verif_malloc(ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
