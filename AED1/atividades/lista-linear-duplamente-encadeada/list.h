#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct list* List;
typedef struct no* Node;

typedef char bool;

#define true 1
#define false 0

//cria uma lista vazia e retorna true ou false
bool Lista_new(List* l_ref);
//apaga uma lista e retorna true ou false
bool Lista_delete(List* l_ref);

//insere um no no inicio da lista
bool Lista_push_front(List l, int valor, int chave);
//insere um no no final da lista
bool Lista_push_back(List l, int valor, int chave);
//insere um no de maneira ordenada na lista
bool Lista_push_ordered(List l, int valor, int chave);

//remove o primeiro elemento da lista
bool Lista_pop_front(List l);
//remove o ultimo elemento da lista
bool Lista_pop_back(List l);
//remove o elemento da lista com a chave informada
bool Lista_pop_key(List l, int key);

//printa uma lista
void Lista_print(List l);
//printa uma lista de tras pra frente
void Lista_reverse_print(List l);

//concatena a lista 2 na lista 1
bool Lista_concat(List l1, List l2);

#endif
