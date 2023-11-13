#ifndef __DATAS_HPP__
#define __DATAS_HPP__

#include <iostream>
#include <stdlib.h>
#include <cmath>

typedef struct data* Data;

//1  cria dinamicamente uma Data e a retorna
Data Data_new(unsigned int dia, unsigned int mes, unsigned int ano);

//2  faz uma copia da Data d e a retorna;
Data Data_copy(Data d);

//3 libera a memoria da Data e a seta para NULL
void Data_delete(Data* d);

//4 retorna uma Data que é "dias" posteriores à data d
Data Data_soma_dias(Data d, unsigned int dias);

//5 retorna uma Data que é "dias" anteriores à data d
Data Data_subtrai_dias(Data d, unsigned int dias); 

//6  atribui a data "d" o dia, mes e ano. Se nao for possivel, muda "d" para NULL
void Data_atribuir(Data* d, unsigned int dia, unsigned int mes, unsigned int ano);

//7 retorna o dia da data d
unsigned int Data_get_dia(Data d);

//8 retorna o mes da data d
unsigned int Data_get_mes(Data d);

//9 retorna o ano da data d
unsigned int Data_get_ano(Data d);

//10 retorna TRUE ou FALSE se o ano da data e bissexto
bool Data_bissex(Data d);

//11 retorna MENOR(-1) - mais recente, IGUAL(0) ou MAIOR(1) - mais antigo
int Data_compare(Data d1, Data d2);

//12 retorna o numero de dias entre as datas d1 e d2
unsigned int Data_numero_dias(Data d1, Data d2);

//13 retorna o numero de meses entre as datas d1 e d2
unsigned int Data_numero_meses(Data d1, Data d2);

//14 retorna o numero de anos entre as datas d1 e d2
unsigned int Data_numero_anos(Data d1, Data d2);

//15 retorna o dia da semana da data d. Domingo = 1, Sabado = 7
unsigned int Data_dia_semana(Data d);

//16 recebe um formato de data (ex ddmmaa) e retorna uma string formatada com a data dd/mm/aa
char* Data_format(Data d, char* formato);




#endif