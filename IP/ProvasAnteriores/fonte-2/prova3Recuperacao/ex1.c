                            //*-*-*-  ALITERAÇÃO  -*-*-*//
#include <stdio.h>

int main(){
    char texto[100], caracter, caracter2;
    int c, alit;

    while(scanf("%[^\n]%*c", texto) != EOF){
        alit = 0;
        for(c = 0; texto[c] != '\0'; c++) if(texto[c] >= 'A' && texto[c] <= 'Z') texto[c] += 'a' - 'A';
        caracter2 = 'A';
        caracter = texto[0];
        

        for(c = 1; texto[c] != '\0'; c++){
            if(texto[c-1] == ' ') caracter = texto[c];

            else if(texto[c] == ' '){
                if(caracter == texto[c+1] && caracter != caracter2){
                    alit++;
                    caracter2 = caracter;
                }
                else if(caracter != caracter2) caracter2 = 'A';
            }

        }
        printf("%d\n", alit);

    }

    return 0;
}