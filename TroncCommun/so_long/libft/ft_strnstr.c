/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:42:45 by julien            #+#    #+#             */
/*   Updated: 2022/04/10 21:38:56 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] != '\0')
	{
		i = 0;
		while (i < len && big[i])
		{
			j = 0;
			while (little[j] && i + j < len)
			{
				if (big[i + j] == little[j])
				{
					j++;
					continue ;
				}
				break ;
			}
			if (little[j] == '\0')
				return ((char *)(big + i));
			i++;
		}
		return (NULL);
	}
	return ((char *)big);
}
