#include <stdio.h>
int main(void)
{
	//parametres : tableau actuel, index acutel, taille du tableau
	int test1[1];
	test1[0] == '1';
	printf("tableau de 1 :");
	if(ft_check_duplcate(test,0,1) == 1)
		printf("ok\n");
	else
		printf("ko\n");
	int test2Valid[4] = {1, 2, 2, 1};
	printf("tableau de 2:");
	if(ft_check_duplicate(test,3,2) == 1)
		printf("ok\n");
	else
		printf("ko\n");
	int test2Invalid[4] = {1, 2, 1 ,0};
	printf("tableau de 2(invalide) : ");
	if( ft_check_duplicate(test,2,2) == 0)
		printf("ok");
	else
		printf("ko");
	int test3Invalid[9] = {1, 2, 3, 3, 3, 0 , 0, 0, 0};
	printf("tableau de 3 : ");
	if(ft_check_duplicate(test,4, 3) == 0)
		printf("ok");
	else
		printf("ko");

}
