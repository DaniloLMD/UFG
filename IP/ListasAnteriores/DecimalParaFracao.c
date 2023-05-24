#include <stdio.h>

int potDez(int x){
    int y;
    int resultado = 1;
    for(y = 0; y < x; y++){
        resultado *= 10;
    }
    return resultado;
}   

int main(){
    double n;
    int n2, c = 0, cont;

    scanf("%lf", &n);

    n2 = n;
    while(n2 != n){
        n *= 10;
        n2 = n;
        c++;
    }

    c = potDez(c);

    for(cont = 2; cont <= n2 && cont <= c; cont++){
        printf("%d\n", cont);
        if(n2%cont == 0 && c%cont == 0){
            n2 /= cont;
            c /= cont;
        }
    }
    printf("%d/%d\n", n2, c);
    return 0;
}