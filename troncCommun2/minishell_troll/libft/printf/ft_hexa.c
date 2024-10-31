/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:06:30 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/22 14:13:55 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_base_lower(unsigned int nb, int len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	write(1, &hexa[nb], 1);
	len++;
	return (len);
}

int	ft_putnbr_base_lower(unsigned int nb, int len)
{
	if (nb < 16)
	{
		len = ft_putchar_base_lower(nb, len);
		return (len);
	}
	if (nb >= 16)
	{
		len = ft_putnbr_base_lower(nb / 16, len);
		nb = nb % 16;
		len = ft_putchar_base_lower(nb, len);
	}
	return (len);
}

static int	ft_putchar_base_upper(unsigned int nb, int len)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	write(1, &hexa[nb], 1);
	len++;
	return (len);
}

int	ft_putnbr_base_upper(unsigned int nb, int len)
{
	if (nb < 16)
	{
		len = ft_putchar_base_upper(nb, len);
		return (len);
	}
	if (nb >= 16)
	{
		len = ft_putnbr_base_upper(nb / 16, len);
		nb = nb % 16;
		len = ft_putchar_base_upper(nb, len);
	}
	return (len);
}
