/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:29:44 by jdetre            #+#    #+#             */
/*   Updated: 2024/10/23 17:24:39 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_putnbr(int nbr)
{
	int len;
	unsigned int nb;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nb = nbr * -1;
	}
	else
		nb = nbr;
	if (nb <= 9)
		len += ft_putchar('0' + nb);
	else
	{
		len += ft_putnbr(nb / 10);
		len += ft_putchar('0' + nb % 10);
	}
	return (len);
}

int ft_puthexa(unsigned int nb)
{
	int len;
	char *base;

	len = 0;
	base = "0123456789abcdef";
	if (nb < 16)
		len += ft_putchar(base[nb]);
	else
	{
		len += ft_puthexa(nb / 16);
		len += ft_putchar(base[nb % 16]);
	}
	return (len);
}

int print_arg(va_list *ag, const char *str, int i)
{
	int len;

	len = 0;
	if (str[i + 1] == 's')
		len += ft_putstr(va_arg(*ag, char *));
	else if (str[i + 1] == 'd')
		len += ft_putnbr(va_arg(*ag, int));
	else if (str[i + 1] == 'x')
		len += ft_puthexa(va_arg(*ag, unsigned int));
	return (len);
}

int ft_printf(const char *str, ...)
{
	int i;
	int len;
	va_list ag;

	if (!str)
		return (-1);
	va_start(ag, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != 0)
		{
			len += print_arg(&ag, str, i);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
		
	}
	va_end(ag);
	return (len);
}

/* #include <stdio.h> */
/* int	main(int argc, char *argv[]) */
/* { */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	int count; */
/* 	count = ft_printf("%s\nvoila le numero %d\nqui fait en hexa :%x\n", "c'est une dingerie", 42424242, 42424242); */
/* 	printf("%d\n", count); */
/* 	count = printf("%s\nvoila le numero %d\nqui fait en hexa :%x\n", "c'est une dingerie", 42424242, 42424242); */
/* 	printf("%d\n", count); */
/* 	return (0); */
/* } */
