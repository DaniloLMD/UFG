#include <stdio.h>

double compute_pi( int n ){
    int c1 = 2;
    int c2 = 1;
    int c;
    double x = 1;
    for(c = 1; c <= n; c++){
        x *= (double) c1/c2;
        if(c % 2 == 0){
            c1 += 2;
        }else if(c % 2 == 1){
            c2 += 2;
        }
    }
    return 2*x;
}

int main(){
    int qtd;
    double pi;
    scanf("%d", &qtd);
    pi = compute_pi(qtd);
    printf("%.12lf\n", pi);
    return 0;
}