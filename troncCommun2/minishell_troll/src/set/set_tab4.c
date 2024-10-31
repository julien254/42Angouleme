/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:20:32 by uguidoni          #+#    #+#             */
/*   Updated: 2024/07/17 16:33:30 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_strlcpy2(char *dest, char *src, size_t size)
{
	size_t	countsrc;
	size_t	i;

	countsrc = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	**ft_tabdup(char **tab)
{
	char	**tabcpy;
	int		i;

	i = 0;
	while (tab[i] != 0)
		i++;
	tabcpy = ft_calloc(i + 2, sizeof(char **));
	if (!tabcpy)
		return (NULL);
	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i])
		{
			tabcpy[i] = ft_strdup(tab[i]);
			if (!tabcpy[i])
			{
				ft_free_env2(tabcpy);
				return (NULL);
			}
		}
		i++;
	}
	return (tabcpy);
}

char	***ft_realloc_tab_while(char ***t_tab, char ***t_tabcpy, int i, int j)
{
	while (i > j)
	{
		if (t_tab[j])
		{
			t_tabcpy[j] = ft_tabdup(t_tab[j]);
			if (!t_tabcpy[j])
			{
				ft_free_tab_a_line(t_tabcpy);
				return (NULL);
			}
		}
		j++;
	}
	return (t_tabcpy);
}

char	***ft_realloc_tab(char ***t_tab, t_line *s_line,
	t_environment *s_env, t_a_line_browse browse)
{
	char	***t_tabcpy;
	int		j;
	int		i;

	i = 0;
	while (t_tab[i][0])
		i++;
	t_tabcpy = ft_calloc(i + 4, sizeof(char **));
	if (!t_tabcpy)
		ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	j = 0;
	t_tabcpy = ft_realloc_tab_while(t_tab, t_tabcpy, i, j);
	if (!t_tabcpy)
		ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	ft_free_tab_a_line(t_tab);
	t_tabcpy[i] = ft_calloc(1, sizeof(char **));
	if (!t_tabcpy[i])
	{
		ft_free_tab_a_line(t_tabcpy);
		ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	}
	return (t_tabcpy);
}

int	*ft_realloc_int_tab(t_line *s_line, t_environment *s_env,
	t_a_line_browse browse)
{
	int	*cpy;
	int	i;
	int	j;

	i = 0;
	while (s_line->tab_sep[i] != 0)
		i++;
	cpy = ft_calloc(i + 2, sizeof(int));
	if (!cpy)
		ft_malloc_error_set_tab(s_line, s_env, NULL, browse);
	j = 0;
	while (i > j)
	{
		cpy[j] = s_line->tab_sep[j];
		j++;
	}
	free (s_line->tab_sep);
	s_line->tab_sep = NULL;
	return (cpy);
}
