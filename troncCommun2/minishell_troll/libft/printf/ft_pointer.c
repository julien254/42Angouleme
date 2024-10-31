/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:59:48 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/22 15:35:24 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_pointer(unsigned long long nb, int len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	write(1, &hexa[nb], 1);
	len++;
	return (len);
}

static int	ft_putnbr_pointer(unsigned long long nb, int len)
{
	if (nb < 16)
	{
		len = ft_putchar_pointer(nb, len);
		return (len);
	}
	if (nb >= 16)
	{
		len = ft_putnbr_pointer(nb / 16, len);
		nb = nb % 16;
		len = ft_putchar_pointer(nb, len);
	}
	return (len);
}

int	ft_pointer(int *ptr, int len)
{
	if (!ptr)
		return (ft_putstr("(nil)", len));
	write(1, "0x", 2);
	len += ft_putnbr_pointer((unsigned long long)ptr, len);
	len += 2;
	return (len);
}
