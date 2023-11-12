#include "texto.hpp"
#include <vector>

struct Texto_{
    char* text;
    unsigned int size;
};

//1
Texto criarTexto(char* t){
    Texto new_texto = (Texto) malloc(1 * sizeof(struct Texto_));
    unsigned int size = 0;

    new_texto->text = t;
   
    for(size = 0; t[size] != '\0'; size++);
    new_texto->size = size;

    return new_texto;
};

void liberarTexto (Texto* t){
    if(*t != NULL){
        free(*t);
    }
    *t = NULL;
}

unsigned int tamanhoTexto (Texto t){
    return t->size;
}

char * obterTexto (Texto t){
    return t->text;
}

void mostrarTexto(Texto t, unsigned int colunas){
    int coluna_atual = 0;

    for(int i = 0; i < t->size; i++){
        if(coluna_atual == colunas){
            printf("\n");
            coluna_atual = 0;
        }
        printf("%c", t->text[i]);
        coluna_atual++;
    }
    printf("\n");
    
}

Texto copiarTexto(Texto t){
    Texto new_texto = criarTexto(t->text);

    return new_texto;
}

void substituirTexto(Texto t, char* alteracao){
    t->text = alteracao;
}

Texto concatenarTextos(Texto t1, Texto t2){
    Texto new_texto;

    new_texto = (Texto) malloc(1 * sizeof(struct Texto_));
    new_texto->size = t1->size + t2->size;
    new_texto->text = (char*) malloc((new_texto->size + 1) * sizeof(char));

    int index = 0;
    for(int i = 0; i < t1->size; i++){
        new_texto->text[index++] = t1->text[i];
    }
    for(int i = 0; i < t2->size; i++){
        new_texto->text[index++] = t2->text[i];
    }


    return new_texto;
}

char* obterSubtexto(Texto t, unsigned int inicio, unsigned int tamanho){
    if(tamanho == 0) return NULL;

    char* sub_texto = (char*) malloc((tamanho+1) * sizeof(char));

    inicio--;
    for(int i = 0; i < tamanho; i++){
        if(inicio == t->size) break;
        sub_texto[i] = t->text[inicio++];
    }

    sub_texto[tamanho] = '\0';
    return sub_texto;
}

unsigned int encontrarSubtexto (Texto t, char * subtexto, unsigned int ocorrencia){
    std::vector<int> z_function; 
    int corretos, index, tamanho_sub;

    for(tamanho_sub = 0; subtexto[tamanho_sub] != '\0'; tamanho_sub++);

    for(int i = 0; i < t->size; i++){
        corretos = 0;
        if(t->text[i] == subtexto[0]){
            index = 0;
            for(int i2 = i; t->text[i2] == subtexto[index] && i2 < t->size; i2++, index++){
                corretos++;
            }
        }
        z_function.push_back(corretos);
    } 
    
    corretos = 1;
    index = 0;
    for(int h: z_function){

        if(h >= tamanho_sub){
            if(corretos == ocorrencia) return index+1;
            corretos++;
        }

        index++;
    }

    return 0;
}

int compararTextos(Texto t1, Texto t2){
    if(t1->size < t2->size) return -1;
    if(t1->size > t2->size) return 1;


    return 0;
}