#include <stdio.h>

int main(){
    int matriz[6][6];
    int i, j, cI, cL;
    int maior = -63, soma = 0;

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++) scanf("%d", &matriz[i][j]);
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            //somando o topo e a parte de baixo da ampulheta
            for(cI = 0; cI < 3; cI += 2){
                for(cL = 0; cL < 3; cL++){
                    soma += matriz[i + cI][j + cL];
                }
            }
            soma += matriz[i+1][j+1]; //somando a parte do meio

            if(soma > maior) maior = soma;
            soma = 0;
        }
    }
    printf("%d\n", maior);



    return 0;
}