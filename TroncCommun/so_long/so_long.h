/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:19:41 by julien            #+#    #+#             */
/*   Updated: 2022/10/18 18:24:45 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <sys/time.h>
# include <fcntl.h>
# include "mlx.h"
# define TILESIZE_Y	50
# define TILESIZE_X	48
# define ERRFORM	1
# define ERRWALL	2
# define ERRCHAR	3
# define ERRELEM	4
# define ERREXIT	5
# define ERRITEM	6
# define ERRARGV	7

typedef struct s_img {
	char				*name;
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					size_x;
	int					size_y;
}				t_img;

typedef struct s_map {
	int		line;
	int		size_line;
	int		nbr_of_line;
	int		exit;
	int		pos;
	int		item;
	int		item_found;
	int		x_exit;
	int		y_exit;
	char	*strmap;
}				t_map;

typedef struct s_lst_near {
	int					x;
	int					y;
	int					*value;
	struct s_lst_near	*next;
}				t_lst_near;

typedef struct s_lst_img {
	void					*mlx;
	void					*win;
	int						pos_hero_x;
	int						pos_hero_y;
	int						count_move;
	int						exit_found;
	int						item_found;
	int						letsgo_up;
	int						letsgo_down;
	int						letsgo_left;
	int						letsgo_right;
	int						i;
	unsigned long long int	msec;
	char					**map2d;
	int						**map2d_int;
	int						map2d_int_x;
	int						map2d_int_y;
	int						**map2d_pix;
	t_map					*map;
	t_img					*hero;
	t_img					*hero_left;
	t_img					*hero_feet_left;
	t_img					*hero_right;
	t_img					*hero_feet_right;
	t_img					*hero_back;
	t_img					*floor;
	t_img					*wall;
	t_img					*exit;
	t_img					*item;
}				t_lst_img;

int						check_if_is(t_lst_img *boximg, t_map *map, \
														char *hero_pos);
t_img					*ft_new_img(char *filename, void *mlx, void *win);
void					update_font_hero(t_img *below, t_img *above);
void					update_font_hero_bonus(t_img *below, t_img *above, \
																int y);
void					print_img(t_lst_img *boximg, t_img *img, int x, int y);
void					choose_img(t_lst_img *boximg, char *line_map2d, int y);
void					ft_put_img(t_img *img);
void					return_err(int errno, t_map *map, t_lst_img *boximg);
int						verif_way(t_lst_img *boximg, int x, int y, int step);
void					init_map(t_map *map, char *str, t_lst_img *boximg);
void					init_box(t_lst_img *boximg, t_map *map, char *map_name);
void					init_imgs(t_img *imgs[16], t_img *hero, \
										t_img *hero_left, t_img *hero_right);
void					init_move(t_lst_img *boximg, struct timeval *time, \
																int *y, int *x);
int						cmp_line_size(char *str, t_map *map, t_lst_img *boximg);
void					set_exit(t_map *map, int x, int y);
void					printmap(char **map2d, t_lst_img *boximg);
void					refresh_win(int *axe, int key, t_lst_img *boximg, \
																	t_img *img);
void					make_map(char *map_name, t_map *map, t_lst_img *boximg);
int						end_game(t_lst_img *boximg);
void					put_tab2d_int(char **tab2d, int **tab2d_int);
int						**tab2d_char_to_int(char **tab2d);
void					free_map2d(void **map2d, int sizeof_line);
void					free_img(t_lst_img *boximg);
void					print_img(t_lst_img *boximg, t_img *img, int x, int y);
int						move_down(t_lst_img *boximg, int *y, int *x);
int						move_up(t_lst_img *boximg, int *y, int *x);
int						stop_move(int key, t_lst_img *boximg);
unsigned long long int	return_msec(struct timeval *time);
int						check_all_letsgo(t_lst_img *boximg);
#endif
/* 46% de la hauteur; 78% de la largeur */
