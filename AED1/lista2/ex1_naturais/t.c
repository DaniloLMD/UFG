#include <stdio.h>

// Função para imprimir um subconjunto
void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        if (subset[i] == 1) {
            printf("%d ", i + 1); // i + 1 para converter de índice 0-based para 1-based
        }
    }
    printf("}\n");
}

// Função para gerar o conjunto das partes
void generatePowerSet(int n) {
    int subset[n];

    // Inicializa o subconjunto como vazio
    for (int i = 0; i < n; i++) {
        subset[i] = 0;
    }

    // Gera todos os subconjuntos usando contagem binária
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            // Testa o j-ésimo bit
            if (i & (1 << j)) {
                subset[j] = 1;
            } else {
                subset[j] = 0;
            }
        }

        // Imprime o subconjunto atual
        printSubset(subset, n);
    }
}

int main() {
    int n;
    printf("Digite o tamanho do conjunto: ");
    scanf("%d", &n);

    printf("Conjunto das partes:\n");
    generatePowerSet(n);

    return 0;
}
