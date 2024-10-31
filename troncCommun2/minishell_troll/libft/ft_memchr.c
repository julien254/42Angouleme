/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:59:19 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/08 16:24:04 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;
	unsigned char	y;

	s2 = (unsigned char *)s;
	i = 0;
	y = (unsigned char)c;
	while (i < n)
	{
		if (s2[i] == y)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
