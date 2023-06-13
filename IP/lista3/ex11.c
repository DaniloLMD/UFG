#include <stdio.h>

int main(){
    int n, v[1000000], c, t, qtd = 0;
    double mediana;
    
    scanf("%d", &n);
    
    for(c = 0; c < n; c++){
        scanf("%d", &v[c]);
    }

    while(1){
        for(c = 0; c < n - 1; c++){
            if(v[c] > v[c+1]){
                t = v[c];
                v[c] = v[c+1];
                v[c+1] = t;
            }
            else qtd++;
        }
        if(qtd == n - 1) break;
        qtd = 0;
    }
    if(n%2 == 0){
        mediana = (double) (v[n / 2 - 1] + v[n / 2] ) / 2;
    }
    else{
        mediana = v[n / 2];
    }

    printf("%.2lf\n", mediana);
    return 0;
}