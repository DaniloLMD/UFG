#include <stdio.h>

/*void botarUmFinal(char *p, int negativo){
    int c, qtd = 0;
    char v2[128];

    if(negativo){
        for(c = 1; p[c] != '\0'; c++) qtd++;
        for(c = qtd; c > 1; c--) p[qtd] = p[qtd-1];
        p[1] = '1';
    }
    else{
        for(c = 0; p[c] != '\0'; c++) qtd++;
        for(c = qtd; c > 0; c--) p[qtd] = p[qtd - 1];
        p[0] = '1';
    }
}*/

/**
* Converte a string str para o valor real correspondente.
* @param str string contendo um número real
* @return print do número inteiro correspondente
*/
void string2double(char * str ){
    char v[128];
    int posSomar[128];
    int c, qtd = 0,c2 = 0, res, p  = 0, negativo = 0;

    printf("%s ", str);
    if(str[0] == '-') negativo = 1;
    for(c = 0; c < 128; c++) v[c] = 0;
    for(c = 0; str[c] != '\0'; c++){
        qtd++;
    }
    
    for(c = qtd -1; c >= 0; c--){
        if(str[c] >= '0' && str[c] <= '9') res = (str[c] - '0') * 2 + '0';
        else res = str[c];
        if (res > '9'){
            res -= 10;
            posSomar[p] = c;
            p++;
        }
        v[c2] = res;
        c2++;
    }
    for(c = 0; c < p; c++){
        if(negativo) v[posSomar[c] - 1] += 1;
        else v[posSomar[c]] += 1;
    }

    qtd = 0;
    for(c = 0; v[c] != '\0'; c++) qtd++;
    for(c = qtd-1; c >= 0; c--) printf("%c", v[c]);
    printf("\n"); 
}
int main(){
    char v[128];

    while(scanf("%s", v) != EOF){
        string2double(v);
    }
    return 0;
}




