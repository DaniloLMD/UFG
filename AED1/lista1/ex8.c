#include <stdio.h>
#include <stdlib.h>

struct arvore{
    int qtd_familias;
    int *familias;
};

typedef struct arvore tree;
typedef char bool;

int main(){

    tree troia;
    int qtd_pessoas, qtd_linhas;
    int c, p1, p2, t;

    bool x;

    scanf("%d %d", &qtd_pessoas, &qtd_linhas);

    troia.qtd_familias = qtd_pessoas;
    troia.familias = (int*) malloc(qtd_pessoas * sizeof(int));
    for(c = 0; c < qtd_pessoas; c++){
        troia.familias[c] = c;
    }

    for(c = 0; c < qtd_linhas; c++){
        scanf("%d %d", &p1, &p2);

        p1 = p1 - 1;
        p2 = p2 - 1;

        if(p1 > p2){
            t = p1;
            p1 = p2;
            p2 = t;
        }

        if(troia.familias[p1] != troia.familias[p2]) troia.qtd_familias--;   
        troia.familias[p2] = troia.familias[p1]; 
    }

    printf("%d\n", troia.qtd_familias);

    return 0;
}