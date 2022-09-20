/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:19:41 by julien            #+#    #+#             */
/*   Updated: 2022/09/20 00:35:12 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H value

# include "libft/libft.h"
# include "mlx.h"

typedef struct	s_img {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		*bits_per_pixel;
	int		*line_length;
	int		*endian;
	int		size_x;
	int		size_y;
}				t_img;

#endif /* ifndef SO_LONG_H */
