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

void	ft_print_num(int *tab,int n,int index)
{
	if (tab[index] < 9)
        {
		int i;

                i = 0;
                while (i < n)
                {
                        ft_putnbr(tab[i]);
                        i++;
                }
                ft_putchar('\n');
                tab[index]++;
                ft_print_num(tab, n, index);
        }
}

void	ft_print_combn(int n)
{
	int tab[n];
	int i;
	int index;
	//int last;
	
	i = 0;
	//last = n;
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
	ft_print_num(tab, n, index);
}

int main(void)
{
	ft_print_combn(5);
}
