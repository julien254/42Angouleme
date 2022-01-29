/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:31:02 by jdetre            #+#    #+#             */
/*   Updated: 2022/01/29 14:05:07 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE_STR	10000

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		ft_putchar(str[a]);
		a++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
}

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

void	init_str(char *str)
{
	int	i;

	i = 0;
	while (i < SIZE_STR)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
}

void	search_nbr1to20(char *str, char *pattern)
{
	int	i;
	int	temp_i;
	int	j;

	i = 0;
	while (str[i])
	{
		temp_i = i;
		j = 0;
		if (str[temp_i] == pattern[j])
		{
			while (str[temp_i] && str[temp_i] == pattern[j] && pattern[j])
			{
				temp_i++;
				j++;
			}
			if (pattern[j] == '\0')
			{
				ft_putstr("match trouver\n");
				while (!(str[temp_i] >= 'a' && str[temp_i] <= 'z'))
					temp_i++;
				while (str[temp_i] != '\n')
				{
					ft_putchar(str[temp_i]);
					temp_i++;
				}
					
			}
		}
		i++;
	}
}

void	recup_dico(void)
{
	int	fd;
	char	*str;
	int	ret;

	str = (char*)malloc(sizeof(*str) * SIZE_STR + 1);
	init_str(str);
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
	}
	ft_putnbr(fd);
	ft_putchar('\n');
	ret = read(fd, str, SIZE_STR);
	str[ret] = '\0';
	ft_putnbr(ret);
	ft_putchar('\n');
	search_nbr1to20(str, "12");
}

int	main(int argv, char *argc[])
{
	if (argv == 2)
	{
		ft_putstr(argc[0]);
		ft_putchar('\0');
		recup_dico();
	}
	return (0);
r}
