#include "str.h"
#include "registro.h"
#include "saida.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char dias[7][8];
extern char horarios[qtd_horarios][12];

//linha e coluna da mensagem ininicial
#define msg_inicial_linhas  7
#define msg_inicial_colunas 50

char msg_incial[msg_inicial_linhas][msg_inicial_colunas] = {
    "         _____    _____    _____          ___  ___",
    "        |     |  |     |  |     |  |   /   |    |",
    "        |     |  |     |  |     |  |  /    |    |",
    "        |_____|  |     |  |     |  | /     |    |",
    "        |_____   |     |  |     |  | \\     |    |",
    "        |     |  |     |  |     |  |  \\    |    |",
    "        |_____|  |_____|  |_____|  |   \\  _|_  _|_"
};
void mensagem_inicial(void) {
    left_to_right();
    printf("\n");
    printf("\tBEM VINDO AO BOOKII\n");
    printf("\033[5m\tPRESSIONE ENTER PARA CONTINUAR\n\n\n\n\n\n\033[0m");
    getchar();
    sleep(1);
    system("clear");
}

void ciano(void) {
    printf("\033[1;36m");
}
//mostra as opcoes do menu inicial e le a escolha do usuario
int menu_inicial(void){
    int escolha = -1;
    ciano();
    printf("Bem-Vindo ao BOOKII, seu sistema de reserva de salas, o que gostaria de fazer?\n");
	printf("Por favor selecione uma das opcoes a seguir:\n");
    printf( "┌──────────────────────────┐\n"
            "│  0 - Sair                │\n"
            "│  1 - Registrar sala      │\n"
            "│  2 - Registrar horario   │\n"
            "│  3 - Ver Registros       │\n"
            "│  4 - Editar Edificio     │\n"
            "│  5 - Ler arquivo salvo   │\n"
            "└──────────────────────────┘\n"
    );

    while(escolha < 0 || escolha > 5){
        printf("Sua escolha: ");
        scanf("%d", &escolha);
        consome_buffer();
    }

    return escolha;
}


//mostra os edificios cadastrados para o usuario escolher
int le_edificio(edificio* t, int tam){
    int escolha = -1, c;
    printf("Escolha o numero do edificio:\n");
    for(c = 0; c < tam; c++){
        printf("   %d - %s\n", c+1, t[c].nome);
    }
    do{
        printf("Sua escolha: ");
        scanf("%d", &escolha);
        consome_buffer();
    }while(escolha <= 0 || escolha > tam);
    return escolha-1;
}

//mostra as salas cadastradas para o usuario escolher
int le_sala(edificio t){
    int escolha = -1, c;
    printf("Escolha o numero da sala:\n");
    for(c = 0; c < t.qtd_salas; c++){
        printf("   %d - %s\n", c+1, t.salas[c].nome);
    }
    do{
        printf("Sua escolha: ");
        scanf("%d", &escolha);
        consome_buffer();
    }while(escolha <= 0 || escolha > t.qtd_salas);

    return escolha-1;
}

//funcoes que leem horario e dia
int le_horario(int hMin, int hMax){
    int escolha = -1, c;
    //printando os horarios
    printf("Escolha o numero do horario para a reserva: \n");
    for(c = hMin; c < hMax; c++){
    printf("   %d - %s\n", c+1, horarios[c]);
    }

    //lendo a escolha
    do{
       printf("Sua escolha: ");
       scanf("%d", &escolha);
       consome_buffer();

        if(escolha <= 0 || escolha > qtd_horarios) printf("O horario informado nao existe!\n");

       else if(escolha > hMax || escolha < hMin) printf("O edificio esta fechado no horario informado!\n");
    }while(escolha < hMin || escolha > hMax);

    return escolha-1;
}
int le_dia(void){
    int escolha = -1, c;

    //printando os dias
    printf("Escolha o numero do dia da reserva: \n");
    for(c = 0; c < qtd_dias; c++){
        printf("   %d - %s\n", c+1, dias[c]);
    }
    //lendo a escolha
    do{
       printf("Sua escolha: ");
       scanf("%d", &escolha);
       consome_buffer();
    }while(escolha <= 0 || escolha > qtd_dias);

    return escolha-1;
}

