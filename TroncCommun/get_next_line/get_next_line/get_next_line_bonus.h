/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:48:15 by julien            #+#    #+#             */
/*   Updated: 2022/04/23 12:21:44 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_save
{
	int				fd[1000];
	char			residu[1000][BUFFER_SIZE + 1];
	int				index_currentfd;
}				t_save;

typedef struct s_list
{
	int				fd;
	char			residu[BUFFER_SIZE + 1];
	char			*ligne;
	t_save			save;
}				t_list;

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcat(char *dst, char *src, size_t size);
size_t		ft_strlen(char *s);
void		ft_strchr(char *s, t_list *filed);
void		ft_strcpy(char *dest, char *src);
char		*ft_strdup(char *s, char end);
#endif
