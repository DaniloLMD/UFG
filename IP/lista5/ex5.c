#include <stdio.h>
#include <stdlib.h>

struct curso{
	int codigo;
	float credito;
	char nome[101];
};
struct aluno{
	char nome[501];
	int matricula;
	int creditos;
};

//typedef struct curso curso;
//typedef struct aluno aluno;

int main(){
	int qtdCursos, qtdAlunos;
	int c, x;
	struct curso *vCurso;
	struct aluno *vAluno;
	
	//lendo a quantidade de cursos
	scanf("%d", &qtdCursos);
	vCurso = (struct curso*) malloc(qtdCursos * sizeof(struct curso));
	//lendo os elementos de cada curso
	for(c = 0; c < qtdCursos; c++){
		scanf("%d", &vCurso[c].codigo);
		scanf("%f%*c", &vCurso[c].credito);
		scanf("%[^\n]", vCurso[c].nome);
	}
	
	//lendo a quantidade de alunos
	scanf("%d%*c", &qtdAlunos);
	vAluno = (struct aluno*) malloc(qtdAlunos * sizeof(struct aluno));
	//lendo os elementos de cada aluno
	for(c = 0; c < qtdAlunos; c++){
		scanf("%[^\n]", vAluno[c].nome);
		scanf("%d", &vAluno[c].matricula);
		scanf("%d%*c", &vAluno[c].creditos);
	}
	
	//printando
	for(c = 0; c < qtdAlunos; c++){
		//pegando o indice que representa qual o curso do estudante c
		for(x = 0; x < qtdCursos; x++){
			if(vAluno[c].matricula == vCurso[x].codigo) break;
		}
	
		printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2f Mensalidade: %.2f\n",
			vAluno[c].nome, vCurso[x].nome, vAluno[c].creditos, vCurso[x].credito, vAluno[c].creditos * vCurso[x].credito);
	}
	

	return 0;
}
