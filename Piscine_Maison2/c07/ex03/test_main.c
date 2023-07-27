/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 02:15:58 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/25 19:41:01 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <malloc.h>

char	*ft_strjoin(int size, char **strs, char *sep);

void	check(int condition)
{
	if (condition)
		printf("OK\n");
	else
		printf(">>> KO\n");
}

void	mcheck(void *p, size_t required_size)
{
	void	*p2;

	p2 = malloc(required_size);
	if (malloc_usable_size(p) == malloc_usable_size(p2))
		printf("OK\n");
	else
		printf(">>> KO\n");
	free(p2);
}

void sigsegv(int signum)
{
	(void)signum;
	puts("segfault");
	exit(0);
}

char **create_tab(int size, ...)
{
	va_list	ap;
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * (size + 1));
	if (tab == NULL)
		return (NULL);
	va_start(ap, size);
	i = 0;
	while (i < size)
	{
		tab[i] = va_arg(ap, char *);
		i++;
	}
	tab[i] = NULL;
	va_end(ap);
	return (tab);
}

int	main(void)
{
	char	**tab;
	char	*result;

	free(NULL);

	signal(SIGSEGV, sigsegv);
	result = ft_strjoin(0, NULL, NULL);
	check(result != NULL);
	free(result);
	result = ft_strjoin(0, NULL, " ");
	check(result != NULL);
	free(result);
	result = ft_strjoin(0, NULL, "");
	check(result != NULL);
	free(result);
	tab = create_tab(1, "Hello");
	result = ft_strjoin(1, tab, NULL);
	check(result != NULL);
	free(tab);
	free(result);
	result = ft_strjoin(1, NULL, " ");
	check(result != NULL);
	free(result);
	result = ft_strjoin(1, NULL, "");
	check(result != NULL);
	free(result);
	tab = create_tab(2, "Hello", "World");
	result = ft_strjoin(2, tab, ", ");
	check(result != NULL);
	check(!strcmp(result, "Hello, World"));
	free(tab);
	free(result);
	tab = create_tab(1, "Hello");
	result = ft_strjoin(1, tab, " ");
	check(result != NULL);
	check(!strcmp(result, "Hello"));
	free(tab);
	free(result);
	tab = create_tab(5, "t", "t", "t", "t", "t");
	result = ft_strjoin(5, tab, "");
	check(result != NULL);
	check(!strcmp(result, "ttttt"));
	free(tab);
	free(result);
	tab = create_tab(4, "Howdy", "Do", "Mother", "Fuckers");
	result = ft_strjoin(4, tab, "-");
	check(result != NULL);
	check(!strcmp(result, "Howdy-Do-Mother-Fuckers"));
	printf("Finished!\n");
	return (0);
}
