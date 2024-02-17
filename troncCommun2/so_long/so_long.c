/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:14:46 by judetre           #+#    #+#             */
/*   Updated: 2024/02/10 07:53:09 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**map_2d;

	/* void	*mlx; */
	/* void	*win; */
	(void)argc;
	(void)argv;
	/* mlx = mlx_init(); */
	/* win = mlx_new_window(mlx, 1920, 1080, "So_long"); */
	/* (void)win; */
	/* mlx_loop(mlx); */
	map_2d = ft_recover_fd(argv[1]);
	ft_puttab2_fd(map_2d, 1);
	return (0);
}
