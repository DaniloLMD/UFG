#include <stdio.h>
 
int main(){
    int qtd, erros = 0, tamanho, i = 0, c;
    char irmao[6];
    char one[4] = "one";
    char two[4] = "two";
    char three[6] = "three";
 
 
    scanf("%d", &qtd);
 
    while(qtd--){
        erros = 0;
        scanf("%s", irmao);
        c = 0;
        i = 0;
        while(irmao[i] != '\0'){
            c++;
            i++;
        }
 
        if(c == 3){
            for(i = 0; i < 4; i++){
                if(irmao[i] != one[i]) erros++;
            }
            if(erros <= 1){
                printf("1\n");
            }
            erros = 0;
            for(i = 0; i < 4; i++){
                if(irmao[i] != two[i]) erros++;
            }           
            if(erros <= 1){
                printf("2\n");
            }
        }
        else if(c == 5){     
            for(i = 0; i < 6; i++){
                if(irmao[i] != three[i]) erros++;
            }
            if(erros <= 1){
                printf("3\n");
            }
        }
    }
 
    return 0;
}