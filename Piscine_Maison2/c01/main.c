/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:59:06 by judetre           #+#    #+#             */
/*   Updated: 2023/07/11 22:43:51 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr < 10)
	{
		ft_putchar('0' + nbr);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar('0' + nbr % 10);
	}
}


void	ft_put_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		if (i == size - 1)
			ft_putchar('.');
		else
			ft_putchar(',');
		i++;
	}
	ft_putchar('\n');
}

void	ft_sort_int_tab(int *tab, int size);

int	main(int argc, char *argv[])
{
	int	tab[10] = {12, 4, 7, 321, 0, -1, 0, 72, 42, 2};
	(void)argc;
	(void)argv;
	ft_sort_int_tab(tab, 10);
	ft_put_tab(tab, 10);
	return (0);
}
