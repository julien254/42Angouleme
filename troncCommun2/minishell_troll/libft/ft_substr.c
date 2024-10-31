/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:46:19 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/08 15:17:10 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			len_m;
	char			*str;

	if (!s)
		return (NULL);
	len_m = ft_strlen(s) - start;
	if (len_m >= len)
		len_m = len;
	if (start > ft_strlen(s))
		len_m = 0;
	str = malloc(len_m + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len_m)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
