#include <stdio.h>
 
int matricula[30], nascimento[30][3];
char nome[30][201];
 
void trocaNome(int indice1, int indice2){
    char temporario[201];
    int c;
    
    //colocando o nome1 no temporario
    for(c = 0; nome[indice1][c] != '\0'; c++){
        temporario[c] = nome[indice1][c];
    }
    temporario[c] = nome[indice1][c];
    
    //colocando o nome2 no nome1
    for(c = 0; nome[indice2][c] != '\0'; c++){
        nome[indice1][c] = nome[indice2][c];
    }
    nome[indice1][c] = nome[indice2][c];
    
    //colocando o temporario no nome2
    for(c = 0; temporario[c] != '\0'; c++){
        nome[indice2][c] = temporario[c];
    }
    nome[indice2][c] = temporario[c];
}
 
void trocaData(int indice1, int indice2){
    int temporario[3], c;
    for(c = 0; c < 3; c++){
        temporario[c] = nascimento[indice1][c];
        nascimento[indice1][c] = nascimento[indice2][c];
        nascimento[indice2][c] = temporario[c];
    }
}
 
void trocaMatricula(int indice1, int indice2){
    int temporario = matricula[indice1];
    matricula[indice1] = matricula[indice2];
    matricula[indice2] = temporario;
}
 
int ehMaisJovem(int *nasc1, int *nasc2){
    int dia1 = nasc1[0], mes1 = nasc1[1], ano1 = nasc1[2];
    int dia2 = nasc2[0], mes2 = nasc2[1], ano2 = nasc2[2];
    int maisJovem = 1;
    
    //comparando os anos de nascimento
    if(ano1 < ano2) maisJovem = 2;
    //comparando os meses
    if( ano1 == ano2 && mes1 < mes2) maisJovem = 2;
    //comparando os dias
    else if( ano1 == ano2 && mes1 == mes2 && dia1 < dia2) maisJovem = 2;
    
    if(maisJovem == 1) return 1; // o 1 eh mais jovem(V)
    if(maisJovem == 2) return 0; // o 1 NAO eh mais jovem(F)
}
 
int main(){
    int qtd;
    int c, c2, c3, qtdJovens, booleano;
    
    scanf("%d", &qtd);
    
    //lendo os alunos
    for(c = 0; c < qtd; c++){
        //lendo a matricula
        scanf("%d", &matricula[c]);
        
        //lendo a data de nasc.
        for(c2 = 0; c2 < 3; c2++){
            scanf("%d%*c", &nascimento[c][c2]);
        }
        
        //lendo o nome
        scanf("%[^\n]", nome[c]);
    }
    
    //comparando as idades e trocando de posicoes
    while(1){
        qtdJovens = 0;
        for(c = 0; c < qtd - 1; c++){
            booleano = ehMaisJovem(nascimento[c], nascimento[c+1]);
            //se o 1 nao for mais jovem que o 2, troca
            if( !booleano ){
                trocaData(c, c+1);
                trocaMatricula(c, c+1);
                trocaNome(c, c+1);
            }
            else if(booleano) qtdJovens++;
        }
        if(qtdJovens == qtd-1) break;
    }
    
    //printando o final
    for(c = 0; c < qtd; c++){
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n",
        matricula[c], nome[c], nascimento[c][0], nascimento[c][1], nascimento[c][2]);
    }
    
    return 0;
}
