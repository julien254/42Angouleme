/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:47:04 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/08 10:01:28 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	destsize;
	size_t	srcsize;

	i = 0;
	j = 0;
	if (dest == NULL && n == 0)
		return (ft_strlen(src));
	destsize = ft_strlen(dest);
	srcsize = ft_strlen(src);
	if (n == 0)
		return (srcsize);
	while (dest[i] != '\0' && i < n)
		i++;
	while (src[j] != '\0' && i < n - 1)
		dest[i++] = src[j++];
	if (n != 0 && n >= destsize)
		dest[i] = '\0';
	if (n < destsize)
		return (srcsize + n);
	return (srcsize + destsize);
}
