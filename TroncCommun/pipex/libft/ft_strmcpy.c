/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:12:26 by julien            #+#    #+#             */
/*   Updated: 2022/09/17 06:56:14 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmcpy(const char *src)
{
	size_t	i;
	size_t	size;
	char	*str;

	size = ft_strlen(src);
	str = (char *)malloc(size + 1);
	i = 0;
	if (size > 0)
	{
		while (i < size)
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