//funcao que le o que o usuario quer editar em um predio
int le_edit_edificio(void){
    int escolha = -1;
    printf("Por favor selecione uma das opcoes a seguir:\n");
    printf(
        "┌──────────────────────────┐\n"
        "│   0 - Cancelar           │\n"
        "│   1 - Mudar nome         │\n"
        "│   2 - Mudar horario      │\n"
        "│   3 - Editar salas       │\n"
        "│   4 - Deletar edificio   │\n"
        "└──────────────────────────┘\n"
    );
    do{
        printf("Sua escolha: ");
        scanf("%d", &escolha);
        consome_buffer();
    }while(escolha < 0 || escolha > 4);

    return escolha;
}

//funcao que le o que o usuario quer editar em uma sala
int le_edit_sala(void){
    int escolha = -1;
    printf("Por favor selecione uma das opcoes a seguir:\n");
    printf(
        "┌──────────────────────────┐\n"
        "│   0 - Cancelar           │\n"
        "│   1 - Mudar nome         │\n"
        "│   2 - Desocupar sala     │\n"
        "│   3 - Deletar sala       │\n"
        "└──────────────────────────┘\n"
    );
    do{
        printf("Sua escolha: ");
        scanf("%d", &escolha);
        if(escolha < 0 || escolha > 3) consome_buffer();
    }while(escolha < 0 || escolha > 3);

    return escolha;
}

//le os novos horarios de funcionamento de um edificio
void le_funcionamento(edificio* t){
    int inicio, fim;
    
    printa_horarios();
    do{
        printf("Este edificio abre a partir das: ");
        scanf("%d", &inicio);
    }while(inicio < 0 || inicio > qtd_horarios);

    do{
        printf("Este edifico fecha a partir das: ");
        scanf("%d", &fim);
    }while(fim < 0 || fim > qtd_horarios || fim < inicio);

    inicio--;
    atualiza_horario(t, inicio, fim);
}

//printa os horario com opcoes
void printa_horarios(){
    int c;
    for(c = 0; c < qtd_horarios; c++){
        printf("   %d -> %s\n", c+1, horarios[c]);
    }
}

//le uma string
void le_str(char* mensagem, char* s){
    int i = 0;
    char t;
    while(1){
        if(i == 0)printf("%s", mensagem);
        scanf("%c", &t);
        if(t == '\n') break;
        s[i] = t;   
        i++;
        if(i == STR_MAX_LEN - 1){
            printf("Nome muito longo. Por favor, insira outro:\n");
            consome_buffer();
            i = 0;
        }
    }
    s[i] = '\0';
    if(str_len(s) == 0) le_str(mensagem, s);
}

//funcao que salva os registros em um arquivo
void salva_arquivo(char* nome, int qtd_ed, edificio* t){
	FILE* arquivo_saida;
	int i, i_sala;
	int qtd_edificios = qtd_ed;
	int dia, hora;

	arquivo_saida = fopen(nome, "w");

	for(i = 0; i < qtd_edificios; i++){
		fprintf(arquivo_saida, "\t\t\t\t\t────────┤ Edificio: %s ├────────\n", t[i].nome);
		fprintf(arquivo_saida,"──────┤Salas:                      \n");
		//printando a sala
		for(i_sala = 0; i_sala < t[i].qtd_salas; i_sala++){
			fprintf(arquivo_saida,"  -> %s                    \n", 			t[i].salas[i_sala].nome);

			//printando os dias da semana
			fprintf(arquivo_saida,"              ");
			for(dia = 0; dia < qtd_dias; dia++){
				fprintf(arquivo_saida,"%s   ", dias[dia]);
			}
			fprintf(arquivo_saida,"\n");

			//printando a matriz de horarios
			for(hora = t[i].h_min; hora < t[i].h_max; hora++){
				fprintf(arquivo_saida,"%s       ", horarios[hora]);
				for(dia = 0; dia < qtd_dias; dia++){
					fprintf(arquivo_saida, "%c        ", t[i].salas[i_sala].horario[hora][dia]);
				}
				fprintf(arquivo_saida,"\n");
			}

		}
		fprintf(arquivo_saida,"\n");
	}
    // Fechar o arquivo
    fclose(arquivo_saida);
}

