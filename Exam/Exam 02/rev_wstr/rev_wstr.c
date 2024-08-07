/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 03:10:25 by judetre           #+#    #+#             */
/*   Updated: 2024/08/07 04:01:59 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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
	int i;
	int size_word;


	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		size_word = 0;
		str = argv[1];
		i = 0;
		while (str[i])
			i++;
		i--;
		while (i >= 0)
		{
			while (i > 0 && str[i] != ' ' && str[i] != '\t')
			{
				i--;
				size_word++;
			}
			if (i == 0)
				write(1, &str[i] , size_word + 1);
			else
				write(1, &str[i + 1] , size_word);
			size_word = 0;
			if (i != 0)
				write(1, " ", 1);
			i--;
		}
		write(1, "\n", 1);
	}
	return (0);
}
