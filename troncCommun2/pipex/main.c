#include <stdio.h>
#include <limits.h>
int main() {
	    printf("Taille de int : %lu octets\n", sizeof(int*));
		    printf("Taille de char : %lu octets\n", sizeof(char *));
			    printf("Taille de void * : %lu octets\n", sizeof(void *));
			    printf("Taille de char : %lu octets\n", sizeof(char));
			    printf("Taille de void : %lu octets\n", sizeof(void));
			    printf("Taille de int : %lu octets\n", sizeof(int));
			    printf("Taille de long int: %lu octets\n%ld", sizeof(long int), LONG_MAX);
			printf("Taille de long long int: %lu octets\n%lld", sizeof(long long int), LLONG_MAX);
			    printf("taille dun size_t: %lu octets\n", sizeof(SIZE_MAX));
			printf("%lu\n", SIZE_MAX);


				    return 0;
}
