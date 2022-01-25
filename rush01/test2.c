#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		ft_putchar(str[a]);
		a++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	temp_a;

	temp_a = *a;
	*a = *b;
	*b = temp_a;
}

void init_tab_combcol(int tabcomb_col[1296][4])
{
	int j;
	int k;

	j = 0;
	while (j < 1296)
	{
		k = 0;
		while (k < 4)
		{
			tabcomb_col[j][k]= 0;
			k++;
		}
		j++;
	}
}
void init_tab_possibility(int possibility[4][6][4])
{
	int j;
	int k;
	int l;

	j = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 6)
		{
			l = 0;
			while (l < 4)
			{
				possibility[j][k][l] = 42;
				l++;
			}
			k++;
		}
		j++;
	}
}

int return_size_possibility(int possibility[4][6][4],int *ligne)
{
	int k;
	int l;

	k = 0;
	while (k < 6)
	{
		l = 0;
		while (l < 4)
		{
			if (possibility[*ligne][k][l] == 42)
			{
				*ligne = *ligne + 1;
				return (k);	
			}
			else if (k == 5 && l == 3)
			{
				*ligne = *ligne + 1;
				return (k + 1);
			}
			l++;
		}
		k++;
	}
}

int check_condition1_ligne (int tab_all_comb_base[1296][4], int cond1, int i)
{
	int i2;
	int count;
	int max;

	i2 = 0;
	count = 0;
	max = 0;
	while (i2 < 4)
	{
		if (tab_all_comb_base[i][i2] > max)
		{
			count++;
			max = tab_all_comb_base[i][i2];
		}
		i2++;
	}
	if (count == cond1)
		return (1);
	else
		return (0);
}

int check_condition2_ligne (int tab_all_comb_base[1296][4], int cond2, int i)
{
	int i2;
	int count;
	int max;

	i2 = 3;
	count = 0;
	max = 0;
	while (i2 >= 0)
	{
		if (tab_all_comb_base[i][i2] > max)
		{
			count++;
			max = tab_all_comb_base[i][i2];
		}
		i2--;
	}
	if (count == cond2)
		return (1);
	else
		return (0);
}

int check_condition1_col (int tabcomb_col[1296][4], int cond1, int num_poss,
		int possibility[4][6][4], int col)
{
	int ligne;
	int count;
	int max;

	ligne = 0;
	count = 0;
	max = 0;
	while (ligne < 4)
	{
		if (possibility[ligne][tabcomb_col[num_poss][ligne]][col] > max)
		{
			count++;
			max = possibility[ligne][tabcomb_col[num_poss][ligne]][col];
		}
		ligne++;
	}
	if (count == cond1)
		return (1);
	else
		return (0);
}

int check_condition2_col (int tabcomb_col[1296][4], int cond2, int num_poss,
		int possibility[4][6][4], int col)
{
	int ligne;
	int count;
	int max;
	int colone;

	ligne = 3;
	count = 0;
	max = 0;
	while (ligne >= 0)
	{
		if (possibility[ligne][tabcomb_col[num_poss][ligne]][col] > max)
		{
			count++;
			max = possibility[ligne][tabcomb_col[num_poss][ligne]][col];
		}
		ligne--;
	}
	if (count == cond2)
		return (1);
	else
		return (0);
}

void check_and_push_allcomb_in_possibility (int tab_all_comb_base[1296][4],
		int possibility[4][6][4], int ligne,
		int indexcond[2], int cond[16])
{
	int i;
	int j;
	int index_possibility;

	i = 0;
	j = 0;
	index_possibility = 0;
	while (i < 24)
	{	
		if (check_condition1_ligne (tab_all_comb_base, cond[indexcond[0]], i))
		{
			if (check_condition2_ligne (tab_all_comb_base, cond[indexcond[1]], i))
			{
				j = 0;
				while (j < 4)
				{
					possibility[ligne][index_possibility][j] =
						tab_all_comb_base[i][j];
					j++;
				}
				index_possibility++;
			}
		}
		i++;
	}
}

