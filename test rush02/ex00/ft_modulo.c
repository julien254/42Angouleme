/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modulo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matandre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:43:46 by matandre          #+#    #+#             */
/*   Updated: 2022/01/30 18:32:37 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "biblio.h"

void	ft_if_modulo_1(char *pattern, char *pattern_temp, int i, char *str)
{
	if (pattern[i] != '0' && pattern[i - 1] != '1')
	{
		ft_stock_num_in_temp(pattern, pattern_temp, i, 1);
		ft_search_nbr_in_dico_and_print(str, pattern_temp, i);
		if (i < ft_strlen(pattern) - 3)
		{
			ft_putstr(" ");
			ft_stock_nbr_rank_in_temp(pattern, pattern_temp, i, 0);
			ft_search_nbr_in_dico_and_print(str, pattern_temp, i);
			if (pattern[i + 1] == '0' && (pattern[i + 2] != '0' \
				|| pattern[i + 3] != '0'))
				ft_putstr(", and ");
			else if (pattern[i + 1] > '0')
				ft_putstr(", ");
		}
	}
	else if (ft_check_0_in_rank(pattern, i) && i < ft_strlen(pattern) - 3)
	{
		ft_stock_nbr_rank_in_temp(pattern, pattern_temp, i, 0);
		ft_search_nbr_in_dico_and_print(str, pattern_temp, i);
		ft_putstr(", ");
	}
}

void	ft_if_modulo_2(char *pattern, char *pattern_temp, int i, char *str)
{
	if (pattern[i] != '1')
	{
		ft_stock_num_in_temp(pattern, pattern_temp, i, 2);
		ft_search_nbr_in_dico_and_print(str, pattern_temp, i);
		if (pattern[i + 1] != '0')
			ft_putstr("-");
		else
			ft_putstr(" ");
	}
	else
	{
		ft_stock_num_in_temp(pattern, pattern_temp, i, 2);
		ft_search_nbr_in_dico_and_print(str, pattern_temp, i);
		ft_putstr(" ");
	}
}

void	ft_if_modulo_0(char *pattern, char *pattern_temp, int i, char *str)
{
	ft_stock_num_in_temp(pattern, pattern_temp, i, 1);
	ft_search_nbr_in_dico_and_print(str, pattern_temp, i);
	ft_putstr(" ");
	ft_stock_nbr_rank_in_temp(pattern, pattern_temp, i, 100);
	ft_search_nbr_in_dico_and_print(str, pattern_temp, i);
	if ((pattern[i + 1] != '0' && pattern[i + 2] != '0') || \
			(pattern[i + 1] != '0' || pattern[i + 2] != '0'))
		ft_putstr(" and ");
	else
		ft_putstr(" ");
}
