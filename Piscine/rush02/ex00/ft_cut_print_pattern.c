/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_print_pattern.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matandre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:22:06 by matandre          #+#    #+#             */
/*   Updated: 2022/01/30 19:51:12 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "biblio.h"

void	ft_cut_print_pattern(char *str, char *pattern)
{
	int		i;
	char	*pattern_temp;

	i = 0;
	pattern_temp = malloc(sizeof(*str) * 10000 + 1);
	if (pattern_temp == NULL)
		ft_putstr("Error");
	else
	{
		ft_init_str(pattern_temp);
		while (pattern[i])
		{
			if ((ft_strlen(pattern) - i) % 3 == 1)
				ft_if_modulo_1(pattern, pattern_temp, i, str);
			else if ((ft_strlen(pattern) - i) % 3 == 2 \
					&& pattern[i] != '0')
				ft_if_modulo_2(pattern, pattern_temp, i, str);
			else if ((ft_strlen(pattern) - i) % 3 == 0 && pattern[i] != '0')
				ft_if_modulo_0(pattern, pattern_temp, i, str);
			i++;
		}
		free(pattern_temp);
	}
}
