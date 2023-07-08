/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:40:06 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/05 12:04:46 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	f_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		f_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr < 10)
	{
		f_putchar('0' + nbr);
	}
	else
	{
		ft_putnbr(nbr / 10);
		f_putchar('0' + nbr % 10);
	}
}
