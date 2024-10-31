/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:18:22 by uguidoni          #+#    #+#             */
/*   Updated: 2024/06/19 17:37:41 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_cut(char *str, char c, int count)
{
	int		i;
	char	*temp;
	int		j;

	i = 0;
	while (i != ft_lequal2(str))
	{
		if (str[i] == c)
			count++;
		i++;
	}
	temp = ft_calloc((ft_strlen(str) - count) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	j = 0;
	i = 0;
	while (i != ft_lequal(str))
	{
		if (str[i] != c)
			temp[j++] = str[i];
		i++;
	}
	while ((size_t)i != ft_strlen(str))
		temp[j++] = str[i++];
	return (temp);
}

int	ft_strlen_tab2(char	***tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int	ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int	ft_lfirstparam(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '|')
		i++;
	return (i);
}

int	ft_icmp(int i1, int i2)
{
	if (i1 > i2)
		return (i1);
	return (i2);
}
