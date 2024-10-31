/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:55:02 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/22 13:42:45 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int len)
{
	write(1, &c, 1);
	len++;
	return (len);
}

int	ft_putstr(char *str, int len)
{
	size_t	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)", len));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		len++;
		i++;
	}
	return (len);
}
