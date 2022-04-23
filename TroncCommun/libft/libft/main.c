/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:25:08 by julien            #+#    #+#             */
/*   Updated: 2022/04/16 13:12:20 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <bsd/string.h>
#include <string.h>
#include <ctype.h>

/* -----------------FT_STRLCAT---------------- */

/* int	main(int argc, char *argv[]) */
/* { */
/* //	char test[] = "rrrrrrrrrrrrrrr"; */
/* //	char test2[100] = "iiiiiiiiiiiiiii"; */
/* 	char test1[] = "rrrrrrrrrrrrrrr"; */
/* 	char test12[100] = "iiiiiiiiiiiiiii"; */
/* 	(void)argc; */
/* 	(void)argv; */
/* //	printf("%s", test2); */
/* 	printf("\n"); */
/* //	printf("%ld", strlcat(test2, test, 31)); */
/* 	printf("\n"); */
/* //	printf("%s", test2); */
/* 	printf("\n"); */
/* 	printf("%s", test12); */
/* 	printf("\n"); */
/* 	printf("%ld", ft_strlcat(test12, test1, 31)); */
/* 	printf("\n"); */
/* 	printf("%s", test12); */
/* 	printf("\n"); */
/* 	return (0); */
/* } */

/* -------------------- FT_TOUPPER ------------------- */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	char	c; */
/* 	char	d; */
/* 	c = 'a'; */
/* 	d = 'a'; */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	printf("%c", c); */
/* 	printf("\n"); */
/* 	printf("%c", ft_toupper(c)); */
/* 	printf("\n"); */
/* 	printf("%c", d); */
/* 	printf("\n");; */
/* 	printf("%c", toupper(d)); */
/* 	printf("\n"); */
/* 	return (0); */
/* } */

/* ------------------------ FT_STRCHR ---------------------- */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	char str[] = "tripouille"; */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	printf("%s", strchr(str, 't' + 265)); */
/* 	printf("%s", ft_strchr(str, 't' + 256)); */
/* 	return (0); */
/* } */

/* ---------------------------- FT_STRNCMP ------------------------ */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	char	str[] = "test\300"; */
/* 	char	str2[] = "test\0"; */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	printf("%d", ft_strncmp(str, str2, 6)); */
/* 	printf("\n"); */
/* 	printf("%d", strncmp(str, str2, 6)); */
/* 	printf("\n"); */
/* 	return (0); */
/* } */

/* -------------------------- FT_STRNSTR ---------------------------- */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	printf("%s", strnstr("lorem ipsum dolor sit amet", "dolor", 17)); */
/* 	printf("\n"); */
/* 	printf("%s", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 17)); */
/* 	printf("\n"); */
/* 	return (0); */
/* } */

/* -------------------------------------- FT_ATOI --------------------------- */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	printf("%d", atoi("546:5")); */
/* 	printf("\n"); */
/* 	printf("%d", ft_atoi("546:5")); */
/* 	return (0); */
/* } */

/* ----------------------- FT_STRDUP -------------------- */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	char	*str; */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	str = ft_strdup("salut les mecs"); */
/* 	printf("%s", str); */
/* 	free(str); */
/* 	return (0); */
/* } */

/* ------------------------ FT_SUBSTR ------------------------ */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	printf("%s", ft_substr("tripouille", 0, 42000)); */
/* 	return (0); */
/* } */

/* ------------------------ FT_STRJOIN ------------------------ */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	printf("\n"); */
/* 	printf("%s", ft_strjoin("1234", "5678")); */
/* 	printf("\n"); */
/* 	return (0); */
/* } */

/* ------------------------ FT_STRTRIM ------------------------ */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	char	str[] = "      xxxxxtripouille"; */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	printf("\n"); */
/* 	printf("%s", ft_strtrim(str, " x")); */
/* 	printf("\n"); */
/* 	return (0); */
/* } */

/* ------------------------ FT_SPLIT ------------------------ */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	char	**split; */
/* 	size_t	i; */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	split = ft_split("dsnidsajij", ' '); */
/* 	i = 0; */
/* 	while (split[i]) */
/* 	{ */
/* 		printf("%s", split[i]); */
/* 		printf("\n"); */
/* 		i++; */
/* 	} */
/* 	printf("%s", split[i]); */
/* 	free(split); */
/* 	return (0); */
/* } */

/* ------------------------ FT_ATOI ------------------------ */

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	printf("%s", ft_itoa(2147483647));
	printf("\n");
	return (0);
}

/* ------------------------ FT_LST ------------------------ */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	t_list	*mylist; */
/* 	t_list	*new; */
/* 	t_list	*cpy; */

/* 	mylist = ft_lstnew("en revoir"); */
/* 	new = ft_lstnew("j'espere que ca va"); */
/* 	ft_lstadd_front(&mylist, new); */
/* 	new = ft_lstnew("bonjour"); */
/* 	ft_lstadd_front(&mylist, new); */
/* 	ft_putstr((char *)mylist->content); */
/* 	ft_putchar('\n'); */
/* 	ft_putnbr((int long long)mylist->next); */
/* 	ft_putchar('\n'); */
/* 	new = mylist->next; */
/* 	ft_putstr((char *)new->content); */
/* 	ft_putchar('\n'); */
/* 	ft_putnbr((int long long)new->next); */
/* 	ft_putchar('\n'); */
/* 	new = ft_lstlast(mylist); */
/* 	ft_putstr((char *)new->content); */
/* 	ft_putchar('\n'); */
/* 	ft_putnbr((int long long)new->next); */
/* 	ft_putchar('\n'); */
/* 	ft_putnbr(ft_lstsize(mylist)); */
/* 	ft_putchar('\n'); */
/* 	cpy = ft_lstmap(mylist, &ft_strdup_main, &ft_del); */
/* 	ft_putstr((char *)cpy->content); */
/* 	ft_putchar('\n'); */
/* 	ft_putnbr((int long long)cpy->next); */
/* 	ft_putchar('\n'); */
/* 	ft_lstclear(&cpy, &ft_del); */
/* 	ft_putstr((char *)mylist->content); */
/* 	ft_putchar('\n'); */
/* 	ft_putnbr((int long long)mylist->next); */
/* 	ft_putchar('\n'); */
/* 	return (0); */
/* } */

/* ------------------------ FT_CALLOC ------------------------ */

/* int	main(int argc, char *argv[]) */
/* { */
/* 	void	*str; */
/* 	(void)argc; */
/* 	(void)argv; */
/* 	str = (void *)ft_calloc(20000000000, 1); */
/* 	if (!str) */
/* 	{ */
/* 		ft_putstr_fd("NULL", 1); */
/* 		return (0); */
/* 	} */
/* 	else */
/* 	{ */
/* 	ft_putstr_fd("OK", 1); */
/* 	free(str); */
/* 	return (1); */
/* 	} */
/* } */
