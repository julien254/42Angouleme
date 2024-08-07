/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:45:55 by judetre           #+#    #+#             */
/*   Updated: 2024/08/06 09:08:54 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int recup_index_lower(char a)
{
	int	i;
	char car;

	car = 'a';
	i = 1;
	while (car <= a)
	{
		if (a == car)
			return (i);
		i++;
		car++;
	}
	return (0);
}

int recup_index_upper(char a)
{
	int	i;
	char car;
	car = 'A';
	i = 1;
	while (car <= a)
	{
		if (a == car)
			return (i);
		i++;
		car++;
	}
	return (0);
}

void	repeat_alpha(char *str)
{
	int	i;
	int	index;
	int j;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			index = recup_index_lower(str[i]);
			j = 0;
			while (j < index)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			index = recup_index_upper(str[i]);
			j = 0;
			while (j < index)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
int	main(int argc, char *argv[])
{
	(void)argc;
	if (argc != 2)
		write(1, "\n", 1);
	else
		repeat_alpha(argv[1]);
	return (0);
}
