/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:58:18 by julien            #+#    #+#             */
/*   Updated: 2022/03/18 18:47:08 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}*/

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

/*int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char	*src;
	char	dest[10];
	
	src = "la petite";
	ft_strcpy(dest, src);
	ft_putstr(dest);
	return (0);
}*/
