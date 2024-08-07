/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:19:35 by judetre           #+#    #+#             */
/*   Updated: 2024/08/07 04:39:49 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int check_arg(char *c, char *replace)
{
	if (ft_strlen(c) != 1 || ft_strlen(replace) != 1)
		return (0);
	return (1);
}
int	main(int argc, char *argv[])
{
	char *str;
	char c;
	char replace;
	if (argc != 4 || check_arg(argv[2], argv[3]) == 0)
		write(1, "\n", 1);
	else
	{
		str = argv[1];
		c = argv[2][0];
		replace = argv[3][0];
		while (*str)
		{
			if (*str == c)
				*str = replace;
			write(1, str, 1);
			str++;
		}
		write(1, "\n", 1);
	}
	
	return (0);
}
