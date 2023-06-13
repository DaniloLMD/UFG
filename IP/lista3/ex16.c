#include <stdio.h>

int main(){
    int v[4999], qtd, c, c2, x, vezes, tot = 0;

    scanf("%d", &qtd);

    for(c = 0; c < qtd; c++) scanf("%d", &v[c]);

    for(c = 0; c < qtd; c++){
        vezes = 0;
        x = v[c];
        for(c2 = 0; c2 < qtd; c2++){
            if(v[c2] == x) vezes++;
        }
        if(vezes == 1) tot++;
    }
    printf("%d\n", tot);

    return 0;
}