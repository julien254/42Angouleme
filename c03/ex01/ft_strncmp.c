/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:00:15 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/27 20:31:35 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				d;

	i = 0;
	d = 0;
	while (s1[i] != '\0' && i < n)
	{
		d = s1[i] - s2[i];
		if (d == 0)
		{
			i++;
			continue ;
		}
		else
			return (d);
	}
	if (s1[i] == '\0')
		d = s1[i] - s2[i];
	return (d);
}
/*
int	main()
{
	printf("%d",ft_strncmp("lol c'zst la meme", "lol c'est la meme", 7));
}*/
