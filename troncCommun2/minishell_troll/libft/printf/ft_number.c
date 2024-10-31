/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:44:29 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/22 15:00:21 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isnegative(int len)
{
	write(1, "-", 1);
	len++;
	return (len);
}

static int	ft_intmin(int len)
{
	write(1, "-2147483648", 11);
	len += 11;
	return (len);
}

int	ft_putnbr(int nb, int len)
{
	int	temp;
	int	temp2;

	if (nb == -2147483647 - 1)
		len = ft_intmin(len);
	else if ((nb >= 0 && nb < 10) && nb != -2147483648)
	{
		temp = nb + '0';
		write(1, &temp, 1);
		len++;
		return (len);
	}
	else if ((nb < 0) && nb != -2147483648)
	{
		len = ft_isnegative(len);
		len = ft_putnbr(-nb, len);
	}
	else if ((nb > 9) && nb != -2147483648)
	{
		len = ft_putnbr(nb / 10, len);
		temp2 = nb % 10 + '0';
		write(1, &temp2, 1);
		len++;
	}
	return (len);
}

int	ft_unsigned_putnbr(unsigned int nb, int len)
{
	int	temp;
	int	temp2;

	if (nb >= 0 && nb < 10)
	{
		temp = nb + '0';
		write(1, &temp, 1);
		len++;
	}
	else if (nb > 9)
	{
		len = ft_putnbr(nb / 10, len);
		temp2 = nb % 10 + '0';
		write(1, &temp2, 1);
		len++;
	}
	return (len);
}
