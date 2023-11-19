#include "conjunto.hpp"

int main(){
    //f1
    Conjunto c = Conjunto_new();
    Conjunto c2 = Conjunto_new();
    Conjunto comp = Conjunto_new();
    Conjunto uniao = Conjunto_new();
    Conjunto intersec = Conjunto_new();
    Conjunto diferenca = Conjunto_new();


    //f2
    printf("C e vazio ? %d\n", Conjunto_is_empty(c));

    //f3
    Conjunto_push_back(c, 1);
    Conjunto_push_back(c, 2);
    Conjunto_push_back(c, 3);
    Conjunto_push_back(c, 4);
    Conjunto_push_back(c, 5);

    Conjunto_push_back(c2, 1);
    Conjunto_push_back(c2, 3);


    //f4
    Conjunto_remove(c, 5);
    Conjunto_remove(c2, 30);

    //f5
    printf("tamanho de C: %d\n", Conjunto_size(c));
    printf("tamanho de C2: %d\n", Conjunto_size(c2));

    //f6
    printf("Numero de elementos maiores que 3: %d\n", Conjunto_maiores(c, 3));

    //f7
    printf("Numero de elementos menores que 3: %d\n", Conjunto_menores(c, 3));

    //f8
    printf("5 pertence a C ? %d\n", Conjunto_pertence(c, 5));

    //f9
    printf("C e C2 sao identicos? %d\n", Conjunto_compare(c, c2));

    //f10
    printf("C2 e subconjunto de C ? %d\n", Conjunto_subconjunto(c2, c));

    //f11
    comp = Conjunto_complemento(c, c2);

    //f12
    uniao = Conjunto_uniao(c, c2);

    //f13
    intersec = Conjunto_intersecao(c, c2);

    //f14
    diferenca = Conjunto_diferenca(c, c2);

    //f15
    printf("C = "); Conjunto_mostra(c);
    printf("C2 = "); Conjunto_mostra(c2, 0);
    printf("Complemento = "); Conjunto_mostra(comp);
    printf("Uniao = "); Conjunto_mostra(uniao, 0);
    printf("Intersecao = "); Conjunto_mostra(intersec, 0);
    printf("Diferenca = "); Conjunto_mostra(diferenca);

    //f16
    printf("Conjunto das partes de C:\n");
    Conjunto_partes(c);

    //f17
    Conjunto_copy(c, &c2);

    //f18
    Conjunto_delete(&c);
    Conjunto_delete(&c2);
    Conjunto_delete(&comp);
    Conjunto_delete(&intersec);
    Conjunto_delete(&uniao);
    Conjunto_delete(&diferenca);

    return 0;
}