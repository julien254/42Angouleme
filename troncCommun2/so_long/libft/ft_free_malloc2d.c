/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_malloc2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:01:32 by judetre           #+#    #+#             */
/*   Updated: 2024/02/25 13:21:16 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_free_malloc2d(void **tab2d)
{
	int	i;

	if (!tab2d)
		return (NULL);
	i = 0;
	ft_printf("le malloc 2d est bien %p. \n", tab2d);
	while (tab2d[i])
	{
		free(tab2d[i]);
		ft_printf("le malloc %p est liberé.\n", tab2d[i]);
		i++;
	}
	free(tab2d);
	ft_printf("le malloc 2d a bien été liberer\n");
	return (NULL);
}
