#include <stdio.h>
#include <stdlib.h>

int modulo(int n){
    if(n < 0) n *= -1;
    return n;
}

int main(){
    char borda, preenchimento;
    int tamanho;
    char **matriz;
    int c, i, j;
    int meio, distancia, minColuna, maxColuna;


    scanf("%d %c %c", &tamanho, &borda, &preenchimento);
    meio = tamanho/2;

    //alocando o espaço da matriz
    matriz = (char**) malloc(tamanho * sizeof(char*));
    for(c = 0; c  < tamanho; c++){
        matriz[c] = (char*) malloc(tamanho * sizeof(char));
    }

    //colocando todos os caracteres em ' '
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++) matriz[i][j] = ' ';
    }

    //colocando a borda da 1 e ultima linha
    matriz[0][meio] = borda;
    matriz[tamanho-1][meio] = borda;
    // colocando o meio e a borda
    for(i = 1; i < tamanho - 1; i++){
        distancia = modulo(meio - i);
        minColuna = 1 + distancia;
        maxColuna = tamanho - 1 - distancia;
        for(j = minColuna; j < maxColuna; j++){
            //colocando o meio
            matriz[i][j] = preenchimento;

            //colocando a borda na posição anterior ou posterior
            if(minColuna == maxColuna - 1){
                matriz[i][j-1] = borda;
                matriz[i][j+1] = borda;
            }
            else if(j == minColuna) matriz[i][j-1] = borda;
            else if(j == maxColuna - 1) matriz[i][j+1] = borda;
        }
    }

    //printando a matriz final
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++) printf("%c", matriz[i][j]);
        printf("\n");
    }

    return 0;
}