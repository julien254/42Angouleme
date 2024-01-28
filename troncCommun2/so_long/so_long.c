/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:14:46 by judetre           #+#    #+#             */
/*   Updated: 2024/01/27 12:52:43 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*win;
	(void)argc;
	(void)argv;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "So_long");
	mlx_loop(mlx);
	return (0);
}
