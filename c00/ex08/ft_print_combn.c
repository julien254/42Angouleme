/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:31:02 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/20 09:33:17 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_tab(int n, int holders[])
{
	int	index;
	int	last;

	index = 0;
	while (index < n)
	{
		ft_putchar(48 + holders[index]);
		index++;
	}
	index = n - 1;
	last = 1;
	while (index >= 0)
	{
		if (holders[index] != 9 - (n - 1 - index))
		{
			last = 0;
			break ;
		}
		index--;
	}
	if (!last)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void    ft_recurcive(int *tab, int n, int num, int niveau)
{
        int next_num;
        if (niveau == n)
                ft_write_tab(n, tab);
        else
        {
                next_num = num + 1;
                while (next_num <= 9)
                {
                        tab[niveau] = next_num;
                        ft_recurcive(tab, n, next_num, niveau + 1);
                        next_num++;
                }
        }
}	


void	ft_print_combn(int n)
{
	int tab[n];
	int i;

	i = 0;
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
	ft_recurcive(tab, n, -1, 0);
}

int main(void)
{
	ft_print_combn(9);
}
