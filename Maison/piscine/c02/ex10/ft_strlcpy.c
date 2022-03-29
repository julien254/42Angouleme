/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:43:23 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/26 12:48:57 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	j = i;
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (j);
}
/*int	main(void)
{
	char	dest[20];
	char	src[] = "lol c'est ouf !";

	printf("%d", ft_strlcpy(dest, src, 20));
}*/
