/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:16:15 by judetre           #+#    #+#             */
/*   Updated: 2024/07/01 11:18:37 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <errno.h>

# define KEY_ESC 65307
# define KEY_Z 122
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100
# define ELEM_SIZE_X 48
# define ELEM_SIZE_Y 50
# define ERR_SHAPE 10
# define STR_ERR_SHAPE "Error: The map isn't rectangular"
# define ERR_WALL 11
# define STR_ERR_WALL "Error: The map isn't surrounded by walls"
# define ERR_HERO 12
# define STR_ERR_HERO "Error: Too few or more of hero"
# define ERR_ITEM 13
# define STR_ERR_ITEM "Error: The map must contain at least one object"
# define ERR_EXIT 14
# define STR_ERR_EXIT "Error: The map must contain one Exit"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_img {
	t_data	wall;
	t_data	item;
	t_data	exit;
	t_data	floor;
	t_data	hero;
	t_data	hero_right;
	t_data	hero_left;
	t_data	hero_back;
}				t_img;

typedef struct s_map {
	size_t	map_size_y;
	size_t	map_size_x;
	int		hero;
	int		hero_direction;
	int		hero_y;
	int		hero_x;
	int		count_move;
	int		item;
	int		exit;
	int		err_map;
}				t_map;

typedef struct s_win {
	void	*mlx;
	void	*win;
	char	**map2d;
	t_map	map;
	t_img	img;
}				t_win;

/********************************* EXIT_GAME ********************************/

void			free_img(t_win *game);
int				close_window(t_win *game);
void			exit_failure(int err, char *str_err, t_win *game);

/********************************* CHECK_MAP ********************************/

void			check_ber_extension(char *map);
void			check_size_map(t_win *game);
void			check_wall_map(t_win *game);
void			check_elem_map(t_win *game);

/********************************* MAP_UTILS ********************************/

char			**read_map(char *file);
void			count_elem_map(t_win *game);

/******************************** PIXEL_UTILS *******************************/

unsigned int	get_pixel_color(t_data *data, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			add_background_img(t_win *game, t_data *img);

/******************************** IMG_LOAD *******************************/

void			load_hero(t_win *game, int size_x, int size_y);
void			load_decor(t_win *game, int size_x, int size_y);
void			load_img(t_win *game);

/******************************** LOOP *******************************/

void			update_map(t_win *game, int *x, int *y);
int				loop_print_map(t_win *game);

/******************************** HOOK *******************************/

int				key_hook(int keycode, t_win *game);

#endif /* ifndef SO_LONG_H */
