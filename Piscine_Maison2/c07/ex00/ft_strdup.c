/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:48:05 by judetre           #+#    #+#             */
/*   Updated: 2023/07/25 16:36:40 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
	{
	int	i;

	i = 0;
	while (src[i])
		{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		size;

	size = ft_strlen(src);
	str = (char *)malloc(size + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, src);
	return (str);
}
#include <stdio.h>
int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char	*str;
	str = ft_strdup("salut les amies");
	printf("%s", str);
	free(str);
	return (0);
}
