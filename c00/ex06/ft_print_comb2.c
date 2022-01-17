/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:21:11 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/17 15:46:49 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* Function to control if the num is the last or not and call ft_putchar */
void	ft_control_and_print(int a, int b)
{
	if (a == 98 && b == 99)
	{
		ft_putchar(48 + a / 10);
		ft_putchar(48 + a % 10);
		ft_putchar(' ');
		ft_putchar(48 + b / 10);
		ft_putchar(48 + b % 10);
	}
	else
	{
		ft_putchar(48 + a / 10);
		ft_putchar(48 + a % 10);
		ft_putchar(' ');
		ft_putchar(48 + b / 10);
		ft_putchar(48 + b % 10);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_control_and_print(a, b);
			b++;
		}
		a++;
	}	
}
