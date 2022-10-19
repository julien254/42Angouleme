/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:07:04 by julien            #+#    #+#             */
/*   Updated: 2022/10/18 18:17:00 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_verif_malloc(void *malloc)
{
	if (malloc == NULL)
	{
		write(2, "Error\nMalloc Error !", 1);
		exit(EXIT_FAILURE);
	}
}
