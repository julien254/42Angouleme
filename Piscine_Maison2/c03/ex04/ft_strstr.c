/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:37:48 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/02 11:01:22 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (to_find[i])
		{
			if (str[i] != to_find[i])
				break;
			i++;
		}
		if (to_find[i] == '\0')
			return (str);
		else
			str++;
	}
	return (NULL);
}