//funcao que le os registros salvos em um arquivo
edificio* le_arquivo(int *qtd_edificios, edificio* t){
    FILE* p = NULL;
    char nome_arquivo[STR_MAX_LEN];
    int escolha;
    
    while(1){
        le_str("Nome do arquivo: ", nome_arquivo);
        p = fopen(nome_arquivo, "r");
        if(p == NULL){
            printf("Nao encontrei o arquivo \"%s\"!\n", nome_arquivo);
        }

        p = fopen(nome_arquivo, "r");
        if(p == NULL){
        printf(
            "   0 -> Voltar\n"
            "   1 -> Continuar\n"
        );
        printf("Sua escolha: ");
        scanf("%d", &escolha);
        if(escolha > 1 || escolha < 0) printf("Opcao invalida!\n");
        if(escolha == 0) return t;
        consome_buffer();
        }
        else break;
    }

    int temp;
    int i, i_sala, dia, hora;
    char str_temp[STR_MAX_LEN];
    char buf_temp;
    
    //lendo a quantidade de edificios
    fscanf(p, "%d", &temp);
    //alocando vetor de predios
    while(1){
        t = (edificio*) realloc(t, (temp + *qtd_edificios) * sizeof(edificio));
        if(t != NULL) break;
    }
    
    //percorrendo todos os edificios
    for(i = *qtd_edificios; i < *qtd_edificios + temp; i++){
        //lendo o h_min e o h_max do edificio
        fscanf(p, "%d %d", &t[i].h_min, &t[i].h_max);

        //lendo a quantidade de salas
        fscanf(p, "%d%*c", &t[i].qtd_salas);
        //lendo o nome do edificio
        fscanf(p, "%[^\n]%*c", t[i].nome);


        //alocando tamanho do vetor de salas do predio
        while(1){
            t[i].salas = (sala*) realloc(t[i].salas, t[i].qtd_salas * sizeof(sala));
            if(t[i].salas != NULL) break;
        }

        for(i_sala = 0; i_sala < t[i].qtd_salas; i_sala++){
            //lendo o nome da sala
            fscanf(p, "%[^\n]%*c", t[i].salas[i_sala].nome);

            //lendo a matriz de horarios da sala
            for(hora = 0; hora < qtd_horarios; hora++){
                for(dia = 0; dia < qtd_dias; dia++){
                    fscanf(p, "%c ", &t[i].salas[i_sala].horario[hora][dia]);
                    if(t[i].salas[i_sala].horario[hora][dia] != vazio && t[i].salas[i_sala].horario[hora][dia] != ocupado) dia--;
                }
            }
        }
    }

    *qtd_edificios += temp;
    fclose(p);

    return t;
}

//salva arquivo fonte com os registros para serem lidos depois
void salva_arquivo_fonte(char* nome, int qtd_ed, edificio* t){
    FILE* p;
    int i, i_sala, hora, dia;

    p = fopen(nome, "w");
    //printando a quantidade de horarios
    fprintf(p, "%d\n", qtd_ed);

    for(i = 0; i < qtd_ed; i++){
        //printando h_min e h_max do edificio
        fprintf(p, "%d %d\n", t[i].h_min, t[i].h_max);

        //printando a quantidade de salas do edificio
        fprintf(p, "%d\n", t[i].qtd_salas);

        //printando o nome do edificio
        fprintf(p, "%s\n", t[i].nome);

        for(i_sala = 0; i_sala < t[i].qtd_salas; i_sala++){
            //printando o nome da sala
            fprintf(p, "%s\n", t[i].salas[i_sala].nome);

            //printando a matriz de horarios
            for(hora = 0; hora < qtd_horarios; hora++){
                for(dia = 0; dia < qtd_dias; dia++){
                    fprintf(p, "%c ", t[i].salas[i_sala].horario[hora][dia]);
                }
                fprintf(p, "\n");
            }
        }
    }


    fclose(p);
}

char matriz_booleana[msg_inicial_linhas][msg_inicial_colunas];

void zera_matriz_booleana(void){
	int lin, col;
	for(lin = 0; lin < msg_inicial_linhas; lin++){
		for(col = 0; col < msg_inicial_colunas; col++){
			matriz_booleana[lin][col] = 0;
		}
	}
}

void printa_matriz(void){
	int i, j;
	for(i = 0; i < msg_inicial_linhas; i++){
		for(j = 0; j < msg_inicial_colunas; j++){
			if(matriz_booleana[i][j] == 0) printf(" ");
			else printf("%lc", msg_incial[i][j]);
		}
		printf("\n");
	}
}

void left_to_right(void){
	int i, j;
	zera_matriz_booleana();
	
	for(j = 0; j < msg_inicial_colunas; j++){
		for(i = 0; i < msg_inicial_linhas; i++){
			matriz_booleana[i][j] = 1;
		}
	 	system("clear");
		printa_matriz();
		fflush(stdout);
		usleep(67000);
	}
}	

int le_voltar(void){
    int esc = -1;
    printf(
        "0 -> Voltar\n"
        "1 -> Continuar\n"
    );
    do{
        scanf("%d", &esc);
    }while(esc < 0 || esc > 1);
    return esc;
}
