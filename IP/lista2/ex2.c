#include <stdio.h>

int fibonacci( int t1, int t2, int n){
    int prox;
    int temp;
    int c;
    for(c = 2; c < n; c++){
        prox = t1 + t2;
        t1 = t2;
        t2 = prox;
    }
    if(n > 2){
        return prox;
    }else if(n == 1){
        return t1;
    }else if(n == 2){
        return t2;
    }
}

int fibonacci_r(int t1, int t2, int n){
	if(n == 1) return t1;
	if(n == 2) return t2;
	return fibonacci_r(t1, t2, n - 1) + fibonacci_r(t1, t2, n - 2);
}



int main(){
    int a, b, c;
    int fib;
    scanf("%d %d %d", &a, &b, &c);
    fib = fibonacci(a, b, c);
    printf("%d\n", fib);
    return 0;
}
