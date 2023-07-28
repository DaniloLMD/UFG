#include <stdio.h>
#include <stdlib.h>

typedef char bool;

typedef struct{
	float valor
	int potencia;
	bool considerado;
}polinomio;

int main(){
	int qtd;
	char op;
	int t1, t2, c, c2, i = 0;
	bool achou_igual;
	polinomio *v, *n1, *n2;
	
	scanf("%d%*c", &qtd);
	while(qtd--){
		i = 0;
		//lendo a operacao
		scanf("%c", &op);
		//lendo o tamanho do 1 polinomio
		scanf("%d", &t1);
		n1 = (polinomio*) malloc(t1 * sizeof(polinomio));
		for(c = 0; c < t1; c++){
			scanf("%f %d", &n1[c].valor, &n1[c].potencia);
		}
		
		//lendo o tamanho do 2 polinomio
		scanf("%d", &t2);
		n2 = (polinomio*) malloc(t2 * sizeof(polinomio));
		for(c = 0; c < t2; c++){
			scanf("%f %d", &n2[c].valor, &n2[c].potencia);
			if(op == '-') n2[c].valor *= -1;
			n2[c].considerado = 0;
		}
		
		for(c = 0; c < t1; c++){
			achou_igual = 0;
			v = (polinomio*) realloc((i+1) * sizeof(polinomio));
			for(c2 = 0; c2 < t2; c2++){
				if(n1[c].potencia == n2[c2].potencia){
					achou_igual = 1;
					n2[c2].considerado = 1;
					v[i].potencia = n1[c].potencia;
					v[i].valor = n1[c].valor + n2[c2].valor;
				}	
			}
			if(!achou_igual){
				v[i].potencia = n1[c].potencia;
				v[i].valor = n1[c].valor;
			}
			i++;
	}
	for(c = 0; c < t2; c++){
		if(n2[c].considerado == 0){
			v[i].potencia = n2[c].potencia;
			v[i].valor = n2[c].valor;
			i++;
		}
	}
	
	ordena(v);
	
	
	
	
	
	
	return 0;
}
