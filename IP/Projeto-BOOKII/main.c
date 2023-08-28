//biblioteca com struct e funcoes para registrar edificios
#include "registro.h"
//biblioteca com manipulacao de arquivos e printf modificados
#include "saida.h"
//biblioteca com manipulacao de strings
#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char dias[7][8];
extern char horarios[qtd_horarios][12];

int main(){
    //struct edificio com as informacoes do usuario
    edificio* usuario;
    //variavel que guarda quantos edificios o usuario registrou
    int qtd_edificios = 0;
    //indice do vetor de edificio do usuario e do vetor salas
    int i, i_sala = 0;
    int dia, hora;
    //string temporaria para leitura de nomes
    char str_temp[STR_MAX_LEN];

    int escolha_usuario;
    int l, c;

    ciano();
    mensagem_inicial();

    while(1){

        escolha_usuario = menu_inicial();

        if(escolha_usuario == 0) break;

        if(escolha_usuario == 1){
            le_str("Nome do edificio: ", str_temp);

            i = checa_predio(str_temp, usuario, qtd_edificios);

            //nao achou o predio antes
            if(i == -1){
                i = qtd_edificios;
                qtd_edificios++;
                
                //alocando vetor de predios
                while(1){
                    usuario = (edificio*) realloc(usuario, qtd_edificios * sizeof(edificio));
                    if(usuario != NULL) break;
                }
                usuario[i].qtd_salas = 0;
                usuario[i].h_min = 0;
                usuario[i].h_max = qtd_horarios;

                str_copy(usuario[i].nome, str_temp);

                //iniciando os horarios de funcionamento do predio
                atualiza_horario(&usuario[i], 0, qtd_horarios);
            }
            
            le_str("Nome da sala: ", str_temp);
            
            i_sala = checa_sala(str_temp, usuario[i]);
            //nao achou sala anterior
            if(i_sala == -1){
                i_sala = usuario[i].qtd_salas;
                usuario[i].qtd_salas++;

                //alocando tamanho do vetor de salas do predio
                while(1){
                    usuario[i].salas = (sala*) realloc(usuario[i].salas, usuario[i].qtd_salas * sizeof(sala));
                    if(usuario[i].salas != NULL) break;
                }

                init_horario(&usuario[i].salas[i_sala]);
                
            }

            str_copy(usuario[i].salas[i_sala].nome, str_temp);
        }//escolha 1(registrar sala)


        else if(escolha_usuario > 1 && qtd_edificios == 0 && escolha_usuario != 5){
            printf("Nao ha edificios registrados!\n");
        }
        else if(escolha_usuario == 2){
            //procurando o predio
            i = le_edificio(usuario, qtd_edificios);
            //procurando a sala
            i_sala = le_sala(usuario[i]);
            
            hora = le_horario(usuario[i].h_min, usuario[i].h_max);
            dia = le_dia();
            
            //checa se a sala ja esta ocupada
            if(!checa_horario(usuario[i].salas[i_sala], dia, hora)){
                printf("A sala %s ja esta ocupada em %s!\n", usuario[i].salas[i_sala].nome, horarios[hora]);
            }
            else{
                marcar(&usuario[i].salas[i_sala], dia , hora);
                printf("Sala ocupada com sucesso!\n");
            }


        }//escolha 2(horario)

        else if(escolha_usuario == 3){

            //printando o edificio
            for(i = 0; i < qtd_edificios; i++){
                printf("────────┤ Edificio: %s ├────────\n", usuario[i].nome);
                printf("──────┤Salas:                 \n");
                //printando a sala
                for(i_sala = 0; i_sala < usuario[i].qtd_salas; i_sala++){
                    printf("  -> %s                    \n", usuario[i].salas[i_sala].nome);

                    //printando os dias da semana
                    printf("              ");
                    for(dia = 0; dia < qtd_dias; dia++){
                        printf("%s   ", dias[dia]);
                    }
                    printf("\n");

                    //printando a matriz de horarios
                    for(hora = usuario[i].h_min; hora < usuario[i].h_max; hora++){
                        printf("%s       ", horarios[hora]);
                        for(dia = 0; dia < qtd_dias; dia++){
                            printf("%c        ", usuario[i].salas[i_sala].horario[hora][dia]);
                        }
                        printf("\n");
                    }
                    
                }
                printf("\n");
            }
        }//escolha 3(ver registros)

        else if(escolha_usuario == 4){
            //lendo qual edificio
            i = le_edificio(usuario, qtd_edificios);
            

            //lendo o que o usuario quer
            escolha_usuario = le_edit_edificio();            
            
            //cancelar
            if(escolha_usuario == 0) continue;

            //mudar nome do predio
            else if(escolha_usuario == 1){
                le_str("Novo nome: ", str_temp);
                str_copy(usuario[i].nome, str_temp);
                printf("Nome alterado com sucesso!\n");
            }

            //mudar horario de funcionamento
            else if(escolha_usuario == 2){
                le_funcionamento(&usuario[i]);
            }

            //editar salas
            else if(escolha_usuario == 3){
                //buscando a sala
                i_sala = le_sala(usuario[i]);
                //buscando a opcao
                escolha_usuario = le_edit_sala();

                //cancelar
                if(escolha_usuario == 0) continue;
                //mudar nome
                else if(escolha_usuario == 1){
                    consome_buffer();
                    le_str("Novo nome: ", str_temp);
                    str_copy(usuario[i].salas[i_sala].nome, str_temp);
                    printf("Nome alterado com sucesso!\n");
                }

                //desocupar sala
                else if(escolha_usuario == 2){
                    printf(
                        "   1 -> Desocupar todos os horarios\n"
                        "   2 -> Desocupar horario especifico\n"
                    );
                    printf("Sua escolha: ");
                    scanf("%d", &escolha_usuario);
                    consome_buffer();
                    if(escolha_usuario == 1){
                        init_horario(&usuario[i].salas[i_sala]);
                    }
                    else if(escolha_usuario == 2){
                        dia = le_dia();
                        hora = le_horario(usuario[i].h_min, usuario[i].h_max);
                        desmarcar(usuario[i].salas[i_sala], dia, hora);
                    }
                    printf("Horario desmarcado!\n");
                }

                //deletar sala
                else if(escolha_usuario == 3){
                    deletar_sala(usuario[i].salas, i_sala, usuario[i].qtd_salas);
                    usuario[i].qtd_salas--;
                }
            }
            //deletar edificio
            else if(escolha_usuario == 4){
                deletar_predio(usuario, i, qtd_edificios);
                qtd_edificios--;
                printf("Edificio excluido com sucesso!\n");
            }
        }//escolha 4(editar ed.)
        

        else if(escolha_usuario == 5){//escolha 5(ler arq)
            qtd_edificios = 0;
            usuario = le_arquivo(&qtd_edificios, usuario);
        }//escolha 5(ler arq)


        sleep(1);
        printf("\n");
    }

    if(qtd_edificios > 0){
        // Escrever os registros    no arquivo
        le_str("Nome do arquivo de saida: ", str_temp);
        salva_arquivo(str_temp, qtd_edificios, usuario);
        le_str("Nome do arquivo de entrada: ", str_temp);
        salva_arquivo_fonte(str_temp, qtd_edificios, usuario);
        
        //dando free em tudo
		for(i = 0; i < qtd_edificios; i++){
		    free(usuario[i].salas);
		}
		free(usuario);
    }
    

    return 0;
}
