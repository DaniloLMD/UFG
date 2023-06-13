
#include <stdio.h>

int main(){
    int alunos, qtdMin, v[1000], c, qtdPresente = 0;

    scanf("%d %d", &alunos, &qtdMin);

    for(c = 0; c < alunos; c++){
        scanf("%d", &v[c]);
        if(v[c] <= 0) qtdPresente++;
    }

    if(qtdPresente >= qtdMin) printf("NAO\n");
    else{
        printf("SIM\n");
        return 0;
    }

    for(c = alunos - 1; c >= 0; c--){
        if(v[c] <= 0) printf("%d\n", c + 1);
    }

    return 0;
}