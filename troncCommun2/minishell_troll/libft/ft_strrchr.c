/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:34:38 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/14 06:39:11 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				stock;
	unsigned char	c2;

	i = 0;
	stock = -1;
	c2 = c;
	while (s[i] != '\0')
	{
		if (s[i] == c2)
			stock = i;
		i++;
	}
	if (s[i] == '\0' && c2 == '\0')
		return ((char *)s + i);
	if (stock != -1)
		return ((char *)s + stock);
	return (0);
}
