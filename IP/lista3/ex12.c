#include <stdio.h>
#include <stdlib.h>


char* func(int n, const char *s){
    int cont;
    char *prefixo = (char*) malloc(n * sizeof(char));
    for(cont = 0; cont < n; cont++){
        prefixo[cont] = s[cont];
    }

    return prefixo;
} 

int main(){
    int qtd, num, c, tamanhoTexto;
    char texto[499], *textoNovo;

    scanf("%d", &qtd);

    while(qtd--){
        scanf("%d%*c %[^\n]%*c", &num, texto);
        tamanhoTexto = 0;
        for(c = 0; texto[c] != '\0'; c++){
            tamanhoTexto++;
        }
        if(num > tamanhoTexto) num = tamanhoTexto;

        textoNovo = func(num, texto);
        if(textoNovo != NULL){
            for(c = 0; c < num; c++){
                printf("%c", textoNovo[c]);
            }
        }
        printf("\n");
        free(textoNovo);
    }

    return 0;
}