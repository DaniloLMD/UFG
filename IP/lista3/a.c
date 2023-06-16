#include <stdio.h>

void ordena(int *v, int tamanho){
    int c, d, t;
    printf("Inicial = %d; Final = %d\n\n", v[0], v[tamanho - 1]);
    while(1){
        for(c = 0; c < tamanho - 1; c++){
           if(v[c] > v[c+1]){
                t = v[c];
                v[c] = v[c+1];
                v[c+1] = t;
            }
            else d++;
        }
        if(d == tamanho - 1) break;
        d = 0;
    }
    printf("Inicial = %d; Final = %d\n\n", v[0], v[tamanho - 1]);
}
int main(){
    /*int v[50000], c, j = 0;
    for(c = 50000; c > 0; c--){
        v[j] = c;
        j++;
    }
    ordena(v, 50000);*/
    printf("50000\n50000\n");
    for(int x = 100000; x > 0; x--) printf("%d\n", x);
    return 0;
}