#include <stdio.h>
#include <stdlib.h>

int main() {
    int *V1 = NULL;
    int *V2 = NULL;
    int i;

    V1 = (int *) malloc(10 * sizeof(int));
    if (V1 == NULL) {
        printf("Erro ao alocar V1!\n");
        return 1;
    }

    V2 = (int *) calloc(10, sizeof(int));
    if (V2 == NULL) {
        printf("Erro ao alocar V2!\n");
        free(V1);
        return 1;
    }

    printf("Valores em V1 (malloc - contem lixo de memoria):\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", V1[i]);
    }
    printf("\n\n");

    printf("Valores em V2 (calloc - inicializados com zero):\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", V2[i]);
    }
    printf("\n");

    /*
     Por que V1 e V2 são diferentes?
     O malloc() só reserva o espaço na memória, então ele deixa lá
     os valores antigos (lixo de memória) que já estavam naquela área.
     Já o calloc() reserva e já limpa tudo, zerando cada elemento.
     É por isso que o V1 mostra números aleatórios e o V2 mostra tudo 0.
     */

    free(V1);
    V1 = NULL;

    free(V2);
    V2 = NULL;

    return 0;
}
