#include <stdio.h>
#include <stdlib.h>

int CountingSort(int **original_ref, int size){

    int *original = *original_ref;
    int *ordenado, *contador;
    int maior;

    maior = original[0];
    for(int c = 1; c < size; c++){
        if(original[c] > maior) maior = original[c];
    }

    ordenado = (int*) malloc(size * sizeof(int));
    contador = (int*) malloc((maior+1) * sizeof(int));

    for(int c = 0; c <= maior; c++){
        contador[c] = 0;
    }
    
    for(int c = 0; c < size; c++){
        contador[ original[c] ]++;
    }

    for(int c = 1; c <= maior; c++){
        contador[c] += contador[c-1];
    }

    for(int c = 0; c < size; c++){
        ordenado[ --contador[original[c]] ] = original[c];
    }

    *original_ref = ordenado;
    free(original);
    free(contador); 
}

int main(){
    int *v;
    int qtd, angulo, maior_angulo = 0;

    scanf("%d", &qtd);
    qtd++;
    v = (int*) malloc(qtd * sizeof(int));

    v[0] = 0;
    for(int c = 1; c < qtd; c++){
        scanf("%d", &angulo);

        for(int c2 = 0; c2 < c; c2++){
            v[c2] = (v[c2] + angulo) % 360;
        }
    }

    CountingSort(&v, qtd);
    
    for(int c = 0; c < qtd - 1; c++){
        angulo = v[c+1] - v[c];
        if(angulo > maior_angulo) maior_angulo = angulo;
    }

    angulo = 360 - v[qtd-1];
    if(angulo > maior_angulo) maior_angulo = angulo;

    printf("%d\n", maior_angulo);

    return 0;
}