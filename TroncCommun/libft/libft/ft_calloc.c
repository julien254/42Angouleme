/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:22:14 by julien            #+#    #+#             */
/*   Updated: 2023/11/03 17:08:52 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*ptr;
	unsigned long long	siz;
	
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (((long long)nmemb) < 0 || ((long long)size) < 0)
		return (NULL);
	siz = nmemb * size;
	if (siz > SIZE_MAX)
		return (NULL);
	ptr = malloc(siz);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, siz);
	return (ptr);
}
