#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 4

typedef struct{
	double pontos[N];
	double norma;
} ponto;

double calc_norma(double *v){
	double n = 0;
	int c, c2;
	
	for(c = 0; c < N; c++){
		n += v[c] * v[c];
	}
	n = sqrt(n);
	
	return n;
}

void ordena_struct(ponto* v, int tam){
	int c, c2;
	ponto temp;
	for(c = 0; c < tam; c++){
		for(c2 = 0; c2 < tam-1; c2++){
			if(v[c2].norma > v[c2+1].norma){
				temp = v[c2];
				v[c2] = v[c2+1];
				v[c2+1] = temp;
			}
		}
	}
	
}


int main(){
	int qtd, c, c2;
	ponto *v;
	scanf("%d", &qtd);
	v = (ponto*) malloc(qtd * sizeof(ponto));
	
	//lendo os pontos
	for(c = 0; c < qtd; c++){
		for(c2 = 0; c2 < N; c2++){
			scanf("%lf", &v[c].pontos[c2]);
		}
		v[c].norma = calc_norma(v[c].pontos);
	}	
	
	ordena_struct(v, qtd);
	
	//printando
	for(c = 0; c < qtd; c++){
		printf("Vetor: (");
		for(c2 = 0; c2 < N; c2++){
			printf("%.2lf", v[c].pontos[c2]);
			if(c2 + 1 != N) printf(", ");
		}
		printf(") Norma: %.2lf\n", v[c].norma);
	}
	return 0;
}
