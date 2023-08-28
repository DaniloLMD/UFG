#ifndef registro_h
#define registro_h
#define qtd_horarios 16
#define qtd_dias 7
#define STR_MAX_LEN 51
//caracter que representa horarios vazios
#define vazio  '-'
#define ocupado 'X'

//struct que representa uma sala
typedef struct{
	//nome da sala
	char nome[STR_MAX_LEN];
    //Matriz em que cada linha representa um horario e cada coluna representa um dia da semana. Cada elemento dela contem se a sala estará ocupando o horario naquele dia.
    char horario[qtd_horarios][qtd_dias];
}sala;

//struct que representa cada edificio da UFG(ex: CAB, INF, IME)
typedef struct{
    //variaveis que guardam o horario de funcionamento do edificio(ex: 0,1 -> 7:10 as 8:50)
    int h_min, h_max;

    //nome do edificio
    char nome[STR_MAX_LEN];
    
    //vetor de salas
    sala *salas;
    
    //quantidade de salas do predio
    int qtd_salas;


} edificio;

//checa se tem alguma sala naquele edificio que ja esta registrada no mesmo dia e horario e retorna 1(OCUPADO) ou 0(VAZIO)
int checa_horario(sala s, int dia, int horario);

//atualiza a matriz de horarios para o horario de funcionamento do edificio. Ex: modificar horario para apenas das 10 as 17h
void atualiza_horario(edificio* t, int horario_min, int horario_max);

//recebe sala, dia e horario e verifica se é possivel registrar e retorna 1(conseguiu marcar) ou 0 (nao conseguiu marcar)
int marcar(sala* s, int dia, int hora);

//recebe sala, dia e horario e desmarca
void desmarcar(sala s,int dia, int hora);

//recebe o nome de um predio e checa se ele ja foi registrado antes. retorna -1 caso nao existe, e caso exista retorna o indice do vetor
int checa_predio(char *nome, edificio* t, int tam);

//recebe o nome de uma sala e seu predio e retorna se a sala ja existe. Caso sim, retorna o indice da sala, caso nao retorna -1
int checa_sala(char *nome, edificio t);

//recebe uma sala e inicia a matriz de horarios dela
void init_horario(sala* s);

//recebe um ponteiro de edificios e deleta no indice informado
void deletar_predio(edificio* t, int indice_edificio, int tot_edificios);
//recebe um ponteiro de salas e deleta a sala no inidice informado
void deletar_sala(sala* s, int indice_sala, int tot_salas);

#endif