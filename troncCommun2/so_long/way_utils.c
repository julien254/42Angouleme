/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:23:32 by judetre           #+#    #+#             */
/*   Updated: 2024/07/31 13:12:16 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	maketab(char *tab2d, int *tab2d_int)
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

int	**map2d_char_to_int(t_win *game)
{
	int		**map2d_int;
	size_t	nbr_line;
	size_t	sizeof_line;
	size_t	i;

	nbr_line = ft_tab2dlen(game->map2d);
	sizeof_line = ft_strlen(*game->map2d);
	map2d_int = (int **)malloc(sizeof(int *) * (nbr_line + 1));
	if (!map2d_int)
		exit_failure(ERR_MALLOC, STR_ERR_MALLOC, game);
	i = 0;
	while (i < nbr_line)
	{
		map2d_int[i] = (int *)malloc(sizeof(int) * sizeof_line);
		if (!map2d_int[i])
			exit_failure(ERR_MALLOC, STR_ERR_MALLOC, game);
		maketab(game->map2d[i], map2d_int[i]);
		i++;
	}
	map2d_int[i] = NULL;
	return (map2d_int);
}
