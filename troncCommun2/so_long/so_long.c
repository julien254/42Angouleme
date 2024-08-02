/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:14:46 by judetre           #+#    #+#             */
/*   Updated: 2024/07/31 12:00:11 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_map(t_win *game)
{
	check_size_map(game);
	check_wall_map(game);
	count_elem_map(game);
	check_wrong_characters(game);
	check_elem_map(game);
}

int	main(int argc, char *argv[])
{
	t_win	game;

	ft_memset(&game, 0, sizeof(t_win));
	if (argc != 2)
	{
		ft_putendl_fd("Error : Too many or too few arguments", 2);
		exit(EXIT_FAILURE);
	}
	game.map2d = read_map(argv[1]);
	check_map(&game);
	game.way.map2d_int = map2d_char_to_int(&game);
	verif_way(&game, game.map.hero_x, game.map.hero_y, 0);
	game.mlx = mlx_init();
	if (!game.mlx)
		close_window(&game);
	game.win = mlx_new_window(game.mlx, ELEM_SIZE_X * game.map.map_size_x, \
			ELEM_SIZE_Y * game.map.map_size_y, "So_long");
	if (!game.win)
		close_window(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	load_img(&game);
	mlx_loop_hook(game.mlx, loop_print_map, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
}
