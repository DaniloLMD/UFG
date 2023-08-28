#include "registro.h"
#include "str.h"
#include <stdlib.h>
#include <stdio.h>

char horarios[qtd_horarios][12] = {
    "07:10-08:00", 
    "08:00-08:50",
    "08:50-09:40",
    "10:00-10:50",
    "10:50-11:40",
    "13:10-14:00",
    "14:00-14:50",
    "14:50-15:40",
    "16:00-16:50",
    "16:50-17:40",
    "17:40-18:30",
    "18:05-18:50",
    "18:50-19:35",
    "19:35-20:20",
    "20:30-21:15",
    "21:15-22:00",
};

char dias[7][8] = {
    "Domingo",
    "Segunda",
    "Terca",
    "Quarta",
    "Quinta",
    "Sexta",
    "Sabado",
};

//checa se tem alguma sala naquele edificio que ja esta registrada no mesmo dia e horario e retorna 1(OCUPADO) ou 0(VAZIO)
int checa_horario(sala s, int dia, int horario){
    if(s.horario[horario][dia] != vazio) return 0;
    return 1;
}

//atualiza a matriz de horarios para o horario de funcionamento do edificio. Ex: modificar horario para apenas das 10 as 17h
void atualiza_horario(edificio* t, int horario_min, int horario_max){
    t->h_min = horario_min;
    t->h_max = horario_max;
}

//recebe predio, sala, dia e horario e verifica se é possivel registrar e retorna 1(conseguiu marcar) ou 0 (nao conseguiu marcar)
int marcar(sala*s, int dia, int hora){
	if(s->horario[hora][dia] != vazio) return 0;
	s->horario[hora][dia] = ocupado;
	return 1;
}

//recebe sala, dia e horario e desmarca
void desmarcar(sala s,int dia, int hora){
	s.horario[hora][dia] = vazio;
}

//recebe o nome de um predio e checa se ele ja foi registrado antes. retorna -1 caso nao existe, e caso exista retorna o indice do vetor
int checa_predio(char *nome, edificio* t, int tam){
    int c;
    for(c = 0; c < tam; c++){
        if(str_compare(nome, t[c].nome)) return c;
    }
    return -1;
}

//recebe o nome de uma sala e seu predio e retorna se a sala ja existe. Caso sim, retorna o indice da sala, caso nao retorna -1
int checa_sala(char *nome, edificio t){
    int c;
    for(c = 0; c < t.qtd_salas; c++){
        if(str_compare(nome, t.salas[c].nome)){
            return c;
        }
    }
    return -1;
}

//recebe uma sala e inicia a matriz de horarios dela
void init_horario(sala* s){
    int i, j;
    for(i = 0; i < qtd_horarios; i++){
        for(j = 0; j < qtd_dias; j++){
            s->horario[i][j] = vazio;
        }
    }
}

//recebe um ponteiro de edificios e deleta o no indice informado
void deletar_predio(edificio* t, int indice_edificio, int tot_edificios){
    int c;

    //copiando os indices posteriores
    for(c = indice_edificio; c < tot_edificios - 1; c++){
        t[c] = t[c+1];
    }
    
    while(1){
        t = (edificio*) realloc(t, (tot_edificios-1) * sizeof(edificio));
        if(t != NULL) break;
    }
}

//recebe um ponteiro de salas e deleta a sala no inidice informado
void deletar_sala(sala* s, int indice_sala, int tot_salas){
    int c;

    //copiando os indices posteriores
    for(c = indice_sala; c < tot_salas-1; c++){
        s[c] = s[c+1];
    }

    while(1){
        s = (sala*) realloc(s, (tot_salas-1)*sizeof(sala));
        if(s != NULL) break;
    }
}