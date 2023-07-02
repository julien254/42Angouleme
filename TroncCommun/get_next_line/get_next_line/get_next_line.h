/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:48:15 by julien            #+#    #+#             */
/*   Updated: 2022/07/01 23:18:58 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4

# endif0	
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_save
{
	int				fd[50];
	char			residu[50][BUFFER_SIZE + 1];
	int				is_finish[50];
	int				index_currentfd;
}				t_save;

typedef struct s_list
{
	int				fd;
	char			residu[BUFFER_SIZE + 1];
	t_save			save;
}				t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, t_list *filed);
void	ft_memset(char *str);
void	ft_strcpy(char *s1, char *s2);
int		end_line(char *residu);
#endif
