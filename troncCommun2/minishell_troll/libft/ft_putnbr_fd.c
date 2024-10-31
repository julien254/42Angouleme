/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:34:29 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/06 14:54:37 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	temp;
	int	temp2;

	if (n == -2147483647 - 1)
		write(fd, "-2147483648", 11);
	else if (n >= 0 && n < 10)
	{
		temp = n + '0';
		write(fd, &temp, 1);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		temp2 = n % 10 + '0';
		write(fd, &temp2, 1);
	}
}
