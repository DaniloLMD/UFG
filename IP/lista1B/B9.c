#include <stdio.h>
#include <math.h>

int main(){
	double n;
	double e;
	double r[50];
	double raiz;
	double erro;
	int k = 0;
	
	r[0] = 1;
	
	scanf("%lf", &n);
	scanf("%lf", &e);
	
	raiz = sqrt(n);
	
	//printf("%.9lf\n", fabs(n - (r[k] * r[k])));
	while(1){
		if (fabs(n - (r[k] * r[k])) <= e){
			break;
		}
	
		k++;
		r[k] = (r[k-1] + n/r[k-1]) / 2;
		erro = n - (r[k] * r[k]);
		printf("r: %.9lf, err: %.9lf\n", r[k], fabs(erro));
	}
	

	return 0;
}
