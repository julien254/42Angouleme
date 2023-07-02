/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:55:25 by jdetre            #+#    #+#             */
/*   Updated: 2023/06/18 18:33:13 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>


void	ptchar(char c)
{
	write(1, &c, 1);
}

void	print_int(int a, int b)
{
	if (a == 98)
	{
		ptchar('0' + a / 10);
		ptchar('0' + a % 10);
		ptchar(' ');
		ptchar('0' + b / 10);
		ptchar('0' + b % 10);
	}
	else
	{
		ptchar('0' + a / 10);
		ptchar('0' + a % 10);
		ptchar(' ');
		ptchar('0' + b / 10);
		ptchar('0' + b % 10);
		ptchar(',');
		ptchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_int(a, b);
			b++;
		}
		a++;
	}
}
