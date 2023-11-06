/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:03:30 by judetre           #+#    #+#             */
/*   Updated: 2023/11/03 17:33:50 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n <= 9 && n != -2147483648)
		ft_putchar_fd('0' + n, fd);
	else
	{
		ft_putnbr_fd(ft_abs(n / 10), fd);
		ft_putchar_fd('0' + ft_abs(n % 10), fd);
	}
}
