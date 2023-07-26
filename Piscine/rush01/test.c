#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void generatePermutations(int arr[], int start, int end) {
    if (start == end) {
        // Une permutation est générée, affichez-la ici
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            // Effectuez un échange pour créer une nouvelle permutation
				printf("je suis dans la boucle aller %d et je swap %d et %d\n", start, arr[start], arr[i]);
            swap(&arr[start], &arr[i]);
            
            // Récursion pour générer les permutations restantes
            generatePermutations(arr, start + 1, end);
            
            // Annuler l'échange pour revenir à l'état précédent
				printf("je suis dans la boucle retour %d et je swap %d et %d\n", start, arr[start], arr[i]);
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Toutes les permutations possibles :\n");
    generatePermutations(arr, 0, n - 1);

    return 0;
}

