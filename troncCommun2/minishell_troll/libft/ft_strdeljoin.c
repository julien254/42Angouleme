/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeljoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:51:20 by uguidoni          #+#    #+#             */
/*   Updated: 2024/05/14 16:32:40 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdeljoin(char *s1, char *s2)
{
	char	*str;
	size_t	n;
	size_t	m;

	n = 0;
	m = 0;
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[n])
	{
		str[n] = s1[n];
		n++;
	}
	while (n < (ft_strlen(s1) + ft_strlen(s2)))
		str[n++] = s2[m++];
	str[n] = 0;
	free(s1);
	free(s2);
	return (str);
}
