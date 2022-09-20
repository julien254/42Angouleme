/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:34:52 by julien            #+#    #+#             */
/*   Updated: 2022/09/19 17:20:15 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_ind
{
	size_t	i;
	size_t	lastindex;
	size_t	count;
	int		ifarg;
}				t_ind;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_index
{
	size_t	i;
	size_t	len;
}				t_index;

typedef struct s_save
{
	int				fd[50];
	char			residu[50][BUFFER_SIZE + 1];
	int				is_finish[50];
	int				index_currentfd;
}				t_save;

typedef struct s_listgnl
{
	int				fd;
	char			residu[BUFFER_SIZE + 1];
	t_save			save;
}				t_listgnl;

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2, t_listgnl *filed);
void	ft_memset_gnl(char *str);
void	ft_strcpy_gnl(char *s1, char *s2);
int		end_line_gnl(char *residu);
int		ft_printf(const char *str, ...);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strmcpy(const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_malloc(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_put_u_nbr_fd(unsigned int n, int fd);
int		ft_puthexa_fd(unsigned int nbr, int fd, int uppercase);
int		ft_puthexa_ll_fd(size_t nbr, int fd, int uppercase);
int		ft_putadd_fd(size_t hexa, int fd);
int		ft_puttab2_fd(char **tab, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *neW);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *neW);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_recover_fd(char *file);
#endif
