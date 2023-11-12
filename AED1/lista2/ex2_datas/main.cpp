#include "datas.hpp"

//parei fazendo o Data_format, colocar potencia 10 pra pegar ao contrario
int main(){

    Data d = Data_new(28, 2, 1780);
    printf("Original: %s\n", Data_format(d, "ddmmaaaa"));


    
    d = Data_soma_dias(d, 1);
    printf("Somei 1: %s\n", Data_format(d, "ddmmaaaa"));

    d = Data_soma_dias(d, 15);
    printf("Somei 15: %s\n", Data_format(d, "ddmmaaaa"));


    d = Data_subtrai_dias(d, 16);
    printf("Subtrai 16: %s\n", Data_format(d, "ddmmaaaa"));


    Data_delete(&d);
    return 0;
}