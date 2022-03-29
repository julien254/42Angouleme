/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:43:23 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/26 12:48:57 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_int_in_hexa(int nbr)
{
	char	*basehexa;
	int		i;

	i = 0;
	basehexa = "0123456789abcdef";
	if (nbr < 16 && i == 0)
	{
		ft_putchar('0');
		ft_putchar(basehexa[nbr]);
	}
	else if (nbr < 16)
		ft_putchar(basehexa[nbr]);
	else
	{
		ft_print_int_in_hexa(nbr / 16);
		ft_putchar(basehexa[nbr % 16]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 31)
		{
			ft_putchar('\\');
			ft_print_int_in_hexa(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
/*int	main()
{
	ft_putstr_non_printable("loool \a \b \t \n \v \f \r loool");
}*/
