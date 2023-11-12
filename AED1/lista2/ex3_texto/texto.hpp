#ifndef T_HPP
#define T_HPP

#include <iostream>
using namespace std;
typedef struct Texto_* Texto;

//1 cria e retorna um Texto recebendo um texto t
Texto criarTexto(char* t);

//2 libera a memoria do ponteiro e seta para NULL
void liberarTexto (Texto* t);

//3 retorna o tamanho do texto de t
unsigned int tamanhoTexto (Texto t);

//4 retorna o texto de t
char * obterTexto (Texto t);

//5 printa o texto de t
void mostrarTexto(Texto t, unsigned int colunas);

//6 cria e retorna uma copia de t
Texto copiarTexto(Texto t);

//7 troca o texto de t pela alteracao
void substituirTexto(Texto t, char* alteracao);

//8 cria e retorna um texto resultado da concatenacao de t1 e t2
Texto concatenarTextos(Texto t1, Texto t2);

//9 retorna um subtexto de t a partir do indice inicio
char* obterSubtexto(Texto t, unsigned int inicio, unsigned int tamanho);

//10 procura subtextos e retorna o indice do inicio da ocorrencia, se nao encontrar retorna 0 (usa Z-Function)
unsigned int encontrarSubtexto (Texto t, char * subtexto, unsigned int ocorrencia);

//11 compara o tamanho de dois textos e retorna -1(MENOR) 0 (IGUAL) ou 1(MAIOR)
int compararTextos(Texto t1, Texto t2);

#endif