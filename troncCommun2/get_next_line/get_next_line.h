/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:24:34 by jdetre            #+#    #+#             */
/*   Updated: 2023/12/04 17:18:16 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_save
{
	char	*residue;
	int		size_residue;
	ssize_t	read_size;
}				t_save;

char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	ft_strlcat(char *dst, char *src);
int		if_is_endline(char *str);
char	*ft_strdup(char *src);
char	*free_all(char *line, char *residue);
#endif
