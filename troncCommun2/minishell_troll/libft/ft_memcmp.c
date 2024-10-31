/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:45:26 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/03 13:49:50 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cpys1;
	unsigned char	*cpys2;
	size_t			i;

	cpys1 = (unsigned char *)s1;
	cpys2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (cpys1[i] != cpys2[i])
			return (cpys1[i] - cpys2[i]);
		i++;
	}
	return (0);
}