void search_comb_col (int tabcomb_col[1296][4], int *index, int *tabindex, int possibility[4][6][4])
{
	int ligne;
	int ligne1;
	int ligne2;
	int ligne3;
	int ligne4;

	ligne = 0;
	ligne1 = return_size_possibility(possibility, &ligne);
	ligne2 = return_size_possibility(possibility, &ligne);
	ligne3 = return_size_possibility(possibility, &ligne);
	ligne4 = return_size_possibility(possibility, &ligne);
	while (tabindex[0] < ligne1)
	{
		tabindex[1] = 0;
		while (tabindex[1] < ligne2)
		{
			tabindex[2] = 0;
			while (tabindex[2] < ligne3)
			{
				tabindex[3] = 0;
				while (tabindex[3] < ligne4)
				{
					tabcomb_col[*index][0] = tabindex[0];
					tabcomb_col[*index][1] = tabindex[1];
					tabcomb_col[*index][2] = tabindex[2];
					tabcomb_col[*index][3] = tabindex[3];
					*index = *index + 1;
					tabindex[3]++;
				}
				tabindex[2]++;
			}
			tabindex[1]++;
		}
		tabindex[0]++;
	}
}

void check_col_and_put_result (int possibility[4][6][4], int *cond)
{
	int tabcomb_col[1296][4];
	int tabindex[4];
	int index;
	int indexcond[2];
	int col;

	init_tab_combcol(tabcomb_col);
	index = 0;
	search_comb_col (tabcomb_col, &index, tabindex, possibility);
	index = 0;
	tabindex[3] = 0;
	while (index < sizeof (tabcomb_col) / (sizeof (int) * 4))
	{
		indexcond[0] = 8;
		indexcond[1] = 9;
		tabindex[0] = 0;
		col = 0;
		while (col < 4)
		{

			if (check_condition1_col
					(tabcomb_col, cond[indexcond[0]], index, possibility, col))
			{
				if (check_condition2_col
						(tabcomb_col, cond[indexcond[1]], index, possibility, col))
				{
					indexcond[0] = indexcond[0] + 2;
					indexcond[1] = indexcond[1] + 2;
					tabindex[0]++;
					col++;
					if (tabindex[0] == 4)
					{
						if (possibility[0][tabcomb_col[index][0]][0] + possibility[1][tabcomb_col[index][1]][0] \
								+ possibility[2][tabcomb_col[index][2]][0] + possibility[3][tabcomb_col[index][3]][0] == 10 \
								&& possibility[0][tabcomb_col[index][0]][1] + possibility[1][tabcomb_col[index][1]][1] \
								+ possibility[2][tabcomb_col[index][2]][1] + possibility[3][tabcomb_col[index][3]][1] == 10 \
								&& possibility[0][tabcomb_col[index][0]][2] + possibility[1][tabcomb_col[index][1]][2] \
								+ possibility[2][tabcomb_col[index][2]][2] + possibility[3][tabcomb_col[index][3]][2] == 10 \
								&& possibility[0][tabcomb_col[index][0]][3] + possibility[1][tabcomb_col[index][1]][3] \
								+ possibility[2][tabcomb_col[index][2]][3] + possibility[3][tabcomb_col[index][3]][3] == 10)
						{
							tabindex[3]++;
							printf ("Solution numero %d :\n", tabindex[3]);
							printf ("%d ", possibility[0][tabcomb_col[index][0]][0]);
							printf ("%d ", possibility[0][tabcomb_col[index][0]][1]);
							printf ("%d ", possibility[0][tabcomb_col[index][0]][2]);
							printf ("%d\n", possibility[0][tabcomb_col[index][0]][3]);
							printf ("%d ", possibility[1][tabcomb_col[index][1]][0]);
							printf ("%d ", possibility[1][tabcomb_col[index][1]][1]);
							printf ("%d ", possibility[1][tabcomb_col[index][1]][2]);
							printf ("%d\n", possibility[1][tabcomb_col[index][1]][3]);
							printf ("%d ", possibility[2][tabcomb_col[index][2]][0]);
							printf ("%d ", possibility[2][tabcomb_col[index][2]][1]);
							printf ("%d ", possibility[2][tabcomb_col[index][2]][2]);
							printf ("%d\n", possibility[2][tabcomb_col[index][2]][3]);
							printf ("%d ", possibility[3][tabcomb_col[index][3]][0]);
							printf ("%d ", possibility[3][tabcomb_col[index][3]][1]);
							printf ("%d ", possibility[3][tabcomb_col[index][3]][2]);
							printf ("%d\n", possibility[3][tabcomb_col[index][3]][3]);
						}
					}
				}
				else
					break;
			}
			else
			{
				break;
			}
		}
		index++;
		if (index == sizeof (tabcomb_col) / (sizeof (int) * 4) && tabindex[3] == 0)
		{
			printf ("error!\n");
		}
	}
}

