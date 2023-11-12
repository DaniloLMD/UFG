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

//6

//7

//8

//9

//10 retorna TRUE ou FALSE se o ano da data e bissexto
bool Data_bissex(Data d);

//11

//12

//13

//14

//15

//16 recebe um formato de data (ex ddmmaa) e retorna uma string formatada com a data dd/mm/aa
char* Data_format(Data d, char* formato);




#endif