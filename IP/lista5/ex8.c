#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int codigo;
	float preco_credito;
	char *nome;
}curso;

typedef struct{
	char *nome;
	int codigo;
	int qtd_credito;

}aluno;

int str_len(char *s){
	int c;
	for(c = 0; s[c] != '\0'; c++);
	return c+1;
}

char* str_copy(char*s){
	char* t = (char*) malloc(str_len(s) * sizeof(char));
	int c;
	
	for(c = 0; s[c] != '\0'; c++){
		t[c] = s[c];
	}
	t[c] = '\0';
	
	return t;
}

int main(){
	char str_temp[1000];
	int qtd_cursos, qtd_alunos, c, tamanho, c2;
	curso* vC;
	aluno* vA;

	//lendo os dados dos cursos
	scanf("%d", &qtd_cursos);
	vC = (curso*) malloc(qtd_cursos * sizeof(curso));
	for(c = 0; c < qtd_cursos; c++){
		scanf("%d", &vC[c].codigo);
		scanf("%f%*c", &vC[c].preco_credito);
		scanf("%[^\n]", str_temp);
		vC[c].nome = str_copy(str_temp);
	}

	//lendo os dados dos alunos
	scanf("%d%*c", &qtd_alunos);
	vA = (aluno*) malloc(qtd_alunos * sizeof(aluno));
	for(c = 0; c < qtd_alunos; c++){
		scanf("%[^\n]", str_temp);
		scanf("%d", &vA[c].codigo);
		scanf("%d%*c", &vA[c].qtd_credito);
		vA[c].nome = str_copy(str_temp);
	}

	//printando
	for(c = 0; c < qtd_alunos; c++){
		
		//achando o curso do aluno
		for(c2 = 0; c2 < qtd_cursos; c2++){
			if(vA[c].codigo == vC[c2].codigo) break;
		}
	
		printf(
			"Aluno(a): %s "
			"Curso: %s "
			"Num. Creditos: %d "
			"Valor Credito: %.2f "
			"Mensalidade: %.2f\n",
			vA[c].nome, vC[c2].nome, vA[c].qtd_credito, vC[c2].preco_credito, vA[c].qtd_credito * vC[c2].preco_credito
		);
	}


	//liberando a memoria dos cursos
	for(c = 0; c < qtd_cursos; c++){
		free(vC[c].nome);
	}	
	free(vC);

	//liberando a memoria dos alunos
	for(c = 0; c < qtd_alunos; c++){
		free(vA[c].nome);
	}
	free(vA);

	return 0;
}
