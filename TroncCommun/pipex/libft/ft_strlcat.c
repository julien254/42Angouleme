/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:12:26 by julien            #+#    #+#             */
/*   Updated: 2022/04/09 02:26:11 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = dstlen;
	if (dstlen < size - 1 && size > 0)
	{
		j = 0;
		while (i < size - 1 && src[j])
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	if (dstlen > size)
		dstlen = size;
	return (srclen + dstlen);
}
