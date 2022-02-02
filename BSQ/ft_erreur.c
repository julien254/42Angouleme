/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:13:39 by mbobin            #+#    #+#             */
/*   Updated: 2022/02/01 12:54:52 by mbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "biblio.h"

int	ft_str_is_printable_and_for_diff_elmts(char *str)
{
	int	i;

	i = 1;
	while (i <= 3)
	{
		if ((str[i] >= ' ' && str[i] <= '~') && ((str[1] != str[2]) 
				&& (str[1] != str[3]) && (str[2] != str[3])))
			i++;
		else
			return (1);
	}
	if ( i != 4)
		return (1);
	return (0);
}
int	ft_char_is_numeric(char c)
{
	if ( c >= '0' && c <= '9')
		return (0);
	else
		return (1);
}
int	ft_erreur(char *str)
{
	if (ft_char_is_numeric(str[0]) == 1)
	{
			ft_putstr("map error\n");
		return (1);
	}
		
	if (ft_str_is_printable_and_for_diff_elmts(str) == 1)
	{
			ft_putstr("map error\n");
		return (1);
	}
	if (ft_erreur_map(str) == 1)
	{
			ft_putstr("map error\n");
		return (1);
	}

	return (0);
	
}
