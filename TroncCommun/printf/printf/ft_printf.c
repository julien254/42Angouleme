/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:02:01 by jdetre            #+#    #+#             */
/*   Updated: 2022/05/31 14:52:53 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int ft_print_arg(va_list *ap, char const *str, size_t i)
{
	int	len;

	len = 0;
	if (str[i + 1] == '%')
		len += write(1, "%", 1);
	else if (str[i + 1] == 'c')
		len += ft_putchar_fd(va_arg(*ap, int), 1);
	else if (str[i + 1] == 's')
		len += ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (str[i + 1] == 'i' || str[i + 1] == 'd')
		len += ft_putnbr_fd(va_arg(*ap, int), 1);
	else if (str[i + 1] == 'u')
		len += ft_put_u_nbr_fd(va_arg(*ap, unsigned int), 1);
	else if (str[i + 1] == 'x')
		len += ft_puthexa_fd(va_arg(*ap, unsigned int), 1, 0);
	else if (str[i + 1] == 'X')
		len += ft_puthexa_fd(va_arg(*ap, unsigned int), 1, 1);
	else if (str[i + 1] == 'p')
		len += ft_putadd_fd(va_arg(*ap, size_t), 1);
	return (len);
}

int ft_printf(const char *str, ...)
{
	t_ind	index;
	va_list	ap;
	int		ifarg;

	index.i = 0;
	index.lastindex = 0;
	index.count = 0;
	ifarg = 0;
	va_start(ap, str);
	while (str[index.i])
	{
		if (str[index.i] == '%')
		{
			ifarg = 1;
			index.count += write(1, str + index.lastindex, index.i - index.lastindex);
			index.count += ft_print_arg(&ap, str, index.i);
			index.lastindex = ++index.i + 1 ;
		}
		index.i++;
	}
	if (!ifarg)
		index.count += write(1, str, index.i);
	else
		index.count += write(1, str + index.lastindex, index.i - index.lastindex);
	va_end(ap);
	return (index.count);
}
