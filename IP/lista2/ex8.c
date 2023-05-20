#include <stdio.h>
#include <math.h>

int absoluto(int n){
    if(n < 0){
        n = n * -1;
    }
    return n;
}
int next_power( int n, int p ){
    int menorDist = 1, pot;
    int c, d1, d2;
    d2 = absoluto(n - menorDist);
    for(c = 1; c < n; c++){
        pot = pow(c, p);
        d1 = absoluto(n - pot);  
        if(d1 < d2){
            d2 = d1;
            menorDist = c;
        }
    }
    return menorDist;
}

int main(){
    int num , pot, base;
    int resultado;
    scanf("%d %d", &num, &pot);
    base = next_power(num, pot);
    resultado = pow(base, pot);
    printf("%d -> %d^%d = %d\n",num, base, pot, resultado);
    return 0;
}