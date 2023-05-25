#include <stdio.h>

int main(){
    double sal, mensalidade;
    int pessoas;
    char plano;
    double totPagar;

    scanf("%lf %d %c %lf", &sal, &pessoas, &plano, &mensalidade);

    if(plano != 'A' && plano != 'E'){
        printf("TIPO DE PLANO INVALIDO\n");
        return 0;
    }

    if(sal <= 1800){
        if(plano == 'A') totPagar = 0.3 * mensalidade;
        else if(plano == 'E') totPagar = 0.25 * mensalidade;
    }else if(sal > 1800 && sal <= 5000){
        if(plano == 'A') totPagar = 0.35 * mensalidade;
        else if(plano == 'E') totPagar = 0.28 * mensalidade;
    }else{
        if(plano == 'A') totPagar = 0.4 * mensalidade;
        else if(plano == 'E') totPagar = 0.31 * mensalidade;
    }
    totPagar *= pessoas;
    
    if(sal - totPagar < sal * 0.3){
        printf("DESCONTO NÃO AUTORIZADO\n");
        return 0;
    }
    
    if(plano == 'E') printf("ENFERMARIA ");
    else printf("APARTAMENTO ");
    printf("%.2lf\n", totPagar);

    return 0;
}