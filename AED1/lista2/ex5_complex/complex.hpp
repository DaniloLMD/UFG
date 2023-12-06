#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>

typedef struct conjunto* Conjunto;
//1 cria um conjunto vazio e retorna SUCESSO ou FALHA
bool Conjunto_new(Conjunto* C);

//2 verifica se um conjunto e vazio e retorna TRUE ou FALSE
bool Conjunto_is_empty(Conjunto C);

//3 insere o numero N = a + bi no conjunto e retorna SUCESSO ou FALHA
bool Conjunto_insert(Conjunto C, double a, double b);

//4 exclui o elemento N = a + bi no conjunto e retorna SUCESSO ou FALHA
bool Conjunto_remove(Conjunto C, double a, double b);

//5 retorna a cardinalidade do conjunto C
unsigned int Conjunto_size(Conjunto C);

//6 retorna se o elemento pertence ou nao ao conjunto C
bool Conjunto_pertence(Conjunto C, double a, double b);

//7 retorna se os conjuntos C1 e C2 sao identicos
bool Conjunto_compare(Conjunto C1, Conjunto C2);

//8 verifica se C1 é subconjunto de C2
bool Conjunto_subconjunto(Conjunto C1, Conjunto C2);

//9 retorna o complemento de C1 em relacao a C2 (elementos de C2 que nao pertencem a C1)
Conjunto Conjunto_complemento(Conjunto C1, Conjunto C2);

//10 retorna a uniao de C1 e C2
Conjunto Conjunto_uniao(Conjunto C1, Conjunto C2);

//11 retorna a intersecao de C1 e C2
Conjunto Conjunto_intersecao(Conjunto C1, Conjunto C2);


//12 retorna a diferenca de C1 e C2
Conjunto Conjunto_diferenca(Conjunto C1, Conjunto C2);

//13 mostra os elementos presentes no conjunto C
void Conjunto_mostra(Conjunto C);


//14 copia um conjunto de C1 para C2 e retorna SUCESSO ou FALHA
bool Conjunto_copy(Conjunto* C1, Conjunto C2);

//15 destroi um conjunto e retorna SUCESSO ou FALHA
bool Conjunto_delete(Conjunto* C);

#endif