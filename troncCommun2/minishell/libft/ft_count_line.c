/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:03:49 by julien            #+#    #+#             */
/*   Updated: 2024/02/11 17:55:01 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_line(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			count++;
	}
	if (i == 0)
		return (0);
	return (count + 1);
}