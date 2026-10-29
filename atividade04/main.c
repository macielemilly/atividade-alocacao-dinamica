#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverter_string(char *s) {
    int inicio = 0;
    int fim = strlen(s) - 1;
    char temp;

    while (inicio < fim) {
        temp = s[inicio];
        s[inicio] = s[fim];
        s[fim] = temp;
        inicio++;
        fim--;
    }
}

int main() {
    int tamanho_maximo;

    printf("Digite o tamanho maximo da frase: ");
    scanf("%d", &tamanho_maximo);
    getchar();

    char *frase = (char *) malloc((tamanho_maximo + 1) * sizeof(char));
    if (frase == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    printf("Digite a frase: ");
    fgets(frase, tamanho_maximo + 1, stdin);

    size_t len = strlen(frase);
    if (len > 0 && frase[len - 1] == '\n') {
        frase[len - 1] = '\0';
    }

    inverter_string(frase);

    printf("Frase invertida: %s\n", frase);

    free(frase);
    frase = NULL;

    return 0;
}
