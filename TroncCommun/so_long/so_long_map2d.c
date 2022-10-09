/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:25:21 by julien            #+#    #+#             */
/*   Updated: 2022/10/09 06:22:54 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	maketab(char *tab2d, int *tab2d_int)
{
	int	sizeof_line;
	int	i;

	sizeof_line = ft_strlen(tab2d);
	i = 0;
	while (i < sizeof_line)
	{
		if (tab2d[i] == '0')
			tab2d_int[i] = 9998;
		else if (tab2d[i] == 'C')
			tab2d_int[i] = 9996;
		else if (tab2d[i] == '1')
			tab2d_int[i] = 9999;
		else if (tab2d[i] == 'E')
			tab2d_int[i] = 9997;
		else if (tab2d[i] == 'P')
			tab2d_int[i] = 0;
		i++;
	}
}

/* void	put_tab2d_int(char **tab2d, int **tab2d_int) */
/* { */
/* 	int	y; */
/* 	int	x; */
/* 	int	sizeof_line; */
/* 	int	nbr_line; */
/* 	nbr_line = ft_tab2dlen(tab2d); */
/* 	sizeof_line = ft_strlen(*tab2d); */
/* 	y = 0; */
/* 	while (y < nbr_line) */
/* 	{ */
/* 		x = 0; */
/* 		while (x < sizeof_line) */
/* 		{ */
/* 			if (tab2d_int[y][x] == 9999) */
/* 				write(1, " W ", 3); */
/* 			else if (tab2d_int[y][x] == 9998) */
/* 				write(1, "   ", 3); */
/* 			else if (tab2d_int[y][x] == 9997) */
/* 				write(1, " E ", 3); */
/* 			else if (tab2d_int[y][x] == 9996) */
/* 				write(1, " C ", 3); */
/* 			else if (tab2d_int[y][x] == 0) */
/* 				write(1, " 0 ", 3); */
/* 			else */
/* 			{ */
/* 				if (tab2d_int[y][x] < 10) */
/* 					ft_printf(" %d ", tab2d_int[y][x]); */
/* 				else if (tab2d_int[y][x] < 100) */
/* 					ft_printf(" %d", tab2d_int[y][x]); */
/* 				else if (tab2d_int[y][x] >= 100) */
/* 					ft_printf("%d", tab2d_int[y][x]); */
/* 			} */
/* 			x++; */
/* 		} */
/* 		write(1, "\n", 1); */
/* 		y++; */
/* 	} */
/* } */

int	**tab2d_char_to_int(char **tab2d)
{
	int		**tab2d_int;
	size_t	nbr_line;
	size_t	sizeof_line;
	size_t	i;

	nbr_line = ft_tab2dlen(tab2d);
	sizeof_line = ft_strlen(*tab2d);
	tab2d_int = (int **)malloc(sizeof(int *) * nbr_line);
	i = 0;
	while (i < nbr_line)
	{
		tab2d_int[i] = (int *)malloc(sizeof(int) * sizeof_line);
		maketab(tab2d[i], tab2d_int[i]);
		i++;
	}
	return (tab2d_int);
}
