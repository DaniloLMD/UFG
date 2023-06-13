#include <stdio.h>

void separaDigitos(char *pc, int *pi){
    int c;
    for(c = 0; pc[c] != '\0'; c++){
        pi[c] = pc[c] - '0';
    }
}


int main(){
    char usuario[100000];
    int qtd, qtdFim, k, indice, maior, c;
    int v[100000];

    while(1){
        scanf("%d %d%*c", &qtd, &qtdFim);
        if(qtd == 0 && qtdFim == 0) break;
        scanf("%s%*c", usuario);
        separaDigitos(usuario, v);

        k = qtd - qtdFim;
        for(c = 0; c <= k; c++){
            if(v[c] > maior){
               maior = v[c];  
               indice = c;
            }
            
            if(c == k){
                printf("%d", maior);
                maior = 0;
                k++;
                c = indice;
            }
        
            if(k == qtd) break;
        }
        printf("\n");

    }


    return 0;
}