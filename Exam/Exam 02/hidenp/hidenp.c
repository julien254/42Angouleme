/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 02:32:21 by judetre           #+#    #+#             */
/*   Updated: 2024/08/07 03:07:56 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	char *str;
	char *str2;
	int	i_str;
	int i_str2;
	int size;
	int count;
	int tmp;

	count = 0;
	tmp = 0;
	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		str = argv[1];
		str2 = argv[2];
		size = ft_strlen(argv[1]);
		if (size == 0)
			write(1, "1\n", 2);
		i_str = 0;
		while (str[i_str])
		{
			i_str2 = tmp;
			while (str2[i_str2])
			{
				if (str[i_str] == str2[i_str2])
				{
					count++;
					i_str2++;
					tmp = i_str2;
					break ;
				}
				else
					i_str2++;
			}
			i_str++;
		}
		if (count == size)
			write(1, "1\n", 2);
		else
			write(1, "0\n", 2);
	}

	return (0);
}
