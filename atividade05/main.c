#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int main() {
    int n, i, indice_maior = 0;
    float maior_valor_total = 0.0, valor_total;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    Produto *produtos = (Produto *) malloc(n * sizeof(Produto));
    if (produtos == NULL) {
        printf("Erro de alocacao!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\n--- Cadastro do Produto %d ---\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        getchar();
        printf("Nome: ");
        fgets(produtos[i].nome, 50, stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[i].quantidade);
    }

    for (i = 0; i < n; i++) {
        valor_total = produtos[i].preco * produtos[i].quantidade;
        if (i == 0 || valor_total > maior_valor_total) {
            maior_valor_total = valor_total;
            indice_maior = i;
        }
    }

    printf("\n========================================\n");
    printf("PRODUTO COM MAIOR VALOR TOTAL EM ESTOQUE:\n");
    printf("Codigo: %d\n", produtos[indice_maior].codigo);
    printf("Nome: %s\n", produtos[indice_maior].nome);
    printf("Preco: R$ %.2f\n", produtos[indice_maior].preco);
    printf("Quantidade: %d\n", produtos[indice_maior].quantidade);
    printf("Valor Total Acumulado: R$ %.2f\n", maior_valor_total);
    printf("========================================\n");

    free(produtos);
    produtos = NULL;

    return 0;
}
