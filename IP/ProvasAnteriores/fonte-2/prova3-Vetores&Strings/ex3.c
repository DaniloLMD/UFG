#include <stdio.h>


double decimal(int exp){
    if(exp == 0) return 1;
    else if(exp > 0) return 10 * decimal(exp - 1);
    else if(exp < 0){
        exp *= -1;
        return (double) 1 / (10 * decimal(exp - 1));
    }
}

/**
* Converte a string str para o valor real correspondente.
* @param str string contendo um número real
* @return o número inteiro correspondente
*/
double string2double( const char * str ){
    double num = 0;
    int c, neg = 0, ponto = 0, qtdAtePonto = -1;

    for(c = 0; str[c] != '\0'; c++){
        if(str[c] == '-') neg = 1;
        else if(str[c] == '.') ponto = 1;

        if(!ponto) qtdAtePonto++;
    }
    if(neg) qtdAtePonto--;
    for(c = 0; str[c] != '\0'; c++){
        if(str[c] >= '0' && str[c] <= '9'){
            num += (str[c] - '0') * decimal(qtdAtePonto);
            qtdAtePonto--;
        }
    }


    if(neg) num *= -1;
    return num; 
}

int main(){
    char v[128];
    double n;
    
    while(scanf("%s", v) != EOF){
        n = string2double(v);
        printf("%.3lf %.3lf\n", n, n*2);
    }



    return 0;
}