#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int likes, retweets, mencoes;
}usuario;

int main(){
	usuario** mat = NULL;
	char **mat_bool = NULL;
	int dim, qtd, c, i, j, l, r, m, vazio = 0;
	double tot_l, tot_r, tot_m;
	tot_l = tot_r = tot_m = 0;
	
	//lendo e alocando a dimensao da matriz
	scanf("%d", &dim);
	mat = (usuario**) malloc(dim * sizeof(usuario*));
	if(mat == NULL) return 0;
	for(c = 0; c < dim; c++){
		mat[c] = (usuario*) malloc(dim * sizeof(usuario));
		if(mat[c] == NULL) return 0;
	}
	mat_bool = (char**) malloc(dim * sizeof(char*));
	if(mat_bool == NULL) return 0;
	for(c = 0; c < dim; c++){
		mat_bool[c] = (char*) malloc(dim * sizeof(char));
		if(mat_bool[c] == NULL) return 0;
	}
	//zerando a matriz booleana
	for(i = 0; i < qtd; i++){
		for(j = 0; j < qtd; j++){
			mat_bool[i][j] = 0;
		}
	}
	
	//lendo a quantidade de testes;
	scanf("%d", &qtd);
	
	//lendo a matriz
	for(c = 0; c < qtd; c++){
		scanf("%d %d %d %d %d", &i, &j, &l, &r, &m);
		tot_l += l;
		tot_r += r;
		tot_m += m;
		
		if(mat_bool[i][j] == 0){
			mat_bool[i][j] = 1;
			mat[i][j].likes = 0;
			mat[i][j].retweets = 0;
			mat[i][j].mencoes = 0;
		}
		mat[i][j].likes += l;
		mat[i][j].retweets += r;
		mat[i][j].mencoes += m;
	}
	qtd = 0;
	for(i = 0; i < dim; i++){
		l = r = m = 0;
		for(j = 0; j < dim; j++){
			if(mat_bool[i][j] == 1){
				l += mat[i][j].likes;
				r += mat[i][j].retweets;
				m += mat[i][j].mencoes;
			}
			else vazio++;
		}
		if(l > 0 || m > 0 || r > 0){
			qtd++;
			printf("Usuario %d - num. likes: %d, num. retweets: %d e num. mencoes: %d\n", i, l, r, m);
		}
	}
	
	tot_l /= qtd;
	tot_m /= qtd;
	tot_r /= qtd;
	printf(
	"Slots vazios: %d\n"
	"Media de likes por usuario: %.2lf\n"
	"Media de retweets por usuario: %.2lf\n"
	"Media de mencoes por usuario: %.2lf\n", vazio, tot_l, tot_r, tot_m
	);

	return 0;
}
