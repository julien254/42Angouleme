/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:06:20 by uguidoni          #+#    #+#             */
/*   Updated: 2024/06/19 16:51:44 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_lequal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	return (i);
}

char	*ft_after_equal(char *str)
{
	int		i;
	int		j;
	char	*temp;
	int		k;

	i = 0;
	while (str[i] != '=')
		i++;
	i += 1;
	j = i;
	while (str[j] != 0)
		j++;
	temp = ft_calloc((j - i) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	k = 0;
	while (str[i] != 0)
		temp[k++] = str[i++];
	return (temp);
}
