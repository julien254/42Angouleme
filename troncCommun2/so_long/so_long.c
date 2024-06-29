/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:14:46 by judetre           #+#    #+#             */
/*   Updated: 2024/06/29 16:11:17 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber_extension(char *map)
{
	char *ext;

	ext = map + ft_strlen(map) - 4;
	if (ft_strncmp(ext, ".ber", 4))
	{
		ft_printf("Error: The map isn't a .ber\n");
		exit(EXIT_FAILURE);
	}
}

int	close_window(t_win *game)
{
	ft_free_malloc2d((void **)game->map2d);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win); // close window
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx); //close mlx 
		free(game->mlx); // free memory
	}
	exit(game->map.err_map);
}

void	exit_failure(int err, char *str_err, t_win *game)
{
	game->map.err_map = err;
	printf("%s\n", str_err);
	close_window(game);

}

char **read_map(char *file)
{
	char **map2d;

	check_ber_extension(file);
	map2d = ft_recover_fd(file);
	if (!map2d)
	{
		perror("Error map");
		exit(EXIT_FAILURE);
	}
	//ft_puttab2_fd(map2d, 1);
	return (map2d);
}

int key_hook(int keycode, t_win *game)
{
	ft_printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		close_window(game);
    // Ajoute ici la gestion des autres touches si nécessaire
    return (0);
}

void check_size_map(t_win *game)
{
	char **map2d;
	int	y; // axe y

	y = 0;
	map2d = game->map2d;
	game->map.map_size_y = ft_tab2dlen(map2d);
	game->map.map_size_x = ft_strlen(map2d[y++]);
	while (map2d[y])
	{
		if (ft_strlen(map2d[y++]) != game->map.map_size_x)
			exit_failure(ERR_SHAPE, STR_ERR_SHAPE, game);
	}
}

void check_wall_map(t_win *game)
{
	char **map2d = game->map2d;
	int	size_line;
	int	x;	// axe x
	int y;	// axe y

	x = 0;
	y = 0;
	size_line = game->map.map_size_x;
	while (map2d[y][x])
	{
		if (map2d[y][x++] != '1')
			exit_failure(ERR_WALL, STR_ERR_WALL, game);
	}
	while (map2d[y])
	{
		if (map2d[y][0] != '1' || map2d[y][size_line - 1] != '1')	
			exit_failure(ERR_WALL, STR_ERR_WALL, game);
		y++;
	}
	x = 0;
	while (map2d[y - 1][x])
	{
		if (map2d[y - 1][x++] != '1')
			exit_failure(ERR_WALL, STR_ERR_WALL, game);
	}
}

void check_map(t_win *game)
{
	check_size_map(game);
	check_wall_map(game);
}

int	main(int argc, char *argv[])
{
	t_win	game;
	
	ft_memset(&game, 0, sizeof(t_win));
	if (argc != 2)
	{
		ft_printf("Error : Too many or too few arguments\n");
		exit(EXIT_FAILURE);
	}
	game.map2d = read_map(argv[1]);
	check_map(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		close_window(&game);
	game.win = mlx_new_window(game.mlx, ELEM_SIZE_X * game.map.map_size_x, \
								ELEM_SIZE_Y * game.map.map_size_y, "So_long");
	if (!game.win)
		close_window(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L<<0, key_hook, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
}
