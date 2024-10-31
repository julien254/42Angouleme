/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:55:17 by gcannaud          #+#    #+#             */
/*   Updated: 2024/07/26 15:18:17 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*ft_handles_access(char *var, t_a_line_browse *browse, int i,
	char **env)
{
	char	*pre_handle;
	char	*post_handle;
	char	*half;
	int		size;

	size = ft_strlen(var);
	half = NULL;
	pre_handle = NULL;
	post_handle = NULL;
	pre_handle = ft_substr(browse->a_line, 0, i);
	post_handle = ft_substr(browse->a_line, (i + size + 1),
			(ft_strlen(browse->a_line) - (i + size) + 1));
	free(browse->a_line);
	if (ft_if_env(env, var) != 0)
	{
		half = (ft_strjoin(ft_getenv(var, env), post_handle));
		browse->a_line = ft_strjoin(pre_handle, half);
		browse->i += ((ft_strlen(ft_getenv(var, env)) - ft_strlen(var)) - 1);
	}
	else
		browse->a_line = ft_strjoin(pre_handle, post_handle);
	free(half);
	free(pre_handle);
	free(post_handle);
	return (browse->a_line);
}

char	*ft_handle_replace(t_a_line_browse *browse, char **env,
	char *tmp, int i)
{
	char	*var;
	int		j;
	int		k;

	j = i;
	while (tmp[j] != '\0' && ((tmp[j + 1] >= 'a' && tmp[j + 1] <= 'z')
			|| (tmp[j + 1] >= 'A' && tmp[j + 1] <= 'Z') || tmp[j + 1] == '_'))
		j++;
	if (j - i == 0)
		return (browse->a_line);
	var = ft_calloc((j - i) + 1, sizeof(char));
	k = 0;
	while (j != i++)
		var[k++] = browse->a_line[i];
	var[k] = 0;
	browse->a_line = ft_handles_access(var, browse, (i - (k + 1)), env);
	free(var);
	return (browse->a_line);
}

char	*ft_replace_block(t_a_line_browse *browse, int i)
{
	char	*pre_handle;
	char	*post_handle;
	char	*half;

	pre_handle = NULL;
	post_handle = NULL;
	pre_handle = ft_substr(browse->a_line, 0, i);
	post_handle = ft_substr(browse->a_line, (i + 2),
			(ft_strlen(browse->a_line) - (i + 2)));
	free (browse->a_line);
	half = ft_itoa(browse->exit_code);
	browse->i--;
	browse->i += (ft_strlen(half) - 2);
	browse->a_line = ft_strjoin(pre_handle, half);
	free (half);
	free(pre_handle);
	free(post_handle);
	return (browse->a_line);
}

int	ft_is_handles(t_a_line_browse *browse, char **env,
	int i, char *tmp)
{
	if (ft_strncmp("$$", &tmp[i], 2) == 0)
	{
		browse->a_line = ft_new_a_line(browse,
				"SYSTEMD_EXEC_PID", 2, i);
	}
	else if (ft_strncmp("$?", &tmp[i], 2) == 0)
	{
		browse->a_line = ft_replace_block(browse, i);
		i--;
	}
	else
		browse->a_line = ft_handle_replace(browse, env, tmp, i);
	return (i);
}

char	*ft_handles_operator(t_a_line_browse *browse, char **env,
	int i, int and)
{
	char	*tmp;
	int		j;

	tmp = NULL;
	if (ft_strncmp(browse->a_line, "\"\"", 3) == 0
		|| ft_strncmp(browse->a_line, "''", 3) == 0)
		return (browse->a_line);
	tmp = ft_strdup(browse->a_line);
	while (i <= and && tmp[i])
	{
		free (tmp);
		tmp = ft_strdup(browse->a_line);
		j = 0;
		if (ft_strncmp("~", &tmp[i], 1) == 0)
			browse->a_line = ft_new_a_line(browse, "HOME", 1, i);
		else if (tmp[i] == '$')
		{
			i = ft_is_handles(browse, env, i, tmp);
			and = ft_strlen(browse->a_line);
		}
		i++;
	}
	free(tmp);
	return (browse->a_line);
}
