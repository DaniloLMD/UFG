#include <stdio.h>

void separaDigitos(int n, int *a, int *b, int*c){
    *a = n % 10;
    *b = (n % 100)/10;
    *c = n/100;
}

int main(){
    int n, u, d, c;
    int invertido;
    scanf("%d", &n);

    separaDigitos(n, &u, &d, &c);
    printf("%d%d%d\n", u, d, c);

    return 0;
}