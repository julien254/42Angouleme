/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 04:18:01 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/26 16:12:44 by jdetre           ###   ########.fr       */
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
		if (str[first] <= 31 || str[first] == 127)
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

void	ft_putaddr_in_hexa(long long int nbr, int level, int tchek, \
															int adaptative)
{
	char	*basehexa;

	basehexa = "0123456789abcdef";
	if (nbr < 16 && level == 0)
	{
		ft_ptchar('0');
		ft_ptchar(basehexa[nbr]);
	}
	else if (nbr < 16)
	{
		if (adaptative)
		{
			while (level++ < 15)
				ft_ptchar('0');
		}
		ft_ptchar(basehexa[nbr]);
	}
	else
	{
		ft_putaddr_in_hexa(nbr / 16, level + 1, 0, adaptative);
		ft_ptchar(basehexa[nbr % 16]);
	}
	if (tchek)
		ft_ptchar(' ');
}

void	ft_putchar_in_hexa(unsigned int *i, unsigned int j, char *str, \
		unsigned int size)
{
	while (j < 16)
	{
		if (*i >= size)
			ft_ptchar(' ');
		else if (*i % 2)
			ft_putaddr_in_hexa(str[*i], 0, 1, 0);
		else
			ft_putaddr_in_hexa(str[*i], 0, 0, 0);
		j++;
		if (str[*i] == '\0')
		{
			while (j < 16)
			{
				ft_ptchar(' ');
				ft_ptchar(' ');
				if (*i % 2)
					ft_ptchar(' ');
				*i += 1;
				j++;
			}
		}
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
		ft_putaddr_in_hexa((long long int)(addr + i), 0, 0, 1);
		ft_ptstr(":  ", 0, 2);
		j = 0;
		ft_putchar_in_hexa(&i, j, (char *)addr, size);
		ft_ptstr((char *)addr, bookmark, i);
		ft_ptchar('\n');
	}
	return (addr);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_print_memory("salut les gas ca va bien @#$% lol ...", 33);
	return (0);
}
