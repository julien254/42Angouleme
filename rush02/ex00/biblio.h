/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biblio.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matandre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:59:32 by matandre          #+#    #+#             */
/*   Updated: 2022/01/30 20:00:58 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BIBLIO_H
# define BIBLIO_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void					ft_init_str(char *str);
unsigned long long int	ft_atoi(char *str);
int						ft_check_0_in_rank(char *pattern, int i);
void					ft_cut_print_pattern(char *str, char *pattern);
void					ft_search_nbr_in_dico_and_print(char *str, \
						char *pattern, int i);
void					ft_recup_dico(char *pattern, char *dict);
void					ft_if_modulo_1(char *pattern, char *pattern_temp, \
						int i, char *str);
void					ft_if_modulo_2(char *pattern, char *pattern_temp, \
						int i, char *str);
void					ft_if_modulo_0(char *pattern, char *pattern_temp, \
						int i, char *str);
void					ft_putchar(char c);
void					ft_putstr(char *str);
void					ft_putnbr(int nb);
int						ft_strlen(char *str);
void					ft_stock_nbr_rank_in_temp(char *pattern, \
						char *pattern_temp, int i, int mode);
void					ft_stock_num_in_temp(char *pattern, char *pattern_temp, \
						int index, int rank);
void					ft_stock_num_10to19_in_temp(char *pattern, char *pattern_temp, \
						int index, int rank);
void					ft_if_str_same_pattern(char *str, int *temp_i, \
						char *pattern, int *j, int *i);
#endif
