/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:14:46 by judetre           #+#    #+#             */
/*   Updated: 2024/06/15 14:31:00 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_win *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);  // close window
	free(game->mlx); // free memory
	exit(0);
	return (0);
}

char **read_map(char *file)
{
	char **map2d;
    // Implémentation de la lecture du fichier et stockage dans un tableau 2D
	map2d = ft_recover_fd(file);
	if (!map2d)
	{
		perror("Error map");
		exit(EXIT_FAILURE);
	}
	ft_puttab2_fd(map2d, 1);
	free(map2d);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_win	game;
	(void)argc;
	(void)argv;
	if (argc != 2)
	{
		ft_printf("Error : Too many or too few arguments\n");
		exit(EXIT_FAILURE);
	}
	read_map(argv[1]);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, 800, 500, "So_long");
	if (game.win == NULL)
	{
		free(game.mlx);
		return (1);
	}
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
