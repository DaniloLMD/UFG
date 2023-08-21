#include <stdio.h>
#include <stdlib.h>
 
#define qtdPais 24
#define tamTexto 50
 
typedef char bool;
 
typedef struct{
    char texto[tamTexto];
}pais;
 
int str_len(char *s){
    int c;
    for(c = 0; s[c] != '\0'; c++);
    return c;
}
 
int str_comp(char *s1, char *s2){
    int c;
 
    if(str_len(s1) != str_len(s2)) return 0;
    for(c = 0; s1[c] != '\0'; c++){
        if(s2[c] != s1[c]) return 0;
    }
 
    return 1;
}
 
int main(){
    char paises[qtdPais][tamTexto] = {
        "brasil",
        "alemanha",
        "austria",
        "coreia",
        "espanha",
        "grecia Kala",
        "estados-unidos",
        "inglaterra",
        "australia",
        "portugal",
        "suecia",
        "turquia",
        "argentina",
        "chile",
        "mexico",
        "antardida",
        "canada",
        "irlanda",
        "belgica",
        "italia",
        "libia",
        "siria",
        "marrocos",
        "japao"
    };
    char frases[qtdPais][tamTexto] = {
        "Feliz Natal!",
        "Frohliche Weihnachten!",
        "Frohe Weihnacht!",
        "Chuk Sung Tan!",
        "Feliz Navidad!",
        "Christougena!",
        "Merry Christmas!",
        "Merry Christmas!",
        "Merry Christmas!",
        "Feliz Natal!",
        "God Jul!",
        "Mutlu Noeller",
        "Feliz Navidad!",
        "Feliz Navidad!",
        "Feliz Navidad!",
        "Merry Christmas!",
        "Merry Christmas!",
        "Nollaig Shona Dhuit!",
        "Zalig Kerstfeest!",
        "Buon Natale!",
        "Buon Natale!",
        "Milad Mubarak!",
        "Milad Mubarak!",
        "Merii Kurisumasu!"
    };
    int c, c2;
    bool achou;
    pais *v = NULL;
    for(c = 0; ;c++){
        achou = 0;
        v = realloc(v, c+1);
        if(scanf("%[^\n]%*c", v[c].texto) == EOF) break;
 
        for(c2 = 0; c2 < qtdPais; c2++){
            if( str_comp(paises[c2], v[c].texto) ){
                printf("%s\n", frases[c2]);
                achou = 1;
            }
        }
        if( !achou) printf("-- NOT FOUND --\n");
    }
    
    free(v);
    return 0;
}
 
 
 
 
 
 
/*
    mult = (ax - by) + (ay + bx)
    div = (a+bi)(x-yi)/x²+y²
*/
