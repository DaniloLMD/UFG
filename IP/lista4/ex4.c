#include <stdio.h>
#include <stdlib.h>

int main(){
    int **matriz;
    int lin, col;
    int c, i, j;
    
    //lendo quantidade valida de linhas
    while(1){
        scanf("%d", &lin);
        if(lin >= 1 && lin <= 10) break;
    }

    //lendo quantidade valida de colunas
    while(1){
        scanf("%d", &col);
        if(col >= 1 && col <= 10) break;
    }

    //alocação para a matriz
    matriz = (int**) calloc(lin, sizeof(int*));
    for(c = 0; c < lin; c++) matriz[c] = (int*) calloc(col, sizeof(int));

    //lendo os valores da matriz
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    //printando
    for(i = 0; i < lin; i++){
        printf("linha %d: ", i + 1);
        for(j = 0; j < col; j++){
            printf("%d", matriz[i][j]);
            if(j != col - 1) printf(",");
        }
        printf("\n");
    }

    return 0;
}