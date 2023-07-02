#include <stdio.h>
 
int main(){
    int testes, caso = 1, c, c2, teveEq;
    int qtdFracoes;
    double numerador, denominador;
    double matriz[50][2], resultado, resultado2;
    
    scanf("%d", &testes);
    
    while(testes--){
        teveEq = 0;
        scanf("%d", &qtdFracoes);
        for(c = 0; c < qtdFracoes; c++){
            scanf("%lf/%lf", &matriz[c][0], &matriz[c][1]);
        }
    
        
        printf("Caso de teste %d\n", caso);
        for(c = 0; c < qtdFracoes; c++){
            resultado = matriz[c][0] / matriz[c][1];
            for(c2 = c + 1; c2 < qtdFracoes; c2++){
                resultado2 = matriz[c2][0] / matriz[c2][1];
                if(resultado == resultado2){
                    printf("%.0lf/%.0lf equivalente a %.0lf/%.0lf\n", matriz[c][0], matriz[c][1], matriz[c2][0], matriz[c2][1]);
                    teveEq = 1;
                }
            }
        }
        if( !teveEq) printf("Nao ha fracoes equivalentes na sequencia\n");
 
        caso++;
    }
 
 
    return 0;
}
