#include <stdio.h>

int main(){
    int qtd, v[1000], c, m1 = 0, m2 = 0;
    double media = 0;
    
    scanf("%d", &qtd);

    for(c = 0; c < qtd; c++){
        scanf("%d", &v[c]);
        media += v[c];
    }
    media /= qtd;

    if(qtd <= 5){
        printf("QUANTIDADE DE ELEMENTOS INVALIDOS!\n");
        return 0;
    }

    for(c = 0; c < qtd; c++){
        if(qtd % 2 == 1){
            if(c == qtd / 2) continue;
        }
        else if(qtd % 2 == 0){
            if(c == qtd / 2 || c == qtd / 2 - 1) continue;
        }

        if(c < qtd / 2){
            if(v[c] > media) m1++;
        }
        else if(c > qtd / 2){
            if(v[c] > media) m2++;
        }
    }
    printf("%.2lf %d %d ", media, m1, m2);
    if(m1 > m2) printf("PRIMEIRA METADE\n");
    else if(m2 > m1) printf("SEGUNDA METADE\n");
    else printf("EMPATE\n");

    return 0;
}