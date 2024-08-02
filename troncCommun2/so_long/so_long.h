/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:16:15 by judetre           #+#    #+#             */
/*   Updated: 2024/07/31 16:48:16 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 
# include "libft/libft.h"
# include "mlx/mlx.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ELEM_SIZE_X 48
# define ELEM_SIZE_Y 50
# define ERR_SHAPE 10
# define STR_ERR_SHAPE "Error\nThe map isn't rectangular"
# define ERR_WALL 11
# define STR_ERR_WALL "Error:\nThe map isn't surrounded by walls"
# define ERR_HERO 12
# define STR_ERR_HERO "Error\nNot enough or too many hero"
# define ERR_ITEM 13
# define STR_ERR_ITEM "Error\nThe map must contain at least one object"
# define ERR_EXIT 14
# define STR_ERR_EXIT "Error\nThe map must contain one Exit"
# define ERR_WAY 15
# define STR_ERR_WAY "Error\nthe exit or/and at least one item is inaccessible"
# define ERR_MALLOC 16
# define STR_ERR_MALLOC "Error\nCannot allocate memory"
# define ERR_IMG 17
# define STR_ERR_IMG "Error\nCannot load one or more image"
# define ERR_ELEM 18
# define STR_ERR_ELEM "Error\nThe map contains bad characters"
# define ERR_WAY_EXIT 19
# define STR_ERR_WAY_EXIT "Error\nThe exit is not accessible."
# define ERR_WAY_ITEM 20
# define STR_ERR_WAY_ITEM "Error\nOne or more item is not accessible."

/********************** STRUCT FOR VERIF_WAY *********************/

typedef struct s_lst_near
{
	int					x;
	int					y;
	int					*value;
	struct s_lst_near	*next;
}		t_lst_near;

typedef struct s_lst_lst
{
	t_lst_near			*near;
	struct s_lst_lst	*next;
}		t_lst_lst;

typedef struct s_way
{
	int					**map2d_int;
	int					item_found;
	int					exit_found;
}				t_way;

/********************** STRUCT FOR SO_LONG *********************/

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}				t_data;

typedef struct s_img
{
	t_data				wall;
	t_data				item;
	t_data				exit;
	t_data				floor;
	t_data				hero;
	t_data				hero_right;
	t_data				hero_left;
	t_data				hero_back;
}				t_img;

typedef struct s_map
{
	int					map_size_y;
	int					map_size_x;
	int					hero;
	int					hero_direction;
	int					hero_y;
	int					hero_x;
	int					count_move;
	int					item;
	int					exit;
	int					err_map;
}				t_map;

typedef struct s_win
{
	void				*mlx;
	void				*win;
	char				**map2d;
	int					exit_success;
	t_map				map;
	t_img				img;
	t_way				way;
	t_lst_lst			*lst;
}				t_win;

/********************************* EXIT_GAME ********************************/

void			free_lst(t_lst_lst *lst);
void			free_img(t_win *game);
int				close_window(t_win *game);
void			exit_failure(int err, char *str_err, t_win *game);

/********************************* CHECK_MAP ********************************/

void			check_ber_extension(char *map);
void			check_size_map(t_win *game);
void			check_wall_map(t_win *game);
void			check_elem_map(t_win *game);
void			check_wrong_characters(t_win *game);

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

/******************************** VERIF_WAY *******************************/

int				**map2d_char_to_int(t_win *game);
void			verif_way(t_win *game, int x, int y, int step);
void			free_lst(t_lst_lst *lst);

/******************************** LST_UTLIS *******************************/

t_lst_lst		*lst_lstlast(t_lst_lst *lst);
void			lstlstadd_back(t_lst_lst **lst, t_lst_lst *neW);
t_lst_lst		*lst_lstnew(t_lst_near **near, t_win *game);

/******************************** LST_NEAR_UTLIS ***************************/

t_lst_near		*lstlast(t_lst_near *lst);
void			lstadd_back(t_lst_near **lst, t_lst_near *new);
t_lst_near		*lstnew(int y, int x, int *value, t_win *game);

#endif /* ifndef SO_LONG_H */
