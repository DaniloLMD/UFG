#include <stdio.h>

/**
* Função que remove vogais e calcula a quantidade de vogais removidas
* @param str string de entrada
* @param vogais vetor de 5 posições que contabiliza a quantidade
* de vogais removidas
* @return A função atualiza os vetores str e vogais.
*/
void remove_vogais( char * str, int * vogais ){
    int c, c2, c3 = 0, vogal = 0;
    char t[256];
    char v[10] = "aeiouAEIOU";

    for(c = 0; str[c] != '\0'; c++){
        if(str[c] >= 'a' && str[c] <= 'z' || str[c] >= 'A' && str[c] <= 'Z'){
            for(c2 = 0; c2 < 10; c2++){
                if(str[c] == v[c2]){
                    vogal = 1;
                    if(c2 >= 5) vogais[c2-5]++;
                    else vogais[c2]++;
                }
            }
        }
        if(!vogal || str[c] == ' '){
            t[c3] = str[c];
            c3++;
        }
        vogal = 0;
    
    }
    for(c = 0; str[c] != '\0'; c++) str[c] = '\0';
    for(c = 0; t[c] != '\0'; c++) str[c] = t[c];
}

int main(){
    char string[256];
    int vog[5] = {0, 0, 0, 0, 0}, x;

    scanf("%[^\n]%*c", string);
    remove_vogais(string, vog);

    printf("%s\n", string);
    printf(
        "a: %d\n"
        "e: %d\n"
        "i: %d\n"
        "o: %d\n"
        "u: %d\n", vog[0], vog[1], vog[2], vog[3], vog[4]
    );
    return 0;
}