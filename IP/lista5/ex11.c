#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *pessoas;
	int *consumos;
	int qtd_imov;
	int tot_pessoas;
	int tot_consumo;
	double consumo_medio;
}	cidade;

int main(){
	int c, c2, qtd_imoveis, qtd_cidades = 0, i;
	cidade *v;
	while(1){
		//lendo quantos imoveis tem na cidade atual
		scanf("%d", &qtd_imoveis);
		if(qtd_imoveis == 0) break;
		//atualizando a quantidade de cidades
		qtd_cidades++;
		i = qtd_cidades - 1;
		//realocando o vetor conforme o numero de cidades aumenta
		v = realloc(v, qtd_cidades * sizeof(cidade));
		//alocando os vetores de pessoas e consumos
		v[i].pessoas = (int*) malloc(qtd_imoveis * sizeof(int));
		v[i].consumos = (int*) malloc(qtd_imoveis * sizeof(int));
		
		//lendo quantidade de pessoas e consumo de cada imovel
		v[i].qtd_imov = qtd_imoveis;
		v[i].tot_pessoas = 0;
		v[i].tot_consumo = 0;	
		for(c = 0; c < qtd_imoveis; c++){
			scanf("%d %d", &v[i].pessoas[c], &v[i].consumos[c]); 
			//calculando o tot_pessoas e o tot_consumo
			v[i].tot_pessoas += v[i].pessoas[c];
			v[i].tot_consumo += v[i].consumos[c];
		}
	
		//calculando o consumo medio da cidade
		v[i].consumo_medio = v[i].tot_consumo / v[i].tot_pessoas;
	}
	
	//printando
	for(c = 0; c < qtd_cidades; c++){
		printf("Cidade# %d:\n", c+1);
		for(c2 = 0; c2 < v[c].qtd_imov; c++){
			printf("%d-%d ",v[c].pessoas[c], v[c].consumos[c] / v[c].consumos[c]);
		}
		printf("\n");
		printf("Consumo medio: %.2lf m3.", v[c].consumo_medio);
		if(c + 1 != qtd_cidades) printf("\n");	
	}
	
	
	
	return 0;
}
