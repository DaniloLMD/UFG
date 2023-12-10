#include "list.h"

int main(){

    List lista;
    List lista2;
    Lista_new(&lista);
    Lista_new(&lista2);

    Lista_push_front(lista, 105, 47);
    Lista_push_front(lista, 204, 52);

    Lista_push_ordered(lista, 5, 4);
    
    Lista_push_ordered(lista, 1, 5);
    
    Lista_push_ordered(lista, 2, 2);
    
    Lista_push_ordered(lista2, 3, 1);
    
    Lista_push_ordered(lista2, 4, 3);

    Lista_push_back(lista2, 37, 99);
    Lista_push_back(lista2, 48, 72);

    Lista_print(lista);
    Lista_print(lista2);
    Lista_concat(lista, lista2);

    Lista_delete(&lista2);

    Lista_print(lista);

    Lista_pop_back(lista);
    Lista_pop_back(lista);
    Lista_pop_front(lista);
    Lista_pop_key(lista, 52);

    Lista_print(lista);

    
    Lista_delete(&lista);

    return 0;
}

