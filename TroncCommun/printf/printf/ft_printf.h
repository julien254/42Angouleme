/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:10:39 by jdetre            #+#    #+#             */
/*   Updated: 2022/05/28 09:13:16 by jdetre           ###   ########.fr       */
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
