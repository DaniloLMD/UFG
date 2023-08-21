#include <stdio.h>
#include <stdlib.h>
 
typedef struct{
    double numerador;
    double denominador;
}fracao;
 
typedef char bool;
 
int main(){
    fracao *usuario;
    int testes, tamanho, c, c2 = 1, c3;
    bool teveEq;
 
    scanf("%d", &testes);    
    while(testes--){
        //alocando o vetor do usuario
        scanf("%d", &tamanho);
        usuario = (fracao*) malloc(tamanho * sizeof(fracao));
        //lendo as fracoes
        for(c = 0; c < tamanho; c++) scanf("%lf/%lf", &(usuario[c].numerador), &(usuario[c].denominador));
        
        //printando
        teveEq = 0;
        printf("Caso de teste %d\n", c2);
        c2++;
        
        for(c = 0; c < tamanho-1; c++){
            for(c3 = c + 1; c3 < tamanho; c3++){
                if(usuario[c].numerador / usuario[c].denominador == usuario[c3].numerador / usuario[c3].denominador){
                    teveEq = 1;
                    printf("%.0lf/%.0lf equivalente a %.0lf/%.0lf\n", usuario[c].numerador, usuario[c].denominador, usuario[c3].numerador, usuario[c3].denominador);
            }
            }
        }
        if(!teveEq) printf("Nao ha fracoes equivalentes na sequencia\n");
    }
    
    return 0;
}
