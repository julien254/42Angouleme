/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:13:37 by julien            #+#    #+#             */
/*   Updated: 2022/03/19 22:57:22 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, unsigned int first, unsigned int last)
{
	while (first < last && str[first] != '\0')
	{
		if (str[first] <= 31)
			ft_putchar('.');
		else if (str[first] == ' ' && str[first - 1] == ' ')
		{
			first++;
			continue ;
		}
		else
			ft_putchar(str[first]);
		first++;
		if (str[first] == '\0')
		{
			ft_putchar('.');
		}
	}
}

void	ft_print_int_in_hexa(long long int nbr, int level)
{
	char	*basehexa;

	basehexa = "0123456789abcdef";
	if (nbr < 16 && level == 0)
	{
		ft_putchar('0');
		ft_putchar(basehexa[nbr]);
	}
	else if (nbr < 16)
		ft_putchar(basehexa[nbr]);
	else
	{
		ft_print_int_in_hexa(nbr / 16, level + 1);
		ft_putchar(basehexa[nbr % 16]);
	}
}

void	ft_put_hexa(unsigned int *i, unsigned int *j, \
						char *carac, unsigned int size)
{
	while (*j < 16)
	{
		if (*i >= size)
			ft_putchar(' ');
		else if (*i % 2 == 1)
		{
			ft_print_int_in_hexa(carac[*i], 0);
			ft_putchar(' ');
		}
		else
		{
			ft_print_int_in_hexa(carac[*i], 0);
		}
		*i += 1;
		*j += 1;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long int	addr_hexa;
	char					*carac;
	unsigned int			bookmark;
	unsigned int			i;
	unsigned int			j;

	addr_hexa = (unsigned long long int)addr;
	carac = (char *)addr;
	i = 0;
	while (i < size)
	{
		bookmark = i;
		ft_putstr("0000 ", 0, 4);
		ft_print_int_in_hexa(addr_hexa + i, 0);
		ft_putchar(':');
		ft_putchar(' ');
		j = 0;
		ft_put_hexa(&i, &j, carac, size);
		ft_putstr(carac, bookmark, i);
		ft_putchar('\n');
	}
	return (addr);
}
