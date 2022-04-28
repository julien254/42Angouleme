/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:02:01 by jdetre            #+#    #+#             */
/*   Updated: 2022/04/28 08:00:03 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void ft_print_arg(va_list *var, char const *str, int i)
{
	(void)var;
	if (str[i + 1] == '%')
		write(1, "%", 1);
}

int ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	lastindex;
	va_list	var;
	int	ifarg;

	i = 0;
	lastindex = 0;
	ifarg = 0;
	va_start(var, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ifarg = 1;
			if (str[i - 2] != '%')
				write(1, str + lastindex, i);
			lastindex = i + 2;
			ft_print_arg(&var, str, i);
			i++;
		}
		i++;
	}
	if (!ifarg)
		write(1, str + lastindex, i);
	return (i);
}
