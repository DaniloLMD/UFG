#include <stdio.h>

void trocaStr(char* s1, char* s2){
	char temp[200];
	int c, c2;
	
	//colocando a 1 str num temporario
	for(c = 0; s1[c] != '\0'; c++){
		temp[c] = s1[c];
	}
	temp[c] = s1[c];
	
	//colocando a 2 str na 1 str
	for(c = 0; s2[c] != '\0'; s2++){
		s1[c] = s2[c];
	}
	s1[c] = s2[c];
	
	//colocando o temporario na 2 str
	for(c = 0; temp[c] != '\0'; c++){
		s2[c] = temp[c];
	}
	s2[c] = temp[c];
}

/*
* recebe a data de nasc. de 2 alunos
* retorna 1 se o primeiro aluno for mais novo ou ter mesma idade
* retorna 0 se o segundo aluno for mais novo
*/
int comparaDataNasc(int nasc1[3], int nasc2[3]){
	int dia1 = nasc1[0], mes1 = nasc1[1], ano1 = nasc1[2];
	int dia2 = nasc2[0], mes2 = nasc2[1], ano2 = nasc1[2];
	
	printf("DATA 1 NA FUNC = %d/%d/%d\n", dia1, mes1, ano1);
	printf("DATA 2 NA FUNC = %d/%d/%d\n", dia2, mes2, ano2);
	
	//comparando os anos
	if(ano1 > ano2) return 1;
	
	//comparando os meses
	if(mes1 > mes2) return 1;
	
	//comparando os dias
	if(dia1 > dia2) return 1;
	
	return 0; 
}

int main(){
	int qtd;
	int mat[200], nasc[30][3];
	char nome[30][201];
	int c, c2, c3, tempI;
	
	scanf("%d", &qtd);
	for(c = 0; c < qtd; c++){
		//lendo matricula
		scanf("%d", &mat[c]);
		
		//lendo dia, mes e ano de nasc.
		scanf("%d %d %d%*c", &nasc[c][0], &nasc[c][1], &nasc[c][2]);
		
		//lendo o nome
		scanf("%[^\n]", nome[c]);
		printf("\n%d NASCEU EM %d/%d/%d\n", c, nasc[c][0], nasc[c][1], nasc[c][2]);
	}
	
	for(c = 0; c < qtd; c++){
		for(c2 = 0; c2 < qtd; c2++){
			if( comparaDataNasc(nasc[c], nasc[c2]) ){
				printf("--------------------\n");
				printf("%d EH MAIS NOVO QUE %d\n", c, c2);
				if(c > c2){
					printf("VOU TROCAR aaaaaaaa\n");
					
					printf("CCCCCCCCCCCCCCCCCCCC\n");
					//trocando as datas
					for(c3 = 0; c3 < 3; c3++){
						tempI = nasc[c][c3];
						nasc[c][c3] = nasc[c2][c3];
						nasc[c2][c3] = tempI;
					printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
					}	
					printf(
						"APOS TROCAR:\n"
						"%d: %d/%d/%d\n"
						"%d: %d/%d/%d\n", c, nasc[c][0],nasc[c][1],nasc[c][2], c2, nasc[c2][0], nasc[c2][1], nasc[c2][2] 
					);
				
					//trocando as matriculas
					tempI = mat[c];
					mat[c] = mat[c2];
					mat[c2] = tempI;
					
					//trocando os nomes
					trocaStr(nome[c], nome[c2]);
			}		
		}
		}
	}
	
	
	//printando
	for(c = 0; c < qtd; c++){
		printf("Matric.: %d Nome: %s Nasc: %d/%d/%d\n", mat[c], nome[c], nasc[c][0], nasc[c][1], nasc[c][2]);
	}

	return 0;
}
