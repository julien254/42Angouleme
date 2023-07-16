/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:27:27 by judetre           #+#    #+#             */
/*   Updated: 2023/07/15 09:42:33 by judetre          ###   ########.fr       */
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
				break ;
			i++;
		}
		if (to_find[i] == '\0')
			return (str);
		else
			str++;
	}
	return (NULL);
}
