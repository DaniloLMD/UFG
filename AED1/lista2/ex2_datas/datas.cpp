#include "datas.hpp"

struct data{
    unsigned int dia, mes, ano;  
};

int meses[12] = {31, 28, 31, 30, 31, 30, 31 , 31, 30, 31, 30, 31};

//===================== FUNCOES AUXILIARES ===========

long long int pot(int base, int exp){
    if(exp == 0) return 1;  
    return base * pot(base, exp-1);
}

//============================================================


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
    if(*d != NULL){
        free(*d);
        *d = NULL;
    }
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

char* Data_format(Data d, const char* formato){
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

void Data_atribuir(Data* d, unsigned int dia, unsigned int mes, unsigned int ano){
    if(*d != NULL){
        (*d)->dia = dia;
        (*d)->mes = mes;
        (*d)->ano = ano;
    }
}

unsigned int Data_get_dia(Data d){
    return d->dia;
}
unsigned int Data_get_mes(Data d){
    return d->mes;
}
unsigned int Data_get_ano(Data d){
    return d->ano;
}

int Data_compare(Data d1, Data d2){
    if(d1->ano > d2->ano) return -1;
    if(d1->ano < d2->ano) return 1;

    if(d1->mes > d2->mes) return -1;
    if(d1->mes < d2->mes) return 1;

    if(d1->dia > d2->dia) return -1;
    if(d1->dia < d2->dia) return 1;


    return 0;
}

unsigned int Data_numero_dias(Data d1_ref, Data d2_ref){
    
    Data d1 = Data_copy(d1_ref);
    Data d2 = Data_copy(d2_ref);

    if(Data_compare(d1, d2) == -1){
        Data t = d1;
        d1 = d2;
        d2 = t;
    }

    unsigned int dias = 0;

    while(Data_compare(d1, d2) != 0){
        d1 = Data_soma_dias(d1, 1);
        dias++;
    }

    Data_delete(&d1);
    Data_delete(&d2);
    return dias;
}

unsigned int Data_numero_meses(Data d1_ref, Data d2_ref){
    
    Data d1 = Data_copy(d1_ref);
    Data d2 = Data_copy(d2_ref);

    if(Data_compare(d1, d2) == -1){
        Data t = d1;
        d1 = d2;
        d2 = t;
    }

    unsigned int meses = 0;

    while(1){
        if(d1->mes == d2->mes && d1->ano == d2->ano) break;
        d1->mes++;
        if(d1->mes > 12){
            d1->mes = 1;
            d1->ano++;
        }
        meses++;
    }

    Data_delete(&d1);
    Data_delete(&d2);
    return meses;
}

unsigned int Data_numero_anos(Data d1_ref, Data d2_ref){
    
    Data d1 = Data_copy(d1_ref);
    Data d2 = Data_copy(d2_ref);
    if(Data_compare(d1, d2) == -1){
        Data t = d1;
        d1 = d2;
        d2 = t;
    }

    unsigned int anos = d2->ano - d1->ano;
    Data_delete(&d1);
    Data_delete(&d2);
    return anos;
}

unsigned int Data_dia_semana(Data d){
    unsigned int resultado;
    unsigned int mes = d->mes;
    unsigned int ano_a = d->ano % 100;
    unsigned int ano_c = d->ano / 100;

    if(mes > 2) mes = mes - 2;
    else if(mes == 2) mes = 12;
    else if(mes == 1) mes = 11;

    resultado = d->dia + (13 * mes - 1) / 5 + ano_a + ano_a/4 + ano_c/4 + 5 * ano_c;

    return (resultado) % 7 + 1;
}