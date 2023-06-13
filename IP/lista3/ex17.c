#include <stdio.h>

double modulo(double n){
    if(n < 0) n *= -1;
    return n;
}

int main(){
    int n, c;
    double v1[1000], v2[1000];
    double vetor[3], maior;

    scanf("%d", &n);

    for(c = 0; c < 3; c++){
        scanf("%lf", &v1[c]);
    }
    for(c = 0; c < 3; c++){
        scanf("%lf", &v2[c]);
        vetor[c] = modulo(v2[c] - v1[c]);
    }
    maior = vetor[0];
    for(c = 0; c < 3; c++){
        if(vetor[c] > maior) maior = vetor[c];
    }
    printf("%.2lf\n", maior);
    
    n -= 2;
    while(n--){
        for(c = 0; c < 3; c++){
            v1[c] = v2[c];
        }
        for(c = 0; c < 3; c++){
            scanf("%lf", &v2[c]);
            vetor[c] = modulo(v2[c] - v1[c]);
        }
        maior = vetor[0];
        for(c = 0; c < 3; c++){
         if(vetor[c] > maior) maior = vetor[c];
        }
        printf("%.2lf\n", maior);
    }
    return 0;
}