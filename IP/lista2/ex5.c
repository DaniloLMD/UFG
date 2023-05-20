#include <stdio.h>
#include <math.h>

int raizesEq2Grau(double a, double b, double c, double *r1, double *r2){
    double delta;

    delta = b*b - (4*a*c);
    if(delta < 0){
        return 0;
    }else if(delta == 0){
        *r1 = (-b)/(2*a);
        return 1;
    }else if(delta > 0){
        *r1 = (-b + sqrt(delta))/(2*a);
        *r2 = (-b - sqrt(delta))/(2*a);
        return 2;
    }
}

int main(){
    double a, b, c;
    double x1, x2, t;
    int qtd;

    scanf("%lf %lf %lf", &a, &b, &c);
    qtd = raizesEq2Grau(a, b, c, &x1, &x2);
    
    if(x1 > x2 && qtd > 1){
        t = x1; 
        x1 = x2;
        x2 = t;
    }


    switch(qtd){
        case 0:

            printf("RAIZES IMAGINARIAS\n");
            break;
        case 1:
            printf("RAIZ UNICA\n");
            printf("X1 = %.2lf\n", x1);
            break;
        case 2: 
            printf("RAIZES DISTINTAS\n");
            printf("X1 = %.2lf\n", x1);
            printf("X2 = %.2lf\n", x2);
            break;
    }

    return 0;
}