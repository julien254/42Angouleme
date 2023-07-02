/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_printable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:19:38 by jdetre            #+#    #+#             */
/*   Updated: 2023/06/22 14:27:47 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_str_is_printable(char *str)
{

	while (*str)
	{
		if (!(*str >= 32 && *str <= 126))
			return (0);
		str++;
	}
	return (1);
}
