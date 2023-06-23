#include <stdio.h>
#include <string.h>

#define qtdPaises 24

/**
* @param p string
* @return tamanho da string
*/
int tamanhoString(char *p){
    int t = 0, c;
    for(c = 0; p[c] != '\0'; c++) t++;
    return t;
}

/**
* @param s1 primeira string
* @param s2 segunda string
* @return quantidade de caracteres diferentes, -1 se o tamanho for diferente
*/
int comparaString(char *s1, char *s2){
    int diferenca = 0;
    int c, tamanho1, tamanho2;

    tamanho1 = tamanhoString(s1);
    tamanho2 = tamanhoString(s2);
    if(tamanho1 != tamanho2) return -1;

    for(c = 0; s1[c] != '\0'; c++){
        if(s1[c] != s2[c]) diferenca++;
    }

    return diferenca;
}

int main(){
    int c, achou = 0;
    char usuario[50];

    char paises[qtdPaises][50] = {
        "brasil", "alemanha", "austria", "coreia", "espanha", "grecia", "estados-unidos", "inglaterra", "australia", "portugal", "suecia", "turquia", "argentina", "chile", "mexico", "antardida", "canada", "irlanda", "belgica", "italia", "libia", "siria", "marrocos", "japao"
    };
    char frases[qtdPaises][100] = {
        "Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!", "Feliz Navidad!",
        "Kala Christougena!", "Merry Christmas!", "Merry Christmas!", "Merry Christmas!", "Feliz Natal!",
        "God Jul!", "Mutlu Noeller", "Feliz Navidad!", "Feliz Navidad!", "Feliz Navidad!", "Merry Christmas!", "Merry Christmas!", "Nollaig Shona Dhuit!", "Zalig Kerstfeest!", "Buon Natale!", "Buon Natale!", "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu!"
    };

    while(scanf("%s", usuario) != EOF){
        for(c = 0; c < qtdPaises; c++){
            if(comparaString(usuario, paises[c]) == 0){
                printf("%s\n", frases[c]);
                achou = 1;
                break;
            }
        }
        if(!achou) printf("-- NOT FOUND --\n");

        achou = 0;
    }

    return 0;
}