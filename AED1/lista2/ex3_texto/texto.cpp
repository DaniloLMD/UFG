#include "texto.hpp"

struct Texto_{
    char* text;
    unsigned int size;

    Texto criarTexto(char* t);



    unsigned int get_size(Texto T);
};

//---------------- FUNCOES EXTRAS ---------------------
unsigned int get_size(Texto T){
    return T->size;
} 

//1
Texto criarTexto(char* t){
    Texto new_texto = (Texto) malloc(1 * sizeof(struct Texto_));
    unsigned int size;

    new_texto->text = t;
   
    for(size = 0; t[size] != '\0'; size++);
    new_texto->size = size;

    return new_texto;
};


void printa(Texto t){
    printf("texto P = %p\n", t->text);
    printf("texto = %s\n", t->text);
    printf("tamanho = %d\n", t->size);
}