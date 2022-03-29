/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_str_same_pattern.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matandre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:03:52 by matandre          #+#    #+#             */
/*   Updated: 2022/01/30 19:08:41 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "biblio.h"

void	ft_if_str_same_pattern(char *str, int *temp_i, char *pattern, int *j, int *i)
{
	while (str[*temp_i] && str[*temp_i] == pattern[*j] && pattern[*j])
	{
		*temp_i = *temp_i + 1;
		*j = *j + 1;
	}
	if (pattern[*j] == '\0')
	{
		while (!(str[*temp_i] >= 'a' && str[*temp_i] <= 'z'))
			*temp_i = *temp_i + 1;
		while (str[*temp_i] == '-' || \
		(str[*temp_i] >= 'a' && str[*temp_i] <= 'z'))
		{
			ft_putchar(str[*temp_i]);
			*temp_i = *temp_i + 1;
		}
		*i = -1;
	}
}
