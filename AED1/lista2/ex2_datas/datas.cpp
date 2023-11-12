#include "datas.hpp"

struct data{
    unsigned int dia, mes, ano;  
};

int meses[12] = {31, 28, 31, 30, 31, 30, 31 , 31, 30, 31, 30, 31};

Data Data_new(unsigned int dia, unsigned int mes, unsigned int ano){
    Data new_data = (Data) malloc(1 * sizeof(data));
    new_data->dia = dia;
    new_data->mes = mes;
    new_data->ano = ano;

    return new_data;
}

Data Data_copy(Data d){
    Data new_data;
    new_data = Data_new(d->dia, d->mes, d->ano);
    return new_data;
}

void Data_delete(Data* d){
    free(*d);
    *d = NULL;
}

Data Data_soma_dias(Data d, unsigned int dias){
    Data new_data = Data_new(d->dia, d->mes, d->ano);

    while(dias--){
        new_data->dia++;

        if(Data_bissex(new_data)){
                meses[1] = 29;
        }
        else{
            meses[1] = 28;
        }
        
        if(new_data->dia > meses[new_data->mes - 1]){
            new_data->dia = 1;
            new_data->mes++;
        }

        if(new_data->mes > 12){
            new_data->mes = 1;
            new_data->ano++;
        }
    }

    return new_data;
}

Data Data_subtrai_dias(Data d, unsigned int dias){
    Data new_data = Data_new(d->dia, d->mes, d->ano);

    while(dias--){
        new_data->dia--;
        if(new_data->dia == 0){
            new_data->mes--;

            if(new_data->mes == 0){
                new_data->mes = 12;
                new_data->ano--;
            }
        
            if(Data_bissex(new_data)){
                meses[1] = 29;
            }
            else{
                meses[1] = 28;
            }


            new_data->dia = meses[new_data->mes-1];
        }

        
    }

    return new_data;
}

int pot(int b, int e){
    if(e == 0) return 1;
    return b * pot(b, e-1);
}

char* Data_format(Data d, char* formato){
    char *str = (char*) malloc(11 * sizeof(char));
    char carac;
    int pd, pm, pa, index = 0;
    pd = pm = 1;
    pa = 3;

    for(int i = 0; i < 8; i++){
        
        if(pd < -1 || pm < -1 || pa < -1){
            printf("FORMATO INVALIDO!\n");
            return NULL;
        }
        

        if(i != 0){
            if(formato[i] != formato[i-1]){
                str[index++] = '/';
            }
        }

        if(formato[i] == 'd'){
                carac = (d->dia / pot(10, pd--)) % 10;
        }
        else if(formato[i] == 'm'){
            carac = (d->mes / pot(10, pm--)) % 10;
        }
        else if(formato[i] == 'a'){
            carac = (d->ano / pot(10, pa--)) % 10;
        }
        carac = carac + '0';
        str[index++] = carac;
    }

    str[10] = '\0';
    return str;
}

bool Data_bissex(Data d){

    if((d->ano % 4 == 0 && d->ano % 100 != 0) || d->ano % 400 == 0) return true;

    return false;
}

