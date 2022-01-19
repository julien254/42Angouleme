/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:31:02 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/17 14:09:37 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
}

void	ft_sort_int_tab(int *tab, int size)
{
	int temptab[size];
	int i;
	int index;
	int lowest;
	int highest;	
	
	i = 0;
	highest = tab[0];
	while (i < size)
	{
		if (tab[i] > highest)
                        highest = tab[i];
		temptab[i] = tab[i];
		i++;
	}
	i = 0;
	lowest = temptab[0];
	while (i < size)
	{
		int j;
		j = 0 ;
		while (j < size)
	        {
        	        if (temptab[j] <= lowest)
			{
                	        lowest = temptab[j];
				index = j;
			}
			j++;
		}
		tab[i] = lowest;
		lowest = highest;
		temptab[index] = highest;
		i++;
	}
}

int	main(void)
{
	int tab[10];

	tab[0] = 4;
	tab[1] = 2;
	tab[2] = 8;
	tab[3] = 9;
	tab[4] = 0;
	tab[5] = 1;
	tab[6] = 3;
	tab[7] = 7;
	tab[8] = 6;
	tab[9] = 5;
	ft_putnbr(tab[0]);
	ft_putnbr(tab[1]);
	ft_putnbr(tab[2]);
	ft_putnbr(tab[3]);
	ft_putnbr(tab[4]);
	ft_putnbr(tab[5]);
	ft_putnbr(tab[6]);
	ft_putnbr(tab[7]);
	ft_putnbr(tab[8]);
	ft_putnbr(tab[9]);
	ft_sort_int_tab(tab, 10);
	ft_putnbr(tab[0]);
	ft_putnbr(tab[1]);
	ft_putnbr(tab[2]);
	ft_putnbr(tab[3]);
	ft_putnbr(tab[4]);
	ft_putnbr(tab[5]);
	ft_putnbr(tab[6]);
	ft_putnbr(tab[7]);
	ft_putnbr(tab[8]);
	ft_putnbr(tab[9]);
}
