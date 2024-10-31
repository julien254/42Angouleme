/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:24:18 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/22 15:35:30 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent(const char *str, va_list arg, int len, size_t i)
{
	if (str[i] == 'c')
		len = ft_putchar(va_arg(arg, int), len);
	if (str[i] == 's')
		len = ft_putstr(va_arg(arg, char *), len);
	if (str[i] == 'p')
		len = ft_pointer(va_arg(arg, void *), len);
	if (str[i] == 'd' || str[i] == 'i')
		len = ft_putnbr(va_arg(arg, int), len);
	if (str[i] == 'u')
		len = ft_unsigned_putnbr(va_arg(arg, unsigned int), len);
	if (str[i] == 'x')
		len = ft_putnbr_base_lower(va_arg(arg, int), len);
	if (str[i] == 'X')
		len = ft_putnbr_base_upper(va_arg(arg, int), len);
	if (str[i] == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	int		len;

	if (!str)
		return (0);
	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_percent(str, arg, 0, i + 1);
			i += 2;
		}
		if (str[i] != '\0' && str[i] != '%')
		{
			write(1, &str[i], 1);
			len++;
			i++;
		}
	}
	va_end(arg);
	return (len);
}
