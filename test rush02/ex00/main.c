/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matandre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:56:36 by matandre          #+#    #+#             */
/*   Updated: 2022/01/30 20:03:31 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "biblio.h"

int	main(int argv, char *argc[])
{
	char	str[10001];
	int		ret;

	ft_init_str(str);
	if (argv == 2)
	{
		if (ft_atoi(argc[1]))
			ft_recup_dico(argc[1], "numbers.dict");
	}
	else if (argv == 1)
	{
		ret = read(0, str, 10000);
		str[ret] = '\0';
		if (ft_atoi(str))
			ft_recup_dico(str, "numbers.dict");
	}
	else if (argv == 3)
	{
		if (ft_atoi(argc[2]))
			ft_recup_dico(argc[2], argc[1]);
	}
	return (0);
}
