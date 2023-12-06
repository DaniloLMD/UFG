#include "complex.hpp"

int main(){
    Conjunto a = NULL;
    Conjunto b = NULL;

    //f1
    Conjunto_new(&a);
    Conjunto_new(&b);

    //f2
    std::cout << "a vazio: " <<  Conjunto_is_empty(a) << "\n";
    
    //f3
    Conjunto_insert(a, 1, 2);
    Conjunto_insert(a, 5, 3);
    Conjunto_insert(a, 1, 2);

    Conjunto_insert(b, 5, 3);
    Conjunto_insert(b, 1, 2);
    Conjunto_insert(b, 1, 2);
    Conjunto_insert(b, 57, 102);
    
    //f4
    Conjunto_remove(b, 5, 3);
    Conjunto_remove(b, 5, 99);
    
    //f5
    std::cout << "Cardinalidade de a: " << Conjunto_size(a) << "\n";

    //f6
    std::cout << "5 + 3i pertence a b: " << Conjunto_pertence(b, 5, 3) << "\n";

    //f7
    std::cout << "a e b iguais: " << Conjunto_compare(a, b) << "\n";

    //f8
    std::cout << "b subconjunto de a: " << Conjunto_subconjunto(b, a) << "\n";

    //f9
    Conjunto comp = Conjunto_complemento(a, b);

    //f10
    Conjunto uniao = Conjunto_uniao(a, b);
    
    //f11
    Conjunto intersec = Conjunto_intersecao(a, b);

    //f12
   Conjunto diferenca = Conjunto_diferenca(a, b);

   //f13
    printf("a = ");Conjunto_mostra(a);
    printf("b = ");Conjunto_mostra(b);
    printf("comp = ");Conjunto_mostra(comp);
    printf("uniao = ");Conjunto_mostra(uniao);
    printf("intersec = ");Conjunto_mostra(intersec);
    printf("diferenca = ");Conjunto_mostra(diferenca);
    
    //f14
    Conjunto_copy(&a, b);


    //f15
    Conjunto_delete(&a);
    Conjunto_delete(&b);
    Conjunto_delete(&comp);
    Conjunto_delete(&uniao);
    Conjunto_delete(&intersec);
    Conjunto_delete(&diferenca);
    
    return 0;
}