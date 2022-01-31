/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dico.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matandre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:42:42 by matandre          #+#    #+#             */
/*   Updated: 2022/01/30 19:52:10 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "biblio.h"

void	ft_search_nbr_in_dico_and_print(char *str, char *pattern, int i)
{
	int	temp_i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		temp_i = i;
		if (str[temp_i] == pattern[j])
		{
			ft_if_str_same_pattern(str, &temp_i, pattern, &j, &i);
		}
		ft_putnbr(i);
		if (i == -1)
			break ;
		i++;
	}
}

void	ft_recup_dico(char *pattern, char *dict)
{
	int		fd;
	int		ret;
	char	*str;

	str = malloc(sizeof(*str) * 10000 + 1);
	if (str == NULL)
		ft_putstr("Error");
	else
	{
		ft_init_str(str);
		fd = open(dict, O_RDONLY);
		if (fd == -1)
			ft_putstr("open() failed\n");
		ret = read(fd, str, 10000);
		str[ret] = '\0';
		ft_cut_print_pattern(str, pattern);
		free(str);
		close(fd);
	}
}
