#include <stdio.h>

int main(){
    int n, v[10000], c, qtd = 0, maior = 0, indiceMaior = 0;

    scanf("%d", &n);

    for(c = 0; c < n; c++){
        scanf("%d", &v[c]);
    }
    
    maior = v[0];
    for(c = 0; c< n; c++){
        if(v[n - 1] == v[c]) qtd++;
        if(v[c] > maior){
            maior = v[c];
            indiceMaior = c;
        }
    }

    printf("Nota %d, %d vezes\n", v[n-1], qtd);
    printf("Nota %d, indice %d\n", maior, indiceMaior);


    return 0;
}