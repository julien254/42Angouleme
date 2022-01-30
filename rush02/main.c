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
#include <stdio.h>
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

void stock_nbr_rank_in_temp(char *pattern, char *pattern_temp, int i, int mode)
{
	int j;
	j = 0;
	if (mode == 100)
	{
	while (j < 3)
	{
		if (j == 0)
			pattern_temp[j] = '1';
		else
			pattern_temp[j] = '0';
		j++;
	}
	pattern_temp[j] = '\0';
	}
	else
	{
		while (pattern[i])
        {
                if (j == 0)
                        pattern_temp[j] = '1';
                else
                        pattern_temp[j] = '0';
                j++;
                i++;
        }
		pattern_temp[j] = '\0';
	}
}

void stock_num_in_temp(char *pattern, char *pattern_temp, int index,int rank)
{
	int j;

	j = 0;
        while (j < rank)
        {
                if (j == 0)
		{
                        pattern_temp[j] = pattern[index];
			j++;
			index++;
		}
		else
		{
			pattern_temp[j] = '0';
			j++;
			index++;
		}
        }
	pattern_temp[j] = '\0';
}

void stock_num_10to19_in_temp(char *pattern, char *pattern_temp, int index,int rank)
{
        int j;

        j = 0;
        while (j < rank)
        {
                if (j == 0)
                {
                        pattern_temp[j] = pattern[index];
                        j++;
                        index++;
                }
                else
                {
                        pattern_temp[j] = pattern[index];
                        j++;
                        index++;
                }
        }
        pattern_temp[j] = '\0';
}

int check_0_in_rank(char *pattern, int i)
{
	if (pattern[i] == '0' && pattern[i - 1] == '0' && pattern[i - 2] == '0')
		return (0);
	return (1);
}

void	search_nbr_in_dico_and_print(char *str, char *pattern, int i)
{
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
				while (!(str[temp_i] >= 'a' && str[temp_i] <= 'z'))
					temp_i++;
				while (str[temp_i] != '\n')
				{
					ft_putchar(str[temp_i]);
					temp_i++;
				}
				i = -1;				
			}
		}
		if (i == -1)
			break;
		i++;
	}
}

void	cut_print_pattern(char *str, char *pattern)
{
	int i;
	char *pattern_temp;

	i = 0;
	pattern_temp = (char*)malloc(sizeof(*str) * SIZE_STR + 1);
	init_str(pattern_temp);
	while (pattern[i])
	{
		if ((ft_strlen(pattern) - i) % 3 == 1)
		{
			
			if (pattern[i] != '0' && pattern[i - 1] != '1')
			{
				stock_num_in_temp(pattern, pattern_temp, i, 1);
				search_nbr_in_dico_and_print(str, pattern_temp, i);
				if (i < ft_strlen(pattern) - 3)	
				{
					ft_putstr(" ");
				stock_nbr_rank_in_temp(pattern, pattern_temp, i, 0);
				search_nbr_in_dico_and_print(str, pattern_temp, i);
				if (pattern[i + 1] == '0' && (pattern[i + 2] != '0' || pattern[i + 3] != '0'))
					ft_putstr(", and ");
				else if (pattern[i + 1] > '0')
					ft_putstr(", ");
				}
				
			}
			else if (check_0_in_rank(pattern, i) && i < ft_strlen(pattern) - 3)
			{
				stock_nbr_rank_in_temp(pattern, pattern_temp, i, 0);
                                search_nbr_in_dico_and_print(str, pattern_temp, i);
				ft_putstr(", ");
			}

		}
		else if ((ft_strlen(pattern) - i) % 3 == 2 \
                                && pattern[i] != '0')
		{
			if (pattern[i] != '1')
			{
				stock_num_in_temp(pattern, pattern_temp, i, 2);
				search_nbr_in_dico_and_print(str, pattern_temp, i);
				if (pattern[i + 1] != '0')
					ft_putstr("-");
				else
					ft_putstr(" ");	
			}
			else
			{
				stock_num_10to19_in_temp(pattern, pattern_temp, i, 2);
				search_nbr_in_dico_and_print(str, pattern_temp, i);
				ft_putstr(" ");

			}

		}
		
		else if ((ft_strlen(pattern) - i) % 3 == 0 && pattern[i] != '0')
		{
			stock_num_in_temp(pattern, pattern_temp, i, 1);
                        search_nbr_in_dico_and_print(str, pattern_temp, i);
				ft_putstr(" ");
			stock_nbr_rank_in_temp(pattern, pattern_temp, i, 100);
                        search_nbr_in_dico_and_print(str, pattern_temp, i);
			if ((pattern[i + 1] != '0' && pattern[i + 2] != '0') || (pattern[i + 1] != '0' || pattern[i + 2] != '0'))
				ft_putstr(" and ");
			else
				ft_putstr(" ");
                }
		i++;
	}
}

void    recup_dico(char *pattern)
{
	int     fd;
	char    *str;
	int     ret;

	str = (char*)malloc(sizeof(*str) * SIZE_STR + 1);
	init_str(str);
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
	}
	ret = read(fd, str, SIZE_STR);
	str[ret] = '\0';
	cut_print_pattern(str, pattern);
}

int	main(int argv, char *argc[])
{
	if (argv == 2)
	{
		printf("%s", argc[1]);
		printf("%c", '\n');
		recup_dico(argc[1]);
		printf("%c", '\n');

	}
	return (0);
}
