#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i;
    float *vetor = NULL;
    float soma = 0.0, media = 0.0;

    printf("Digite a quantidade de elementos (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    vetor = (float *) malloc(N * sizeof(float));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    printf("Digite os %d valores:\n", N);
    for (i = 0; i < N; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vetor[i]);
        soma += vetor[i];
    }

    if (N > 0) {
        media = soma / N;
    }
    printf("\nA media aritmetica dos elementos e: %.2f\n", media);

    free(vetor);
    vetor = NULL;

    return 0;
}
