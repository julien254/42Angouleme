/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:57:51 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/16 17:35:31 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_lequal2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=' && str[i] != '+')
		i++;
	return (i);
}

char	*ft_str_sup_char(char *str, char c)
{
	char	*str2;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == c)
			k++;
		i++;
	}
	str2 = ft_calloc(sizeof(char), ((i - k) + 1));
	k = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		str2[k] = str[i];
		k++;
		if (str[i] != 0)
			i++;
	}
	return (str2);
}

int	ft_if_env(char **env, char *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != 0 && env[i][j] != '=')
			j++;
		if ((size_t)j == ft_strlen(var) && ft_strncmp(env[i], var, j) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	str_skip_char(char *str, char c, int i)
{
	if (str[i] == c)
	{
		i++;
		while (str && str[i] != c)
			i++;
	}
	return (i);
}

char	**ft_tabcpy(char **tab, int size)
{
	int		i;
	char	**tab2;
	int		j;

	tab2 = ft_calloc(ft_strlen_tab(tab) + size, sizeof(char *));
	if (!tab2)
		return (NULL);
	i = 0;
	while (tab[i] != 0)
	{
		j = 0;
		tab2[i] = ft_calloc(ft_strlen(tab[i]) + 1, sizeof(char));
		if (!tab2)
		{
			ft_free_env2(tab2);
			return (NULL);
		}
		while (tab[i][j] != '\0')
		{
			tab2[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	return (tab2);
}
