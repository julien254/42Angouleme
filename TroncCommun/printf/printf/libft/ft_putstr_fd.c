/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:42:03 by julien            #+#    #+#             */
/*   Updated: 2022/05/28 10:14:10 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}
