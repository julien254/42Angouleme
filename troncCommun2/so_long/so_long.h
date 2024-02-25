/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:16:15 by judetre           #+#    #+#             */
/*   Updated: 2024/01/30 08:37:41 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 
# include "libft/libft.h"
# include "mlx/mlx.h"

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


#endif /* ifndef SO_LONG_H */
