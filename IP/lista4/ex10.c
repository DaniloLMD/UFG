#include <stdio.h>
 
int exibidos = 0;
int max, minLin, maxLin, minCol, maxCol;
int matriz[10][10];
 
int minToMax(void){
    int i, j;

    // minCol -> maxCol
    for(j = minCol; j <= maxCol; j++){
        printf("%d ", matriz[minLin][j]);
        exibidos++;
        if(exibidos == max) return -1;
    }
    minLin++;
 
    // minLin -> maxLin    
    for(i = minLin; i <= maxLin; i++){
        printf("%d ", matriz[i][maxCol]);
        exibidos++;
        if(exibidos == max) return -1;
    }
    maxCol--;
 
    return 1;
}
 
int maxToMin(void){
    int i, j;

    // maxCol -> minCol
    for(j = maxCol; j >= minCol; j--){
        printf("%d ", matriz[maxLin][j]);
        exibidos++;
        if(exibidos == max) return -1;
    }
    maxLin--;    
    
    // maxLin -> minLin    
    for(i = maxLin; i >= minLin; i--){
        printf("%d ", matriz[i][minCol]);
        exibidos++;
        if(exibidos == max) return -1;
    }
    minCol++;
    
    return 0;
}
 
int main(){
    int alternador = 0;
    int lin, col, i, j;
    
    //lendo as dimensoes da matriz
    scanf("%d %d", &lin, &col);
    if(lin > 10 || lin < 1 || col > 10 || col < 1){
        printf("Dimensao invalida\n");
        return 0;
    }
    
    
    //lendo a matriz
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++) scanf("%d", &matriz[i][j]);
    }
    
    
    max = lin * col;
    minLin = minCol = 0;
    maxLin = lin - 1;
    maxCol = col - 1;
    //printando a matriz em espiral    
    while(alternador != -1){
        if(alternador == 0){
            alternador = ( minToMax());
        }
        else if(alternador == 1){
            alternador = ( maxToMin());
        }
    }
    
    printf("\n");
    return 0;
}
