#include <stdio.h>

int main(){
    int n, v1[1000], v2[1000], c, maior, k = 1, menor;

    scanf("%d", &n);

    for(c = 0; c < n; c++){
        scanf("%d", &v1[c]);
    }

    maior = v1[0];
    menor = v1[0];
    for(c = 0; c < n; c++){
        v2[c] = v1[n - k];
        k++;
        if(v1[c] > maior) maior = v1[c];
        if(v1[c] < menor) menor = v1[c];

        printf("%d", v1[c]);
        if(c != n - 1) printf(" ");
        else printf("\n");
    }

    for(c = 0; c < n; c++){
        printf("%d", v2[c]);
        if(c != n - 1) printf(" ");
        else printf("\n");
    }
    printf("%d\n%d\n", maior, menor);

    return 0;
}