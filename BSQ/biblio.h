/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biblio.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matandre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:59:32 by matandre          #+#    #+#             */
/*   Updated: 2022/02/01 13:54:57 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BIBLIO_H
# define BIBLIO_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void					ft_putchar(char c);
void					ft_putstr(char *str);
int						ft_strlen(char *str);
void					ft_init_str(char *str);
int						ft_str_is_printable(char *str);
int						ft_char_is_numeric(char c);
int						ft_erreur(char *str);
char					*ft_recup_map(char *map);
int						ft_len_ligne(char *str);
int						ft_carac(char *str);
int						ft_erreur_map(char *str);

#endif
