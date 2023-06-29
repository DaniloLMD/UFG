#include <stdio.h>

/**
* @param valor numero a ser checado
* @param *v vetor 
* @param tamV tamanho do vetor
* @return -1(F) ou C2(indice que tem o numero no 2 vetor) se o elemento ta nos 2 vetores
*/
int temNosDois(int valor, int *v, int tamV){
	int c, c2 = 0;
	
	for(c = 0; c < tamV; c++){
		if(v[c] == valor) return c;
	}

	return -1;
}

//retorna a soma de 2 numeros, trocando o sinal do segundo se a operacao for '-'
double somatorio(char operacao, double n1, double n2){
	if(operacao == '-') n2 *= -1;
	return n1 + n2;
}

//retorna quantidade de termos em comum entre 2 vetores
int intersec(int *v1, int *v2, int tamanho, int tamanho2){
	int c, c2, comuns = 0;
	for(c = 0; c < tamanho; c++){
		for(c2 = 0; c2 < tamanho2; c2++){
			if(v1[c] == v2[c2]) comuns++;
		}
	}
	
	return comuns;
}

int main(){
	char operacao;
	int testes, indice;
	double numero, num1[50], num2[50];
	int exp1[50], exp2[50];
	int c, c2, qtdTermos1, qtdTermos2, qtdTermosFim;
	double numFim[100];
	int expFim[100], maiorExp;
	
	
	scanf("%d%*c", &testes);
	
	
	while(testes--){
		scanf("%c%*c", &operacao);
		
		//lendo termos do 1 polinomio
		scanf("%d%*c", &qtdTermos1);
		for(c = 0; c < qtdTermos1; c++) scanf("%lf %d", &num1[c], &exp1[c]);	
		
		
		//lendo termos do 2 polinomio
		scanf("%d%*c", &qtdTermos2);
		for(c = 0; c < qtdTermos2; c++) scanf("%lf %d", &num2[c], &exp2[c]);		
			
		//fazendo as operacoes com todos os expoentes do 1 vetor
		for(c = 0; c < qtdTermos1; c++){
			indice = temNosDois(exp1[c], exp2, qtdTermos2);
			if(indice != -1){
				numero = somatorio(operacao, num1[c], num2[indice]);
			}
			else numero = num1[c];
			
			numFim[c] = numero;
			expFim[c] = exp1[c];
		}	
		
		//fazendo as operacoes com os expoentes que não estão no 1 vetor
		
		for(c2 = 0; c2 < qtdTermos2; c2++){
			indice = temNosDois(exp2[c2], exp1, qtdTermos1);
			if(indice == -1){
				numFim[c] = num2[c2];
				expFim[c] = exp2[c2];
				c++;
			}
		}
		
		//rodando o vetor do numFim
		qtdTermosFim = qtdTermos1 + qtdTermos2 - intersec(exp1, exp2, qtdTermos1, qtdTermos2);
		for(c2 = 0; c2 < qtdTermosFim; c2++){
			//pegando o maior expoente
			maiorExp = expFim[0];
			indice = 0;
			for(c = 0; c < qtdTermosFim; c++){
				if(expFim[c] > maiorExp){
					maiorExp = expFim[c];
					indice = c;
				}
			}
			//printando o numero e o maior expoente
			if(numFim[indice] > 0) printf("+");
			
			if(numFim[indice] == 0);
			else{
				if(maiorExp == 0) printf("%.2lf", numFim[indice]);
				else printf("%.2lfX^%d", numFim[indice], expFim[indice]);
			}
			expFim[indice] = -1; //retirando o maior exp
		}
		printf("\n");
	}

	return 0;
}
