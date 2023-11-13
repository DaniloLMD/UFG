#include "datas.hpp"

//parei fazendo o Data_format, colocar potencia 10 pra pegar ao contrario
int main(){
    Data d1, d2, d3;

    //f1
    printf("Data d1 e d2 criadas\n");
    d1 = Data_new(29, 10, 2004);
    d2 = Data_new(22, 4, 1500);

    //f2
    printf("D3 recebe uma copia de D1\n");
    d3 = Data_copy(d1);

    //f4
    printf("D3 recebe uma data 400 dias posteriores à D2\n");
    d3 = Data_soma_dias(d2, 400);

    //f5
    printf("D3 recebe uma data 400 dias anteriores à D2\n");
    d3 = Data_subtrai_dias(d2, 400);

    //f6
    printf("Data de D3 atribuida para 01/01/2000\n");
    Data_atribuir(&d3, 1, 1, 2000);

    //f7
    printf("Dia de d1 = %d\n", Data_get_dia(d1));

    //f8
    printf("Mes de d1 = %d\n", Data_get_mes(d1));

    //f9
    printf("Ano de d1 = %d\n", Data_get_ano(d1));

    //f10
    printf("D1 bissexto: %d\n", Data_bissex(d1));

    //f11
    printf("Comparacao de D1 e D2 : %d\n", Data_compare(d1, d2));

    //f12
    printf("Numero de dias entre d1 e d2: %d\n", Data_numero_dias(d1, d2));

    //f13
    printf("Numero de meses entre d1 e d2: %d\n", Data_numero_meses(d1, d2));

    //f14
    printf("Numero de anos entre d1 e d2: %d\n", Data_numero_anos(d1, d2));
    

    //f15
    printf("Dia da semana de D1: %d\n", Data_dia_semana(d1));

    //f16
    printf("D1 no formato ddmmaaaa: %s\n", Data_format(d1, "ddmmaaaa"));
    printf("D2 no formato ddmmaaaa: %s\n", Data_format(d2, "ddmmaaaa"));

    //f3
    printf("D1, D2 e D3 deletados\n");
    Data_delete(&d1);
    Data_delete(&d2);
    Data_delete(&d3);

    return 0;
}