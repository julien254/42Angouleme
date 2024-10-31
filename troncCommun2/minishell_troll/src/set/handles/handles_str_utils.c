/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_str_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:50:51 by gcannaud          #+#    #+#             */
/*   Updated: 2024/08/14 12:50:52 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_str_c_number(char *str, char *c)
{
	int	i;
	int	cunter;

	i = 0;
	cunter = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_strcmp(&str[i], c) == 0)
			cunter++;
		i++;
	}
	return (cunter);
}

char	*ft_str_add_char(char *str, char *c)
{
	char	*tmp;

	tmp = ft_strjoin(str, c);
	free(str);
	return (tmp);
}

char	*ft_deljoin(char *str1, char *str2)
{
	char	*join;

	join = ft_strjoin(str1, str2);
	free(str1);
	return (join);
}

char	*ft_supchar(char *str, int start, char *strsup)
{
	char	*str2;
	int		j;
	int		k;

	j = 0;
	k = 0;
	str2 = ft_calloc((ft_strlen(str) - (ft_strlen(strsup)) + 2), sizeof(char));
	while ((size_t)k <= ft_strlen(str) - ft_strlen(strsup))
	{
		if (j == start)
			j = j + (ft_strlen(strsup) - 1);
		str2[k] = str[j];
		k++;
		if (str[j] != 0)
			j++;
	}
	free(str);
	return (str2);
}
