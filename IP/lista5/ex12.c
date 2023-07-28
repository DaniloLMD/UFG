#include <stdio.h>

typedef struct{
	int a, b;
} tRacional;

//MDC entre 2 racionais
int MDC(int x, int y){
	int c, m = 1;
	if(x < 0) x *= -1;
	if(y < 0) y *= -1;
	for(c = 2; c <= y && c <= x; c++){
		if(x%c == 0 && y%c == 0){
			m = c;
		}
	}
	
	return m;
}

//retorna o racional na forma a/b
tRacional racional(int a, int b);

//retorna o numero racional negativo (-r)
tRacional negativo(tRacional r){
	tRacional t = r;
	t.a *= -1;
	return t;
}

//soma dois racionais
tRacional soma(tRacional r1, tRacional r2){
	tRacional t;
	t.a = r1.a * r2.b + r1.b * r2.a;
	t.b = r1.b * r2.b;
	return t;
}

//multiplicacao
tRacional mult(tRacional r1, tRacional r2){
	tRacional t;
	t.a = r1.a * r2.a;
	t.b = r1.b * r2.b;
	return t;
}

//divisao
xtRacional div(tRacional r1, tRacional r2){
	tRacional t;
	t.a = r1.a * r2.b;
	t.b = r1.b * r2.a;
	return t;
}

//reduz a fracao ao maximo
void reduzFracao(tRacional *r);

int main(){
	tRacional n1, n2, res;
	char op;
	int mdc;
	while(scanf("%d %d %c %d %d", &n1.a, &n1.b, &op, &n2.a, &n2.b) != EOF){
		mdc = MDC(n1.b, n2.b);
		switch(op){
			case '-':
				n2 = negativo(n2);
			case '+':
				res = soma(n1, n2);
				break;
			case '*':
				res = mult(n1, n2);
				break;
			case '/':
				res = div(n1, n2);
				break;
		}
		mdc = MDC(res.a, res.b);
		res.a /= mdc;
		res.b /= mdc;
		printf("%d %d\n", res.a, res.b); 
	}
	return 0;
}


/*
	a/b + c/d = a*d + b*c/b*d
	a/b * c/d = a*c / b*d
	a/b / c/d = a*d / b*c
*/
