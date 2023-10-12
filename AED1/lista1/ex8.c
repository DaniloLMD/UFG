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
    int c, p1, p2;

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

        if(troia.familias[p1] != troia.familias[p2]) troia.qtd_familias--;   
        troia.familias[p2] = troia.familias[p1];

        
    }

    printf("%d\n", troia.qtd_familias);

    return 0;
}

/*bool procura_isolados(int *v, int size){
    int c1, c2;
    bool achei_isolado;
    int isolados = 0;

    for(c1 = 0; c1 < size; c1++){
        achei_isolado = 1;
        for(c2 = 0; c2 < size; c2++){
            if(c2 == c1) continue;

            if(v[c1] == v[c2]){
                achei_isolado = 0;
            }
        }

        if(achei_isolado == 1){
            return 1; //verdadeiro -> encontrei um isolado
        }
    }

    return 0; //falso -> nao tem nenhum isolado
}

if( !procura_isolados(troia.familias, qtd_pessoas) ) break;*/