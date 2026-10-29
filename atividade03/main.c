#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacidade = 3;
    int tamanho = 0;
    int valor;

    int *vetor = (int *) malloc(capacidade * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocacao inicial!\n");
        return 1;
    }

    printf("Digite numeros inteiros (digite 0 para parar):\n");
    while (1) {
        printf("Numero: ");
        scanf("%d", &valor);

        if (valor == 0) {
            break;
        }

        if (tamanho >= capacidade) {
            capacidade *= 2;
            int *temp = (int *) realloc(vetor, capacidade * sizeof(int));
            if (temp == NULL) {
                printf("Erro ao realocar memoria!\n");
                free(vetor);
                return 1;
            }
            vetor = temp;
        }

        vetor[tamanho] = valor;
        tamanho++;
    }

    printf("\nNumeros armazenados: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\nQuantidade de elementos validos: %d\n", tamanho);
    printf("Capacidade final alocada na Heap: %d posicoes\n", capacidade);

    free(vetor);
    vetor = NULL;

    return 0;
}
