/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matandre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:56:36 by matandre          #+#    #+#             */
/*   Updated: 2022/03/04 01:18:54 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "biblio.h"

int	main(int argc, char *argv[])
{
	char *map;
	
	(void)argc;
	map = ft_recup_map(argv[1]);
	if (ft_erreur(map))
		return (0);
	
}

int autrechose(void)
{
	return (0);
}


