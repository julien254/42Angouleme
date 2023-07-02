/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:21:33 by julien            #+#    #+#             */
/*   Updated: 2022/03/23 17:43:13 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb <= 9)
	{
		ft_putchar('0' + nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar('0' + nb % 10);
	}
}

void	init_ab(int *ab)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ab[i] = 0;
		i++;
	}
}

void	cond1_print(int *ab, int i)
{
	if (ab[i] < 10)
	{
		ft_putchar('0');
		ft_putnbr(ab[i]);
	}
	else
		ft_putnbr(ab[i]);
}

void	cond2_print(int *ab, int i)
{
	if (ab[i] < 10)
	{
		ft_putchar('0');
		ft_putnbr(ab[i]);
		ft_putchar(' ');
	}
	else
	{
		ft_putnbr(ab[i]);
		ft_putchar(' ');
	}
}

void	cond3_print(int *ab, int i)
{
	if (ab[i] < 10)
	{
		ft_putchar('0');
		ft_putnbr(ab[i]);
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(ab[i]);
		ft_putchar('\n');
	}
}

void	cond4_print(int *ab, int i)
{
	if (ab[i] < 10)
	{
		ft_putchar('0');
		ft_putnbr(ab[i]);
		ft_putchar(' ');
	}
	else
	{
		ft_putnbr(ab[i]);
		ft_putchar(' ');
	}
}

void	cond_if(int *ab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i == n - 1)
		{
			cond1_print(ab, i);
		}
		else
		{
			cond2_print(ab, i);
		}
		i++;
	}
}

void	cond_else(int *ab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i == n - 1)
		{
			cond3_print(ab, i);
		}
		else
		{
			cond4_print(ab, i);
		}
		i++;
	}
}

void	ft_control_and_print(int *ab, int n)
{
	if (ab[n - 1] == 99 && ab[0] == 100 - n)
	{
		cond_if(ab, n);
	}
	else
	{
		cond_else(ab, n);
	}
}

void	ft_recurcive(int *ab, int courant_num, int niveau, int n)
{
	int	next_num;

	if (niveau == n)
	{
		ft_control_and_print(ab, n);
	}
	else
	{
		next_num = courant_num + 1;
		while (next_num != 101 - (n - niveau))
		{
			ab[niveau] = next_num;
			ft_recurcive(ab, next_num, niveau + 1, n);
			next_num++;
		}
	}
}

void	ft_print_comb2n(int niveau)
{
	int	ab[100];
	init_ab(ab);
	ft_recurcive(ab, -1, 0, niveau);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_print_comb2n(2);
	return (0);
}
