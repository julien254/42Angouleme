/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:27:27 by judetre           #+#    #+#             */
/*   Updated: 2023/07/17 00:30:40 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	tcheck;

	while (*str)
	{
		i = 0;
		tcheck = 1;
		while (to_find[i] && tcheck)
		{
			if (str[i] != to_find[i])
				tcheck = 0;
			if (tcheck)
				i++;
		}
		if (tcheck)
			return (str);
		else
			str++;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char *str;
	char *str2;
	str = ft_strstr("salut tous le monde lol" , "mqnde");
	str2 = strstr("salut tous le monde lol" , "mqnde");
	if (str == NULL)
		write(1, "NULL", 4);
	else
		printf("%s\n", str);
	if (str2 == NULL)
		write(1, "NULL", 4);
	else
		printf("%s\n", str2);
	return (0);
}
