/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:17:08 by julien            #+#    #+#             */
/*   Updated: 2022/04/16 08:57:19 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	searchc(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	start = 0;
	if (set[0] == '\0')
		return (ft_strdup(s1));
	while (searchc(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (searchc(s1[end], set))
		end--;
	if (end == 18446744073709551615UL && start == ft_strlen(s1))
		return ((char *)ft_calloc(sizeof(char), 1));
	str = (char *)ft_calloc((end + 1 - start) + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end + 1)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
