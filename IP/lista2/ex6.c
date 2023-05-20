#include <stdio.h>

double absoluto(double n){
    if(n < 0){
        n *= -1;
    }
    return n;
}

double raiz( double n, double p ){
    double r;
    double ant = 1, k, e;

    while(1){
        if(absoluto(n - (k * k)) <= p){
            break;
        }
        k = (ant + (n/ant))/2;
        ant = k;
        e = absoluto(n - (k * k));
        printf("r: %.9lf, err: %.9lf\n", k, e);
    }

    return r;
}

int main(){
    double num;
    double erro;

    scanf("%lf", &num);
    scanf("%lf", &erro);

    raiz(num, erro);

    return 0;
}