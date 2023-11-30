/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judetre <julien.detre.dev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:02:56 by judetre           #+#    #+#             */
/*   Updated: 2023/11/28 14:03:06 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_ind
{
	size_t	i;
	size_t	lastindex;
	size_t	count;
	int		ifarg;
}				t_ind;

int		ft_printf(const char *str, ...);
#endif
