/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:48:15 by julien            #+#    #+#             */
/*   Updated: 2022/04/23 08:52:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			residu[BUFFER_SIZE + 1];
	char			*ligne;
	struct s_list	*next;
}				t_list;

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcat(char *dst, char *src, size_t size);
size_t		ft_strlen(char *s);
void		ft_strchr(char *s, t_list *filed);
void		ft_strcpy(char *dest, char *src);
char		*ft_strdup(char *s, char end);
#endif
