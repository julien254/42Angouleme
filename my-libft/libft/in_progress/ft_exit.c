/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 05:45:25 by judetre           #+#    #+#             */
/*   Updated: 2024/01/10 20:13:49 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(int nbFd, int nbptr, int exit_type, ...)
{
	va_list	args;
	int		i;

	i = 0;
	while (i <= nbFd)
	{
		close(va_arg(args, int));
		i++;
	}
	while (i <= nbFd + nbptr)
	{
		free(va_arg(args, void *));
		i++;
	}
	if (exit_type == 1)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
