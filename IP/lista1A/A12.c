#include <stdio.h>

#define salario 937.00

int main(){
	int Lx;
	float renda, salarioCalc;
	int pessoas, escola, etnia;
	
	/* escola : 1- particular, 2- pública
	   etnia : 1- preto; 2- pardo; 3- indígena; 4- branco*/
	
	scanf("%f %d %d %d", &renda, &pessoas, &escola, &etnia);
	
	renda = renda / pessoas;
	salarioCalc = 1.5 * salario;
	
	if (escola == 2){
		printf("ALUNO COTISTA");
		if (renda <= salarioCalc){
			if (etnia == 4){
				Lx = 1;
				printf(" (L%d)\n", Lx);
			}else if (etnia == 1  || etnia == 2 || etnia == 3){
				Lx = 2;
				printf(" (L%d)\n", Lx);
			}
		}else if(etnia == 1 || etnia == 2 || etnia == 3){
			Lx = 4;
			printf(" (L%d)\n", Lx);
		}else{
			Lx = 3;
			printf(" (L%d)\n", Lx);
			}
	
	} else if (escola == 1){
		printf("ALUNO NAO COTISTA\n");
	}
	


	return 0;
}
