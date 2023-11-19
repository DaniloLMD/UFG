#ifndef __CONJUNTO_H__
#define __CONJUNTO_H__

#include <iostream>


#define max_cardinalidade 1e6
typedef struct conjunto* Conjunto;

//1 cria um conjunto, inicialmente vazio, e retorna se foi possivel ou nao a criacao
Conjunto Conjunto_new();

//2 verifica se o conjunto C e vazio
bool Conjunto_is_empty(Conjunto C);

//3 insere um elemento no conjunto. Se o elemento ja estiver presente ou der erro na insercao, retorna FALSE. Caso contrario retorna TRUE
bool Conjunto_push_back(Conjunto C, int valor);

//4 exclui o valor do conjunto C e retorna true ou false se o elemento nao estiver presente
bool Conjunto_remove(Conjunto C, int valor);

//5 retorna o tamanho do conjunto
unsigned int Conjunto_size(Conjunto C);

//6 retorna o numero de elementos do conjunto C maiores que o valor
unsigned int Conjunto_maiores(Conjunto C, int valor);

//7 retorna o numero de elementos do conjunto C menores que o valor
unsigned int Conjunto_menores(Conjunto C, int valor);

//8 verifica se o valor esta no conjunto C
bool Conjunto_pertence(Conjunto C, int valor);

//9 retorna se dois conjuntos sao identicos
bool Conjunto_compare(Conjunto C1, Conjunto C2);

//10 retorna se C1 e subconjunto de C2
bool Conjunto_subconjunto(Conjunto C1, Conjunto C2);

//11 retorna o complemento de C1 em relacao a C2 - elementos de C2 que nao pertencem a C1
Conjunto Conjunto_complemento(Conjunto C1, Conjunto C2);

//12 retorna a uniao de C1 e C2 
Conjunto Conjunto_uniao(Conjunto C1, Conjunto C2);

//13 retorna a intersecao de C1 e C2
Conjunto Conjunto_intersecao(Conjunto C1, Conjunto C2);

//14 retorna a diferenca de C1 e C2
Conjunto Conjunto_diferenca(Conjunto C1, Conjunto C2);

//15 Gera o conjunto das partes do conjunto C
void Conjunto_partes(Conjunto C);

//16 mostra os elementos do conjunto C em ordem crescente(1) ou decrescente(0)
void Conjunto_mostra(Conjunto C, int ordem = 1);

//17 copia os elementos de C1 para C2
bool Conjunto_copy(Conjunto C1, Conjunto* C2);


//18 deleta o conjunto C
bool Conjunto_delete(Conjunto* C);

#endif