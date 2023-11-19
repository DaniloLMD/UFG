#include "conjunto.hpp"

struct conjunto{
    int* data;
    unsigned int cardinalidade;
};

/*====================== FUNCOES EXTRAS ==================*/

//ordena o conjunto C de maneira crescente(1) ou decrescente(0), em O(n)
void Counting_Sort(Conjunto C, int ordem){

    if(C->cardinalidade == 0) return;

    int* ordenado = (int*) malloc((C->cardinalidade) * sizeof(int));
    int* contador;
    int maior;

    for(int i = 0; i < C->cardinalidade; i++){
        if(i == 0) maior =  C->data[0];

        if(C->data[i] > maior) maior = C->data[i];
    }

    contador = (int*) malloc((maior+1) * sizeof(int));

    for(int i = 0; i <= maior; i++){
        contador[i] = 0;
    }
    
    for(int i = 0; i < C->cardinalidade; i++){
        contador[ C->data[i] ]++;
    }
    
    for(int i = 1; i <= maior; i++){
        contador[i] += contador[i-1];
    }
    
    for(int i = 0; i < C->cardinalidade; i++){
        ordenado[ contador[C->data[i]] - 1] = C->data[i];
        contador[C->data[i]]--;
    }

    if(ordem == 0){
        int t;
        for(int i = 0; i < C->cardinalidade / 2; i++){
            t = ordenado[i];
            ordenado[i] = ordenado[C->cardinalidade - 1 - i];
            ordenado[C->cardinalidade - 1 - i] = t;
        }
    }

    free(contador);
    free(C->data);
    C->data = ordenado;

}

//calcula base^expoente em O( logn )
int pot(int base, int expoente){
    if(expoente == 0) return 1;

    int p = pot(base, expoente >> 1);

    p *= p;
    if(expoente&1){
        p *= base;
    }

    return p;
}


/*=========================================================================*/

Conjunto Conjunto_new(void){
    Conjunto C;
    C = (Conjunto) malloc(1 * sizeof(conjunto));

    C->cardinalidade = 0;
    C->data = NULL;

    return C;
}

bool Conjunto_is_empty(Conjunto C){
    if(C->cardinalidade == 0) return true;
    return false;
}

bool Conjunto_push_back(Conjunto C, int valor){
    if(Conjunto_pertence(C, valor)) return false;   
    
    if(C->cardinalidade == max_cardinalidade) return false;

    C->data = (int*) realloc(C->data, (C->cardinalidade+1) * sizeof(int));

    if(C->data == NULL) return false;
    C->data[C->cardinalidade] = valor;
    C->cardinalidade++;

    return true;
}

bool Conjunto_remove(Conjunto C, int valor){
    for(int i = 0; i < C->cardinalidade; i++){
        if(C->data[i] == valor){
            for(int j = i; j < C->cardinalidade - 1; j++){
                C->data[j] =C->data[j+1];
            }
            C->data = (int*) realloc(C->data, (C->cardinalidade-1) * sizeof(int));
            C->cardinalidade--;
            return true;
        }
    }

    return false;
}

bool Conjunto_pertence(Conjunto C, int valor){

    if(C == NULL) return false;

    for(int i = 0; i < C->cardinalidade; i++){
        if(C->data[i] == valor) return true;
    }

    return false;
}

unsigned int Conjunto_size(Conjunto C){
    return C->cardinalidade;
}

unsigned int Conjunto_maiores(Conjunto C, int valor){
    unsigned int maiores = 0;

    for(int i = 0; i < C->cardinalidade; i++){
        if(C->data[i] > valor) maiores++;
    }

    return maiores;
}

unsigned int Conjunto_menores(Conjunto C, int valor){
    unsigned int menores = 0;

    for(int i = 0; i < C->cardinalidade; i++){
        if(C->data[i] < valor) menores++;
    }

    return menores;
}

