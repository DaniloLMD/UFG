#include "complex.hpp"

typedef struct complex* Complex;

//a = parte real ; b = parte imaginaria
struct complex{
    double a, b;
};

struct conjunto{
    Complex data;
    unsigned int size;
    unsigned int capacity;
};


/*======== FUNCOES EXTRAS ==========  */

bool Conjunto_realocar(Conjunto C){

    if(C == NULL) return false;
    
    if(C->capacity == 0) C->capacity = 100;
    else C->capacity = C->capacity * 2;
    
    C->data = (Complex) realloc(C->data, C->capacity * sizeof(complex));

    if(C->data == NULL) return false;

    return true;
}

/*====================================*/
bool Conjunto_new(Conjunto* C){
    Conjunto new_conjunto = (Conjunto) malloc(1 * sizeof(conjunto));
    if(new_conjunto == NULL) return false;

    Conjunto_delete(C);

    new_conjunto->data = NULL;
    new_conjunto->size = 0;
    new_conjunto->capacity = 0;
    *C = new_conjunto;

   
    return true;
}

bool Conjunto_delete(Conjunto* C){
    if(*C == NULL) return false;

    if((*C)->data != NULL) free((*C)->data);
    free(*C);
    *C = NULL;

    return true;
}

bool Conjunto_is_empty(Conjunto C){
    if(C->size == 0) return true;
    return false;
}

bool Conjunto_insert(Conjunto C, double a, double b){

    if(C == NULL) return false;
    
    complex N;
    N.a = a;
    N.b = b;

    for(int i = 0; i < C->size; i++){
        if(N.a == C->data[i].a && N.b == C->data[i].b) return false;
    }   

    if(C->size == C->capacity){
        Conjunto_realocar(C);
    }

    C->data[C->size] = N;
    C->size++;
   
    return true;
}

bool Conjunto_remove(Conjunto C, double a, double b){
    for(int i = 0; i < C->size; i++){
        if(C->data[i].a == a && C->data[i].b == b){
            for(int j = i; j < C->size - 1; j++){
                C->data[j] = C->data[j+1];
            }

            C->size--;
            return true;
        }
    }

    return false;
}

unsigned int Conjunto_size(Conjunto C){
    return C->size;
}

bool Conjunto_pertence(Conjunto C, double a, double b){

    for(int i = 0; i < C->size; i++){
        if(C->data[i].a == a && C->data[i].b == b) return true;
    }
    return false;
}

bool Conjunto_compare(Conjunto C1, Conjunto C2){

    if(C1->size != C2->size) return false;
   
    bool achou;
    for(int i = 0; i < C1->size; i++){
        achou = false;
        for(int j = 0; j < C2->size; j++){
            if(C1->data[i].a == C2->data[j].a && C1->data[i].b == C2->data[j].b){
                achou = true;
                break;
            } 
        }

        if(!achou) return false;
    }

    return true;
}

bool Conjunto_subconjunto(Conjunto C1, Conjunto C2){
    if(Conjunto_size(C1) > Conjunto_size(C2)) return false;

    for(int i = 0; i < C1->size; i++){
        if(!Conjunto_pertence(C2, C1->data[i].a, C1->data[i].b)){
            return false;
        }
    }   
    return true;
}

Conjunto Conjunto_complemento(Conjunto C1, Conjunto C2){
    Conjunto new_conjunto = NULL;
    Conjunto_new(&new_conjunto);

    for(unsigned int i = 0; i < C2->size; i++){
        if(!Conjunto_pertence(C1, C2->data[i].a, C2->data[i].b)){
            Conjunto_insert(new_conjunto, C2->data[i].a, C2->data[i].b);
        }
    }

    return new_conjunto;
}

Conjunto Conjunto_uniao(Conjunto C1, Conjunto C2){
    Conjunto new_conjunto = NULL;
    Conjunto_new(&new_conjunto);

    for(unsigned int i = 0; i < C1->size; i++){
        Conjunto_insert(new_conjunto, C1->data[i].a, C1->data[i].b);
    }

    for(unsigned int i = 0; i < C2->size; i++){
        if(!Conjunto_pertence(new_conjunto, C2->data[i].a, C2->data[i].b)){
            Conjunto_insert(new_conjunto, C2->data[i].a, C2->data[i].b);
        }
    }

    return new_conjunto;

}

Conjunto Conjunto_intersecao(Conjunto C1, Conjunto C2){
    Conjunto new_conjunto = NULL;
    Conjunto_new(&new_conjunto);

    for(unsigned int i = 0; i < C2->size; i++){
        if(Conjunto_pertence(C1, C2->data[i].a, C2->data[i].b)){
            Conjunto_insert(new_conjunto, C2->data[i].a, C2->data[i].b);
        }
    }

    return new_conjunto;
}

Conjunto Conjunto_diferenca(Conjunto C1, Conjunto C2){
    Conjunto new_conjunto = NULL;
    Conjunto_new(&new_conjunto);

    for(unsigned int i = 0; i < C1->size; i++){
        if(!Conjunto_pertence(C2, C1->data[i].a, C1->data[i].b)){
            Conjunto_insert(new_conjunto, C1->data[i].a, C1->data[i].b);
        }
    }

    return new_conjunto;
}

bool Conjunto_copy(Conjunto* C1, Conjunto C2){
    if(C2 == NULL) return false;

    Conjunto_delete(C1);
    Conjunto_new(C1);
    for(unsigned int i = 0; i < C2->size; i++){
        Conjunto_insert(*C1, C2->data[i].a, C2->data[i].b);
    }

    return true;    
}

void Conjunto_mostra(Conjunto C){
    if(C == NULL) return;
    printf("{");

    for(unsigned int i = 0; i < C->size; i++){
        printf("%.2lf + %.2lfi", C->data[i].a, C->data[i].b);
        if(i+1 != C->size) printf(", ");
    }

    printf("}\n");
}