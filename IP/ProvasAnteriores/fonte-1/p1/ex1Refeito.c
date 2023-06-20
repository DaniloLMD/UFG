#include <stdio.h>
#include <math.h>

int main(){
    double s1, s2, s3;
    double d1, d2, d3;
    
    scanf("%lf %lf %lf", &s1, &s2, &s3);

    d2 = s2;
    d1 = sqrt(3) * s1;
    d3 = sqrt(3) * s3;

    if(d1 == d2 && d2 == d3) printf("VOLTAR\n");
    else if(d1 < d2 && d2 < d3) printf("DIREITA\n");
    else if(d1 > d2 && d2 > d3) printf("ESQUERDA\n");
    else printf("PARAR\n");

    return 0;
}