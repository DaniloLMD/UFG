#include <stdio.h>

int main(){
    int v[10000], n, c, c2, maior = 0, qtd = 0;

    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        
        for(c = 0; c < n; c++){
            scanf("%d", &v[c]);
            if(v[c] > maior) maior = v[c];
        }
        for(c = 0; c <= maior; c++){
            for(c2 = 0; c2 < n; c2++){
                if(v[c2] <= c) qtd++;
            }
            printf("(%d) %d\n", c, qtd);
            qtd = 0;
        }
        maior = 0;

    }

    return 0;
}