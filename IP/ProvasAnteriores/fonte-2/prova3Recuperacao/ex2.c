                //*-*-*- PARES E ÍMPARES -*-*-*//

#include <stdio.h>
#include <stdlib.h>

void ordena(int *p,int qtd){
    int c, ordem, temp;
    while(1){
        ordem = 0;

        for(c = 0; c < qtd - 1; c++){
            if(p[c] > p[c+1]){
                temp = p[c];
                p[c] = p[c+1];
                p[c+1] = temp;
            }
            else ordem++;
        }

        if(ordem == qtd - 1) break; 
    }
}



int main(){
    int qtd, c, cPar = 0, cImpar = 0;
    int *v, *par, *impar;

    scanf("%d", &qtd);
    v = (int*) malloc(qtd * sizeof(int));
    par = (int *) malloc(qtd * sizeof(int));
    impar = (int*) malloc(qtd * sizeof(int));

    for(c = 0; c < qtd; c++){
        scanf("%d", v + c /*v[c]*/);
        if(v[c] % 2 == 0){
            par[cPar] = v[c];
            cPar++;
        }
        else{
            impar[cImpar] = v[c];
            cImpar++;
        }
    }
    ordena(par, cPar);
    ordena(impar, cImpar);
    for(c = 0; c < cPar; c++) printf("%d\n", par[c]);
    for(c = cImpar - 1; c >= 0; c--) printf("%d\n", impar[c]);



    free(v);
    free(par);
    free(impar);
    return 0;
}