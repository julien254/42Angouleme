/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:22:10 by uguidoni          #+#    #+#             */
/*   Updated: 2023/11/22 15:43:11 by uguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c, int len);
int	ft_putstr(char *str, int len);
int	ft_putnbr(int nb, int len);
int	ft_unsigned_putnbr(unsigned int nb, int len);
int	ft_putnbr_base_lower(unsigned int nb, int len);
int	ft_putnbr_base_upper(unsigned int nb, int len);
int	ft_pointer(int *ptr, int len);

#endif