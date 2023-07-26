/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:12:45 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/26 16:22:36 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchr(unsigned char c)
{
	write(1, &c, 1);
}

void	putnbr_hexa(long long int nbr, int niveau)
{
	char	*base_hexa;

	base_hexa = "0123456789abcdef";
	if (nbr < 16 && niveau == 0)
	{
		ft_putchr('0');
		ft_putchr(base_hexa[nbr]);
	}
	else if (nbr < 16)
		ft_putchr(base_hexa[nbr]);
	else
	{
		putnbr_hexa(nbr / 16, niveau + 1);
		ft_putchr(base_hexa[nbr % 16]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str < 127)
			ft_putchr(*str);
		else
		{
			ft_putchr('\\');
			putnbr_hexa((unsigned char)*str, 0);
		}
		str++;
	}
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_putstr_non_printable("lol salut les gas \001 \002 \003 \004 \005 \006 \037 ");
	return (0);
}