int main (int argv, char *argc[])
{
	int tab_all_comb_base[24][4];
	int possibility[4][6][4];
	int ligne;
	int cond[16];
	int indexcond[2];

	indexcond[0] = 0;
	indexcond[1] = 0;
	if (argv != 2)
		ft_putstr("error!");

	else
	{
		while (argc[1][indexcond[0]] != '\0')
		{
			if (argc[1][indexcond[0]] >= '0' && argc[1][indexcond[0]] <= '9')
			{
				indexcond[1]++;

			}
			indexcond[0]++;
		}
		if (indexcond[1] != 16)
		{
			ft_putstr("error!");
		}
		else
		{

			cond[0] = argc[1][16] - 48;
			cond[1] = argc[1][24] - 48;
			cond[2] = argc[1][18] - 48;
			cond[3] = argc[1][26] - 48;
			cond[4] = argc[1][20] - 48;
			cond[5] = argc[1][28] - 48;
			cond[6] = argc[1][22] - 48;
			cond[7] = argc[1][30] - 48;
			cond[8] = argc[1][0] - 48;
			cond[9] = argc[1][8] - 48;
			cond[10] = argc[1][2]- 48;
			cond[11] = argc[1][10]- 48;
			cond[12] = argc[1][4] - 48;
			cond[13] = argc[1][12]- 48;
			cond[14] = argc[1][6] - 48;
			cond[15] = argc[1][14] - 48;
			init_tab_possibility(possibility);
			ligne = 0;
			tab_all_comb_base[0][0] = 1;
			tab_all_comb_base[0][1] = 2;
			tab_all_comb_base[0][2] = 3;
			tab_all_comb_base[0][3] = 4;
			tab_all_comb_base[1][0] = 1;
			tab_all_comb_base[1][1] = 2;
			tab_all_comb_base[1][2] = 4;
			tab_all_comb_base[1][3] = 3;
			tab_all_comb_base[2][0] = 1;
			tab_all_comb_base[2][1] = 3;
			tab_all_comb_base[2][2] = 2;
			tab_all_comb_base[2][3] = 4;
			tab_all_comb_base[3][0] = 1;
			tab_all_comb_base[3][1] = 3;
			tab_all_comb_base[3][2] = 4;
			tab_all_comb_base[3][3] = 2;
			tab_all_comb_base[4][0] = 1;
			tab_all_comb_base[4][1] = 4;
			tab_all_comb_base[4][2] = 2;
			tab_all_comb_base[4][3] = 3;
			tab_all_comb_base[5][0] = 1;
			tab_all_comb_base[5][1] = 4;
			tab_all_comb_base[5][2] = 3;
			tab_all_comb_base[5][3] = 2;
			tab_all_comb_base[6][0] = 2;
			tab_all_comb_base[6][1] = 1;
			tab_all_comb_base[6][2] = 3;
			tab_all_comb_base[6][3] = 4;
			tab_all_comb_base[7][0] = 2;
			tab_all_comb_base[7][1] = 1;
			tab_all_comb_base[7][2] = 4;
			tab_all_comb_base[7][3] = 3;
			tab_all_comb_base[8][0] = 2;
			tab_all_comb_base[8][1] = 3;
			tab_all_comb_base[8][2] = 1;
			tab_all_comb_base[8][3] = 4;
			tab_all_comb_base[9][0] = 2;
			tab_all_comb_base[9][1] = 3;
			tab_all_comb_base[9][2] = 4;
			tab_all_comb_base[9][3] = 1;
			tab_all_comb_base[10][0] = 2;
			tab_all_comb_base[10][1] = 4;
			tab_all_comb_base[10][2] = 1;
			tab_all_comb_base[10][3] = 3;
			tab_all_comb_base[11][0] = 2;
			tab_all_comb_base[11][1] = 4;
			tab_all_comb_base[11][2] = 3;
			tab_all_comb_base[11][3] = 1;
			tab_all_comb_base[12][0] = 3;
			tab_all_comb_base[12][1] = 1;
			tab_all_comb_base[12][2] = 2;
			tab_all_comb_base[12][3] = 4;
			tab_all_comb_base[13][0] = 3;
			tab_all_comb_base[13][1] = 1;
			tab_all_comb_base[13][2] = 4;
			tab_all_comb_base[13][3] = 2;
			tab_all_comb_base[14][0] = 3;
			tab_all_comb_base[14][1] = 2;
			tab_all_comb_base[14][2] = 1;
			tab_all_comb_base[14][3] = 4;
			tab_all_comb_base[15][0] = 3;
			tab_all_comb_base[15][1] = 2;
			tab_all_comb_base[15][2] = 4;
			tab_all_comb_base[15][3] = 1;
			tab_all_comb_base[16][0] = 3;
			tab_all_comb_base[16][1] = 4;
			tab_all_comb_base[16][2] = 1;
			tab_all_comb_base[16][3] = 2;
			tab_all_comb_base[17][0] = 3;
			tab_all_comb_base[17][1] = 4;
			tab_all_comb_base[17][2] = 2;
			tab_all_comb_base[17][3] = 1;
			tab_all_comb_base[18][0] = 4;
			tab_all_comb_base[18][1] = 1;
			tab_all_comb_base[18][2] = 2;
			tab_all_comb_base[18][3] = 3;
			tab_all_comb_base[19][0] = 4;
			tab_all_comb_base[19][1] = 1;
			tab_all_comb_base[19][2] = 3;
			tab_all_comb_base[19][3] = 2;
			tab_all_comb_base[20][0] = 4;
			tab_all_comb_base[20][1] = 2;
			tab_all_comb_base[20][2] = 1;
			tab_all_comb_base[20][3] = 3;
			tab_all_comb_base[21][0] = 4;
			tab_all_comb_base[21][1] = 2;
			tab_all_comb_base[21][2] = 3;
			tab_all_comb_base[21][3] = 1;
			tab_all_comb_base[22][0] = 4;
			tab_all_comb_base[22][1] = 3;
			tab_all_comb_base[22][2] = 1;
			tab_all_comb_base[22][3] = 2;
			tab_all_comb_base[23][0] = 4;
			tab_all_comb_base[23][1] = 3;
			tab_all_comb_base[23][2] = 2;
			tab_all_comb_base[23][3] = 1;
			indexcond[0] = 0;
			indexcond[1] = 1;
			while ( ligne < 4)
			{
				check_and_push_allcomb_in_possibility (tab_all_comb_base, possibility, ligne, indexcond, cond);
				indexcond[0] = indexcond[0] + 2;
				indexcond[1] = indexcond[1] + 2;
				ligne++;
			}
			//	printf ("%d %d %d %d %d %d %d %d\n", possibility[0][0][0],
			//			possibility[0][0][1], possibility[0][0][2], possibility[0][0][3],
			//			possibility[0][1][0], possibility[0][1][1], possibility[0][1][2],
			//			possibility[0][1][3]);
			//	printf ("%d %d %d %d %d %d %d %d\n", possibility[1][0][0],
			//			possibility[1][0][1], possibility[1][0][2], possibility[1][0][3],
			//			possibility[1][1][0], possibility[1][1][1], possibility[1][1][2],
			//			possibility[1][1][3]);
			//	printf ("%d %d %d %d %d %d %d %d\n", possibility[2][0][0],
			//			possibility[2][0][1], possibility[2][0][2], possibility[2][0][3],
			//			possibility[2][1][0], possibility[2][1][1], possibility[2][1][2],
			//			possibility[2][1][3]);
			//	printf ("%d %d %d %d %d %d %d %d\n", possibility[3][0][0],
			//			possibility[3][0][1], possibility[3][0][2], possibility[3][0][3],
			//			possibility[3][1][0], possibility[3][1][1], possibility[3][1][2],
			//			possibility[3][1][3]);
			check_col_and_put_result (possibility, cond);
		}

	}
}
