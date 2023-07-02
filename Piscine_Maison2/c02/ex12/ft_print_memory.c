/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 04:18:01 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/01 13:39:38 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_ptchar(char c)
{
	write(1, &c, 1);
}

void	ft_ptstr(char *str, unsigned int first, unsigned int last)
{
	while (first < last && str[first] != '\0')
	{
		if (str[first] <= 31)
			ft_ptchar('.');
		else if (str[first] == ' ' && str[first - 1] == ' ')
		{
			first++;
			continue ;
		}
		else
			ft_ptchar(str[first]);
		first++;
		if (str[first] == '\0')
		{
			ft_ptchar('.');
		}
	}
}

void	ft_putaddr_in_hexa(long long int nbr, int level)
{
	char	*basehexa;

	basehexa = "0123456789abcdef";
	if (nbr < 16 && level == 0)
	{
		ft_ptchar('0');
		ft_ptchar(basehexa[nbr]);
	}
	else if (nbr < 16)
		ft_ptchar(basehexa[nbr]);
	else
	{
		ft_putaddr_in_hexa(nbr / 16, level + 1);
		ft_ptchar(basehexa[nbr % 16]);
	}
}
void	ft_putchar_in_hexa(unsigned int *i, unsigned int j, char *str , unsigned int size)
{
	(void)size;
	while (j < 16)
	{
		if (*i >= size)
			ft_ptchar(' ');
		else if (*i % 2)
		{
			ft_putaddr_in_hexa(str[*i], 0);
			ft_ptchar(' ');
		}
		else
			ft_putaddr_in_hexa(str[*i], 0);
		j++;
		*i += 1;

	}
}
void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	bookmark;

	i = 0;
	while (i < size)
	{
		bookmark = i;
		ft_ptstr("0000 ", 0, 4);
		ft_putaddr_in_hexa((long long int)(addr + i), 0);
		ft_ptstr(":  ", 0 , 2);
		j = 0;
		ft_putchar_in_hexa(&i, j,(char *)addr, size);
		ft_ptstr((char *)addr, bookmark, i);
		ft_ptchar('\n');
	}
	return (addr);
}

