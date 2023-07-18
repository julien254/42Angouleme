/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:28:22 by judetre           #+#    #+#             */
/*   Updated: 2023/07/18 15:19:50 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_tab(int *tab)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	write(1, "\n", 1);
}

int	pos_is_good(int *tab, int posx)
{
	int	i;
	int j;

	i = posx - 1;
	j = 1;
	while (i >= 0)
	{
		if (tab[posx] == tab[i] || tab[posx] == tab[i] + j || tab[posx] == tab[i] - j)
			return (0);
		i--;
		j++;
	}
		return (1);
}

void	recursive(int *tab, int posx, int *count)
{
	int	i;

	if (posx == 10)
	{
		ft_write_tab(tab);
		*count = *count + 1;
	}
	else
	{
		i = 0;
		while (i < 10)
		{
			tab[posx] = i;
			if (pos_is_good(tab, posx))
				recursive(tab, posx + 1, count);
			i++;
		}
	}

}

int	ft_ten_queens_puzzle(void)
{
	int	tab[10] = {0,0,0,0,0,0,0,0,0,0};
	int	i;
	int	count;

	count = 0;
	i = 0;
	recursive(tab, i, &count);
	return (count);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_ten_queens_puzzle();
	return (0);
}
