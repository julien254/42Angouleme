/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:11:26 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/26 15:22:14 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	y;

	i = 0;
	y = (unsigned char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == y)
			return ((char *)&s[i]);
		i++;
	}
	if (y == 0)
		return ((char *)&s[i]);
	return (NULL);
}
