#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
typedef struct{
    double i, r;
} Complex;
 
typedef struct{
    Complex x1, x2;
} RaizEq2;
 
 typedef char bool;
 
RaizEq2 calcula_raiz_eq_2( double a, double b, double c){
    RaizEq2 func;
    double delta = b*b - 4*a*c;
    if(delta < 0){
        delta *= -1;
        func.x1.r = (-b)/(2*a);
        func.x1.i = (sqrt(delta))/(2*a);
        func.x2.r = (-b)/(2*a);
        func.x2.i = (-sqrt(delta))/(2*a);
    }
    else if(delta >= 0){
        func.x1.r = (-b + sqrt(delta))/(2*a);
        func.x1.i = 0;
        func.x2.r = (-b - sqrt(delta))/(2*a);
        func.x1.i = 0;
    }
    
    return func;
}
 
void complex_print(Complex c){
 
    if(c.r == 0);
    else printf("%.2lf", c.r);
 
    if(c.i == 0);
    else if(c.i == 1 && c.r != 0) printf("+i");
    else if(c.i == 1 && c.r == 0) printf("i");
    else if(c.i == -1) printf("-i");
    else printf("%+.2lfi", c.i);
    
    if(c.i == 0 && c.r == 0) printf("0");
    
    printf("\n");
}
 
int main(){
    double a,b,c;
    RaizEq2 f;
    scanf("%lf %lf %lf", &a, &b, &c);
    f = calcula_raiz_eq_2(a, b, c);
    printf("x1 = ");
    complex_print(f.x1);
    printf("x2 = ");
    complex_print(f.x2);
    
    return 0;
}
