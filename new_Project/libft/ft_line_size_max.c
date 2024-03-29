/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_size_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:27:27 by julien            #+#    #+#             */
/*   Updated: 2022/10/06 02:27:32 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_line_size_max(char *str)
{
	int	i;
	int	size_max;
	int	j;

	size_max = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i++] != '\n')
			j++;
		if (j > size_max)
			size_max = j;
	}
	return (j);
}
