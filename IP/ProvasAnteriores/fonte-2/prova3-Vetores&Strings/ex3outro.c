#include <stdio.h>

void botarUmFinal(char *p, int negativo){
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
}

/**
* Converte a string str para o valor real correspondente.
* @param str string contendo um número real
* @return print do número inteiro correspondente
*/
void string2double(char * str ){
    char v[128];
    int c, qtd = 0, c2 = 0, res, passar  = 0;

    for(c = 0; str[c] != '\0'; c++){
        qtd++;
    }
    
    for(c = qtd -1; c >= 0; c--){
        printf("String: %s\n", str);
        printf("Analisando o caracter: %c\n", str[c]);
        if(str[c] >= '0' && str[c] <= '9') res = (str[c] - '0') * 2 + '0';
        else res = str[c];
        printf("Resultado(res): %c\n", str[c]);

        if (res > '9'){
            res -= 10;
            if(str[c-1] == '.') str[c-2] += 1;
            else if(c-1 == 0 && str[0] == '-') botarUmFinal(v, 1);
            else if(c == 0) botarUmFinal(v, 0);
            else str[c-1] += 1;
        }
        printf("Vou colocar atual: %c\n", res);
        v[c] = res + passar;
        c2++;
        printf("String formando: %s\n\n\n", v);
    }
    printf("%s\n", v);
}
int main(){
    char v[128];

    while(scanf("%s", v) != EOF){
        string2double(v);
    }
    return 0;
}




