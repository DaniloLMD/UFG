
#include "texto.hpp"

int main(){

    Texto t1, t2, t3;
    //f1
    printf("\nF1\n");
    printf("T1 e T2 criados\n");
    t1 = criarTexto("Danilo");
    t2 = criarTexto("Gustavo");

    
    //f3
    printf("\nF3\n");
    cout << "Tamanho de f1: " << tamanhoTexto(t1) << endl;

    cout << "Tamanho de f2: " << tamanhoTexto(t2) << endl;
    
    //f4
    printf("\nF4\n");
    cout << "Texto de t1: " << obterTexto(t1) << endl;
    cout << "Texto de t2: " << obterTexto(t2) << endl;
    
    //f5
    printf("\nF5\n");
    cout << "Mostrar t1 com 3 colunas:\n";
    mostrarTexto(t1, 3);
    //f6
    printf("\nF6\n");
    t3 = copiarTexto(t1);
    printf("T3 recebeu uma copia de T1.\n");
    

    //f7
    printf("\nF7\n");
    printf("Antes de substituir: %s\n", obterTexto(t1));
    substituirTexto(t1, "Novo Texto");
    printf("Apos substituir: %s\n", obterTexto(t1));

    //f8
    printf("\nF8\n");
    t1 = concatenarTextos(t3, t2);
    printf("T1 = T3 + T2 = %s\n", obterTexto(t1));

    //f9
    printf("\nF9\n");
    printf("Subtexto de F2 a partir do indice 4: %s\n", obterSubtexto(t2, 5, 500));

    //f10
    printf("\nF10\n");
    substituirTexto(t1, "ABCdefABdABCabcABCt");
    printf("texto = %s\n", obterTexto(t1));
    printf("indice em que \"ABC\" aparece pela segunda vez: %d\n", encontrarSubtexto(t1, "ABC", 2));
    //f11
    printf("\nF11\n");
    printf(
            "T1 = %s\n"
            "T2 = %s\n", 
            obterTexto(t1), obterTexto(t2)
    );
    switch(compararTextos(t1, t2)){
        case -1:
            printf("T1 < T2\n");
        break;

        case 0:
            printf("T1 == T2\n");
        break;

        case 1:
            printf("T1 > T2\n");
        break;
    }

    //f2
    printf("\nF2\n");
    printf("t1, t2 e t3 liberados\n");
    liberarTexto(&t1);
    liberarTexto(&t2);
    liberarTexto(&t3);
    printf(
        "t1 = %p\n"
        "t2 = %p\n"
        "t3 = %p\n", t1, t2, t3
    );

    return 0;
}