/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:22:14 by julien            #+#    #+#             */
/*   Updated: 2022/04/14 20:50:31 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	if (nmemb > 0 && size > 0 && (nmemb * size != 1 || (nmemb == 1 && size == 1)))
	{		ptr = (char *)malloc(nmemb * size);
		if (!ptr)
			return (NULL);
		i = 0;
		while (i < nmemb)
			ptr[i++] = '\0';
		return ((void *)ptr);
	}
	return (NULL);
}
