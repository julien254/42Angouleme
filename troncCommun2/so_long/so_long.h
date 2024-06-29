/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:16:15 by judetre           #+#    #+#             */
/*   Updated: 2024/06/29 16:05:15 by jdetre           ###   ########.fr       */
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

typedef struct s_map {

	size_t	map_size_y;
	size_t	map_size_x;
	int		hero_y;
	int		hero_x;
	int		item;
	int		exit;
	int		err_map;
}				t_map;

typedef struct s_win {
	void	*mlx;
	void	*win;
	char	**map2d;
	t_map	map;
}				t_win;

int     close_window(t_win *game);
char    **read_map(char *file);

#endif /* ifndef SO_LONG_H */
