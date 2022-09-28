/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:19:41 by julien            #+#    #+#             */
/*   Updated: 2022/09/26 17:44:12 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"
# define TILESIZE	50

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
	int					pos_x;
	int					pos_y;
}				t_img;

typedef struct s_lst_img {
	void	*mlx;
	void	*win;
	t_img	*hero;
	t_img	*floor;
	t_img	*wall;
}				t_lst_img;

t_img	*ft_lst_new_img(char *filename, void *mlx, void *win);
void	ft_putlst_img(t_img *img);
#endif /* ifndef SO_LONG_H */
