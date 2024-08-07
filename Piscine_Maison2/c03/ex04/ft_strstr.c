/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:27:27 by judetre           #+#    #+#             */
/*   Updated: 2023/07/17 19:14:12 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	tcheck;

	if (ft_strlen(to_find) == 0)
		return (str);
	while (*str)
	{
		i = 0;
		tcheck = 1;
		while (to_find[i] && tcheck)
		{
			if (str[i] != to_find[i])
				tcheck = 0;
			if (tcheck)
				i++;
		}
		if (tcheck)
			return (str);
		else
			str++;
	}
	return (0);
}
