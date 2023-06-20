#include <stdio.h>

int main(){
    int mat, dependentes;
    float salMin, sal, imposto;
    double impBruto, impLiq, impCobrado, resultado;

    scanf("%d %f %d %f %f", &mat, &salMin, &dependentes, &sal, &imposto);

    if(sal >= 12*salMin) impBruto = 0.2 * sal;
    else if(sal >= 5*salMin) impBruto = 0.08 * sal;
    else impBruto = 0;
    impCobrado = imposto * sal / 100;
    impLiq = impBruto - 300*dependentes;
    resultado = impLiq - impCobrado;

    printf("MATRICULA = %d\n", mat);
    printf("IMPOSTO BRUTO = %.2lf\n", impBruto);
    printf("IMPOSTO LIQUIDO = %.2lf\n", impLiq);
    printf("RESULTADO = %.2lf\n", resultado);
    if(resultado > 0) printf("IMPOSTO A PAGAR\n");
    else if(resultado == 0) printf("IMPOSTO QUITADO\n");
    else printf("IMPOSTO A RECEBER\n");
    return 0;
}