/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab2_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 08:58:12 by julien            #+#    #+#             */
/*   Updated: 2022/09/16 09:25:24 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puttab2_fd(char **tab, int fd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
		count += ft_putendl_fd(tab[i++], fd);
	return (count);
}
