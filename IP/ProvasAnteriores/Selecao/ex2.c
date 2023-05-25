#include <stdio.h>

int main(){
    int n1, n2, n3, n4, n5;
    int organizacao;
    int maior, menor;

    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

    if(n1 < n2 && n2 < n3 && n3 < n4 && n4 < n5){
        organizacao = 1;
    }else if(n1 > n2 && n2 > n3 && n3 > n4 && n4 > n5){
        organizacao = 2;
    }else{
        organizacao = 3;
    }

    maior = n1;
    if(n2 > maior){
        maior = n2;
    }
    if(n3 > maior){
        maior = n3;
    }
    if(n4 > maior){
        maior = n4;
    }
    if(n5 > maior){
        maior = n5;
    }

    menor = n1;
    if(n2 < menor){
        menor = n2;
    }
    if(n3 < menor){
        menor = n3;
    }
    if(n4 < menor){
        menor = n4;
    }
    if(n5 < menor){
        menor = n5;
    }
    printf("MENOR: %d, MAIOR: %d\n", menor, maior);
    switch(organizacao){
        case 1:
            printf("ORDENADO CRESCENTE\n");
            break;
        case 2:
            printf("ORDENADO DECRESCENTE\n");
            break;
        case 3:
            printf("DESORDENADO\n");
            break;
    }

    return 0;
}