/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:26:04 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/08 17:48:54 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trim(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (*s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1) - 1;
	while (ft_trim(&s1[len], set) == 1)
		len--;
	i = 0;
	while (ft_trim(&s1[i], set) == 1)
		i++;
	str = ft_substr(s1, i, (len - i) + 1);
	return (str);
}
