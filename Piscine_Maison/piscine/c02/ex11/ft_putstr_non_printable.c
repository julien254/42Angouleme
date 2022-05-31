/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:43:23 by jdetre            #+#    #+#             */
/*   Updated: 2022/03/19 23:14:44 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_int_in_hexa(int nbr, int niveau)
{
	char	*basehexa;

	basehexa = "0123456789abcdef";
	if (nbr < 16 && niveau == 0)
	{
		ft_putchar('0');
		ft_putchar(basehexa[nbr]);
	}
	else if (nbr < 16)
		ft_putchar(basehexa[nbr]);
	else
	{
		ft_print_int_in_hexa(nbr / 16, niveau + 1);
		ft_putchar(basehexa[nbr % 16]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31)
		{
			ft_putchar('\\');
			ft_print_int_in_hexa(str[i], 0);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
/*int	main()
{
	ft_putstr_non_printable("\1 \2 \3 \4 \5 \6 \7 \10 \11 \12 \13 \14 \15 \
	\16 \17 \20 \21 \22 \23 \24 \25 \26 \27 \30 \31 \32 \33 \34 \35 \36 \37");
	ft_putstr_non_printable("\10");
}*/
