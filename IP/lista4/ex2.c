#include <stdio.h>
#include <stdlib.h>

int main(){
    int **matriz;
    int *linha;
    int lin, col;
    int i, j, contadorIndice;

    //lendo qtd de Linhas e Colunas(no caso vai ser uma matriz quadrada)
    scanf("%d", &lin);
    col = lin;

    //alocando os bytes necessários para cada linha -> fazendo 1 vetor em que cada elemento será uma linha
    matriz = (int**) malloc(lin * sizeof(int*));


    //percorrendo cada linha(cada elemento do vetor) e alocando outro vetor(em que cada posição será a coluna)
    for(i = 0; i < lin; i++){
        matriz[i] = (int*) malloc(col * sizeof(int));
    }

    //percorrendo a matriz
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    //pegando os elementos da diagonal secundária
    contadorIndice = col - 1;
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            if(j == contadorIndice){
                printf("%d\n", matriz[i][j]);
                contadorIndice--;
            }
        }
    }





    return 0;
}