#include <stdio.h>

int main(){
    int lin, col, i, j, minLin, maxLin, minCol, maxCol, qtd = 0;
    int m[10][10];

    scanf("%d %d", &i, &j);

    if(i > 10 || i < 1 || j > 10 || j < 0){
        printf("Dimensao invalida\n");
        return 0;
    }


    for(lin = 0; lin < i; lin++){
        for(col = 0; col < j; col++){
            scanf("%d", &m[lin][col]);
        }
    }

    minLin = 0;
    maxLin = i - 1;
    maxCol = j - 1;
    while(1){

        if(minLin < i && maxLin > 0 && minCol < j && maxCol > 0){
        //printando a menor linha
            lin = minLin;
            for(col = minCol; col <= maxCol && qtd < i * j; col++){
                qtd++;
                printf("%d ", m[lin][col]);
            }

            minLin++;

            //printando  a ultima coluna
            col = maxCol;
            for(lin = minLin; lin <= maxLin && qtd < i * j; lin++){
                qtd++;
                printf("%d ", m[lin][col]);
            }

            maxCol--;
            //printando a ultima linha
            lin = maxLin;    
            for(col = maxCol; col >= minCol && qtd < i * j; col--){
                qtd++;
                printf("%d ", m[lin][col]);
            }

            maxLin--;
            //printando a menor coluna
            col = minCol;
            for(lin = maxLin; lin >= minLin && qtd < i * j; lin--){
                qtd++;
                printf("%d ", m[lin][col]);
            }
            minCol++;
        }
        else if(minLin >= i || maxLin <= 0){
            lin = maxLin;
            for(col = minCol; col <= maxCol && qtd < i * j; col++){
                qtd++;
                printf("%d ", m[lin][col]);
            }
        }
        else if(minCol >= j || maxCol <= 0){
            col = maxCol;
            for(lin = minLin; lin <= maxLin && qtd < i * j; lin++){
                qtd++;
                printf("%d ", m[lin][col]);
            }
        }

        if(qtd >= i * j) break;
    }
    
    printf("\n");
    return 0;
}