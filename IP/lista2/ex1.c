#include <stdio.h>

unsigned long int fat( unsigned int n){
    unsigned long int fatorial = 1;
    int c;
    for(c = 2; c <= n; c++){
        fatorial *= c;
    }
    return fatorial;
}

int main(){
    unsigned int n;
    scanf("%d", &n);
    unsigned long int f = fat(n);
    printf("%d! = %lu\n", n, f);

    return 0;
}