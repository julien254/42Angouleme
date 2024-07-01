/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:44:20 by jdetre            #+#    #+#             */
/*   Updated: 2024/07/01 15:41:02 by jdetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

#define WALL 999999
#define EMPTY 999998
#define ITEM 999997
#define EXIT 999996
#define START 999995

typedef struct s_win {            
	int	pos_x;
	int	pos_y;
	int	item;
}               t_win;

void	show_tab2d_int(int **tab2d, int size_x, int size_y)
{
	int	y;
	int	x;

	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			printf("%d, ", tab2d[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}


void	set_tab2d(char **map2d, int **tab2d)
{
	int	y;
	int	x;

	y = 0;
	while (map2d[y])
	{
		x = 0;
		while (map2d[y][x])
		{
			if (map2d[y][x] == '1')
				tab2d[y][x] = WALL;
			if (map2d[y][x] == '0')
				tab2d[y][x] = EMPTY;
			if (map2d[y][x] == 'C')
				tab2d[y][x] = ITEM;
			if (map2d[y][x] == 'E')
				tab2d[y][x] = EXIT;
			if (map2d[y][x] == 'P')
				tab2d[y][x] = START;
			x++;
		}
		y++;
	}
}

int **make_map_int(int size_x, int size_y)
{
	int	**tab2d;
	int	y;
	int	x;

	tab2d = (int **)malloc(sizeof(int *) * size_y);
	if (!tab2d)
		return (NULL);
	y = 0;
	while (y < size_y)
	{
		tab2d[y] = (int *)malloc(sizeof(int) * size_x);
		if (!tab2d[y])
			return (NULL);
		y++;
	}
	return (tab2d);
}

int	verif_way(int **tab2d, t_win *game)
{
	
}

int main(int argc, char **argv)
{
	int	**tab2d;
	char map[6][6] = {
    {'1', '1', '1', '1', '1', '\0'},
    {'1', 'P', '0', 'C', '1', '\0'},
    {'1', '0', '1', '0', '1', '\0'},
    {'1', 'E', '0', 'C', '1', '\0'},
    {'1', '1', '1', '1', '1', '\0'}};
	char *map2d[6];
	t_win	game;

	map2d[0] = map[0];
	map2d[1] = map[1];
	map2d[2] = map[2];
	map2d[3] = map[3];
	map2d[4] = map[4];
	map2d[5] = NULL;
	game.pos_x = 1;
	game.pos_y = 1;
	game.item = 2;

	tab2d = make_map_int(5, 5);
	set_tab2d((char **)map2d, tab2d);
	show_tab2d_int(tab2d, 5, 5);
	verif_way(tab2d, &game);
}
