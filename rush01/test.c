#include <stdlib.h>
#include <stdio.h>

int 	check_condition1_ligne(int (*tab_all_comb_base)[4], int cond1, int i)
{
	int 	i2;
	int 	count;
	int 	max;

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

int	check_condition2_ligne(int (*tab_all_comb_base)[4], int cond2, int i)
{
        int	i2;
        int	count;
        int	max;

        i2 = 3;
        count = 0;
        max = 0;
        while (i2 != 0)
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

int    check_condition1_col(int (*tabcomb_col)[10000][4], int cond1, int *num_poss, int *possibility, int  *col)
{
        int     ligne;
        int     count;
        int     max;

        ligne = 0;
        count = 0;
        max = 0;
        while (ligne < 4)
        {
                if ( possibility[ligne][tabcomb_col[*num_poss][ligne]][col] > max)
                {
                        count++;
                        max = possibility[ligne][tabcomb_col[*num_poss][ligne]][col];
                }
                ligne++;
        }
        if (count == cond1)
                return (1);
        else
                return (0);
}

int    check_condition2_col(int (*tabcomb_col)[10000][4], int cond2, int *num_poss, int *possibility,int  *col)
{
        int     ligne;
        int     count;
        int     max;
	int 	colone;

        ligne = 3;
        count = 0;
        max = 0;
        while (ligne >= 0)
        {
                if ( possibility[ligne][tabcomb_col[*num_poss][ligne]][col] > max)
                {
                        count++;
                        max = possibility[ligne][tabcomb_col[*num_poss][ligne]][col];
                }
                ligne++;
        }
        if (count == cond2)
                return (1);
        else
                return (0);
}

void	check_and_push_allcomb_in_possibility(int (*tab_all_comb_base)[4], int (*possibility)[24][4], int ligne, int *cond)
{
	int i;
	int j;
	int index_possibility;

	i = 0;
	index_possibility = 0;
	while (i < 24)
	{
		if (check_condition1_ligne(tab_all_comb_base, cond[0], i))
		{
			if (check_condition2_ligne(tab_all_comb_base, cond[1], i))
			{
				while (j < 4)
				{
					possibility[ligne][index_possibility][j] = tab_all_comb_base[i][j];
					j++;
				}
				index_possibility++;
			}
		}
		i++;
	}
}

void 	search_comb_col(int (*tabcomb_col)[4],int *index,int *tabindex, int *possibility)
{
	while (tabindex[0] < sizeof(possibility[0]))
	{
		while (tabindex[1] < sizeof(possibility[1]))
        	{
			while (tabindex[2] < sizeof(possibility[2]))
			{
				while (tabindex[3] < sizeof(possibility[3]))
				{
					tabcomb_col[*index][0] = tabindex[0];
					tabcomb_col[*index][1] = tabindex[1];
					tabcomb_col[*index][2] = tabindex[2];
					tabcomb_col[*index][3] = tabindex[3];
					index++;
					tabindex[3]++;
				}
				tabindex[2]++;
			}
			tabindex[1]++;
		}
		tabindex[0]++;
	}
}

void    check_col_and_put_result(int *possibility,int *cond)
{
	int tabcomb_col[10000][4];
	int tabindex[4];
	int index;
	int num_poss;
	int col;
	
	tabindex[0] = 0;
	tabindex[1] = 0;
	tabindex[2] = 0;
	tabindex[3] = 0;
	index = 0;
	num_poss = 0;
	col = 0;
	index = 0;
	search_comb_col(tabcomb_col, &index, tabindex,possibility);
	index = 0;
	while (index < sizeof(tabcomb_col))
	{
		tabindex[0] = 0;
		while (col < 4)
		{
			
			if (check_condition1_col(&tabcomb_col, cond[0], &num_poss, possibility, &col))
			{
				if (check_condition2_col(&tabcomb_col, cond[1], &num_poss, possibility, &col))
				{
					tabindex[0]++;
				       if (*tabindex == 4)
				       {	       
					printf("match trouver");
				       }
				}
			}
			col++;
		}
		num_poss++;
		index++;
		if (index = sizeof(tabcomb_col))
		{
			printf("error");
		}
	}
}

int main(void)
{
	int tab_all_comb_base[24][4];
	int possibility[4][24][4];
	int ligne;
	int cond[2];

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
        tab_all_comb_base[9][2] = 1;
        tab_all_comb_base[9][3] = 4;
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
printf("%d %d %d %d", possibility[0][0][0], possibility[0][0][1], possibility[0][0][2], possibility[0][0][3]);
		printf("%d %d %d %d", possibility[1][0][0], possibility[1][0][1], possibility[1][0][2], possibility[1][0][3]);
		printf("%d %d %d %d", possibility[2][0][0], possibility[2][0][1], possibility[2][0][2], possibility[2][0][3]);
		printf("%d %d %d %d", possibility[3][0][0], possibility[3][0][1], possibility[3][0][2], possibility[3][0][3]);
	// while ( ligne < 4)
	// {
	//	cond[0] = 4;
	//	cond[1] = 1;
	//	check_and_push_allcomb_in_possibility(tab_all_comb_base, possibility, ligne, cond);
	//	ligne++;
	//	cond[0] = 3;
      //          cond[1] = 2;
        //        check_and_push_allcomb_in_possibility(tab_all_comb_base, possibility, ligne, cond);
          //      ligne++;
	//	cond[0] = 2;
      //          cond[1] = 2;
        //        check_and_push_allcomb_in_possibility(tab_all_comb_base, possibility, ligne, cond);
          //      ligne++;
	//	cond[0] = 1;
      //          cond[1] = 2;
        //        check_and_push_allcomb_in_possibility(tab_all_comb_base, possibility, ligne, cond);
          //      ligne++;
	//	printf("%d %d %d %d", possibility[0][0][0], possibility[0][0][1], possibility[0][0][2], possibility[0][0][3]);
	//	printf("%d %d %d %d", possibility[1][0][0], possibility[1][0][1], possibility[1][0][2], possibility[1][0][3]);
	//	printf("%d %d %d %d", possibility[2][0][0], possibility[2][0][1], possibility[2][0][2], possibility[2][0][3]);
	//	printf("%d %d %d %d", possibility[3][0][0], possibility[3][0][1], possibility[3][0][2], possibility[3][0][3]);
	// }
}
