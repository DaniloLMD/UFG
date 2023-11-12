#include "datas.hpp"

//parei fazendo o Data_format, colocar potencia 10 pra pegar ao contrario
int main(){

    Data d = Data_new(23, 10, 2004);

    printf("d1 = %s\n", Data_format(d, "ddmmaaaa"));

    d = Data_soma_dias(d, 7980);

    printf("d2 = %s\n", Data_format(d, "ddmmaaaa"));

    d = Data_subtrai_dias(d, 7980);

    printf("d3 = %s\n", Data_format(d, "ddmmaaaa"));



    Data_delete(&d);
    return 0;
}