bool Conjunto_compare(Conjunto c1, Conjunto c2){
    if(c1->cardinalidade != c2->cardinalidade) return false;

    for(int i = 0; i < c1->cardinalidade; i++){
        if(c1->data[i] != c2->data[i]){
            return false;
        }
    }

    return true;
}

bool Conjunto_subconjunto(Conjunto C1, Conjunto C2){
    for(int i = 0; i < C1->cardinalidade; i++){
        if(!Conjunto_pertence(C2, C1->data[i])) return false;
    }

    return true;
}

Conjunto Conjunto_complemento(Conjunto C1, Conjunto C2){
    Conjunto complemento = Conjunto_new();

    for(int i = 0; i < C2->cardinalidade; i++){
        if(!Conjunto_pertence(C1, C2->data[i])){
            Conjunto_push_back(complemento, C2->data[i]);
        }
    }

    return complemento;
}

Conjunto Conjunto_uniao(Conjunto C1, Conjunto C2){
    Conjunto uniao = Conjunto_new();

    for(int i = 0; i < C1->cardinalidade; i++){
        Conjunto_push_back(uniao, C1->data[i]);        
    }

    for(int i = 0; i < C2->cardinalidade; i++){
        if(!Conjunto_pertence(uniao, C2->data[i])){
            Conjunto_push_back(uniao, C2->data[i]);
        }

        if(uniao->cardinalidade > max_cardinalidade){
            Conjunto_delete(&uniao);
            return NULL;
        }
    }

    return uniao;   
}

Conjunto Conjunto_intersecao(Conjunto C1, Conjunto C2){
    Conjunto intersecao = Conjunto_new();

    for(int i = 0; i < C1->cardinalidade; i++){
        if(Conjunto_pertence(C2, C1->data[i])){
            Conjunto_push_back(intersecao, C1->data[i]);
        }
    }

    return intersecao;
}

Conjunto Conjunto_diferenca(Conjunto C1, Conjunto C2){
    Conjunto diferenca = Conjunto_new();

    for(int i = 0; i < C1->cardinalidade; i++){
        if(!Conjunto_pertence(C2, C1->data[i])){
            Conjunto_push_back(diferenca, C1->data[i]);
        }
    }

    return diferenca;
}

void Conjunto_mostra(Conjunto C, int ordem  ){
    Counting_Sort(C, ordem);
   
    printf("{{}");
    for(int i = 0; i < C->cardinalidade; i++){
        printf(", %d", C->data[i]);
    }
    printf("}");

    printf("\n");
}

bool Conjunto_delete(Conjunto* C){

    if(*C == NULL){
        return false;
    }
    if((*C)->data != NULL) free((*C)->data);
    
    free(*C);
    *C = NULL;
    return true;
}

bool Conjunto_copy(Conjunto C1, Conjunto* C2_ref){
    if(C1 == NULL) return false;

    if(*C2_ref == NULL){
        *C2_ref = Conjunto_new();
        if(*C2_ref == NULL) return false;
    }
    Conjunto C2 = *C2_ref;

    free(C2->data);
    C2->data = NULL;
    C2->cardinalidade = 0;
    
    int valor;

    for(int i = 0; i < C1-> cardinalidade; i++){
        valor = C1->data[i];
        Conjunto_push_back(C2, valor);
    }
    
    return true;
}



void Conjunto_partes(Conjunto C){
    int max, atual = 0, temp, i_final;
    max = pot(2, C->cardinalidade);

    while(atual < max){

        temp = atual;
        for(int i = 0; i < C->cardinalidade; i++){
            if(temp%2 == 1){
               i_final = i;
            }

            temp = temp >> 1;
        }

        temp = atual;
        printf("{");
        for(int i = 0; i < C->cardinalidade; i++){
            if(temp%2 == 1){
                printf("%d", C->data[i]);
                if(i < i_final  ) printf(", ");
            }

            temp = temp >> 1;
        }
        printf("}\n");

        atual++;
    }
}