/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:28:22 by judetre           #+#    #+#             */
/*   Updated: 2023/07/19 10:48:16 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_array(int *array)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(array[i] + '0');
		i++;
	}
	write(1, "\n", 1);
}

int	pos_is_good(int *array, int posx)
{
	int	i;
	int	j;

	i = posx - 1;
	j = 1;
	while (i >= 0)
	{
		if (array[posx] == array[i] || array[posx] == array[i] + j || \
												array[posx] == array[i] - j)
			return (0);
		i--;
		j++;
	}
	return (1);
}

void	recursive(int *array, int posx, int *count)
{
	int	i;

	if (posx == 10)
	{
		ft_write_array(array);
		*count = *count + 1;
	}
	else
	{
		i = 0;
		while (i < 10)
		{
			array[posx] = i;
			if (pos_is_good(array, posx))
				recursive(array, posx + 1, count);
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	array[10];
	int	i;
	int	count;

	count = 0;
	i = 0;
	recursive(array, i, &count);
	return (count);
}
