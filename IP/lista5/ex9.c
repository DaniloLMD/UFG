#include <stdio.h>
#include <stdlib.h>
 
typedef struct{
    int a, b;
} fracao;
 
int main(){
    fracao *v;
    int tamanho, qtd, n1, n2, testes = 0;
    char separador, achouEq;
    
    scanf("%d", &qtd);
    
    while(qtd--){
    
        tamanho = 0;
        testes++;
        achouEq = 0;
        
        while(1){
            
            scanf("%d/%d%c", &n1, &n2, &separador);
            tamanho++;
            v = (fracao*) realloc(v, tamanho * sizeof(fracao));
            v[tamanho-1].a = n1;
            v[tamanho-1].b = n2;
            if(separador == '\n') break; 
        }
        
        printf("Caso de teste %d\n", testes);
        for(n1 = 0; n1 < tamanho; n1++){
            for(n2 = n1 + 1; n2 < tamanho; n2++){
                if( (double) v[n1].a / v[n1].b == (double) v[n2].a / v[n2].b){
                    achouEq = 1;
                    printf("%d/%d equivalente a %d/%d\n", v[n1].a, v[n1].b, v[n2].a, v[n2].b);
                }
            }
        }
        
        if(!achouEq) printf("Nao ha fracoes equivalentes na sequencia\n");
        
    }
    
    
    return 0;
}
