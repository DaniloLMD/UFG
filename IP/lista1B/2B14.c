#include <stdio.h>

int main(){
    int n,i=1,soma=0, aux;
    scanf("%d", &n);
    printf("%d = ", n);
    while(1){
        aux = n%i;
        if (i==n) break;
        if(aux==0){
            if(i!=1) printf(" + ");
            printf("%d", i);
            soma= soma+i;
        }
        i++;
    }
    printf(" = %d", soma);
    if (soma==n) {
        printf(" (NUMERO PERFEITO)");
    }
    else {
        printf(" (NUMERO NAO E PERFEITO)");
    }
    return 0;
}
