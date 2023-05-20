#include <stdio.h>

void converteEmNotasMoedas(int v, int *cem, int *cinquenta, int *dez, int *um){
    *cem = 0;
    *cinquenta = 0;
    *dez = 0;
    *um = 0;
    while(v){
        while(v >= 100){
            *cem += 1;
            v = v - 100;
        }
        while(v >= 50){
            *cinquenta += 1;
            v -= 50;
        }
        while(v >= 10){
            *dez += 1;
            v -= 10;
        }while(v){
            *um += 1;
            v--; 
        }
        
    }

}


int main(){
    int valor;
    int qtd100;
    int qtd50;
    int qtd10;
    int qtd1;

    scanf("%d", &valor);
    converteEmNotasMoedas(valor, &qtd100, &qtd50, &qtd10, &qtd1);
    printf("NOTAS DE 100 = %d\n", qtd100);
    printf("NOTAS DE 50 = %d\n", qtd50);
    printf("NOTAS DE 10 = %d\n", qtd10);
    printf("MOEDAS DE 1 = %d\n", qtd1);
    return 0;
}