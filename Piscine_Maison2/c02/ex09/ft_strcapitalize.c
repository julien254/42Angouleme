/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:11:18 by jdetre            #+#    #+#             */
/*   Updated: 2023/07/14 08:50:20 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && \
				(!(str[i - 1] >= 'A' && str[i - 1] <= 'Z') && \
				!(str[i - 1] >= '0' && str[i - 1] <= '9') && \
				!(str[i - 1] >= 'a' && str[i - 1] <= 'z')))
			str[i] = str[i] - 32;
		else if ((str[i] >= 'A' && str[i] <= 'Z') && \
				((str[i - 1] >= 'A' && str[i - 1] <= 'Z') || \
				(str[i - 1] >= '0' && str[i - 1] <= '9') || \
				(str[i - 1] >= 'a' && str[i - 1] <= 'z')))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
