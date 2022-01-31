/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_temp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matandre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:43:31 by matandre          #+#    #+#             */
/*   Updated: 2022/01/30 18:44:46 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "biblio.h"

void	ft_stock_nbr_rank_in_temp(char *pattern, char *pattern_temp, \
	int i, int mode)
{
	int	j;

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

void	ft_stock_num_in_temp(char *pattern, char *pattern_temp, \
	int index, int rank)
{
	int	j;

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

void	ft_stock_num_10to19_in_temp(char *pattern, char *pattern_temp, \
	int index, int rank)
{
	int	j;

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
