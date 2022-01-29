/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:00:15 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/27 19:43:12 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	diff = 0;
	while (s1[i] != '\0')
	{
		diff = s1[i] - s2[i];
		if (diff == 0)
		{
			i++;
			continue ;
		}
		else
			return (diff);
	}
	diff = s1[i] - s2[i];
	return (diff);
}
/*
int	main()
{
	printf("%d",ft_strcmp("lol c'est la ", "lol c'est la meme"));
}*/
