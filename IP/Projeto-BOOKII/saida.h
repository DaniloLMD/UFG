#include "registro.h"

//mensagem que aparece assim que o programa inicia
void mensagem_inicial(void);

//muda a cor do texto para ciano
void ciano(void);

//mostra as opcoes do menu inicial e le a escolha do usuario
int menu_inicial(void);


//mostra os edificios cadastrados para o usuario escolher
int le_edificio(edificio* t, int tam);
//mostra as salas cadastradas para o usuario escolher
int le_sala(edificio t);

//funcao que le horario
int le_horario(int hMin, int hMax);
//funcao que le dia da semana
int le_dia(void);

//funcao que le o que o usuario quer editar em um predio
int le_edit_edificio(void);
//funcao que le o que o usuario quer editar em uma sala
int le_edit_sala(void);

//recebe um ponteiro de edificios e deleta o no indice informado
void deletar_predio(edificio* t, int indice_edificio, int tot_edificios);

//le os novos horarios de funcionamento de um edificio
void le_funcionamento(edificio* t);

//printa os horarios(7:00, 14:00 etc)
void printa_horarios();

//le uma string
void le_str(char* mensagem, char* s);

//funcao que salva os registros em um arquivo
void salva_arquivo(char* nome, int qtd_ed, edificio* t);
//salva arquivo fonte com os registros para serem lidos depois
void salva_arquivo_fonte(char* nome, int qtd_ed, edificio* t);
//funcao que le os registros salvos em um arquivo
edificio* le_arquivo(int *qtd_edificios, edificio* t);

//animacao inicial
void zera_matriz_booleana(void);
void printa_matriz(void);
void left_to_right(void);

//le se o usuario quer voltar ou continuar
int le_voltar(void);
 