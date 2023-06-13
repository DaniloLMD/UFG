#include <stdio.h>
 
int main(){
    int qtd, b;
    int v[100000];
    int v2[1000];
    int c, d;
    
    scanf("%d", &qtd);
    for(c = 0; c < qtd; c++){
        scanf("%d", &v[c]);
    }
 
    scanf("%d", &b);
    for(c = 0; c < b; c++){
        scanf("%d", &v2[c]);
         for(d = 0; d < qtd; d++){
            if(v2[c] == v[d]){
                printf("ACHEI\n");
                break;
            }
            if(d == qtd - 1) printf("NAO ACHEI\n");
         }
    }
 
    return 0;
}