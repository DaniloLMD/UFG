#include <stdio.h>



int pot(int a, int b){
    if(b == 0) return 1;
    return a * pot(a, b-1);
}

long int string2int( const char * str ){
    int c, tot = 0, peso = -1;
    long int num = 0;

    for(c  = 0; str[c] != '\0'; c++){
        if(str[c] == '.') break;

        if(str[c] >='0' && str[c] <= '9'){
          peso++;
        }
        tot++;
    }
    for(c = 0; c < tot; c++){
        if(str[c] >= '0' && str[c] <= '9'){
            num += (str[c] - '0') * pot(10, peso);       
            peso--;
        }
    }

    if(str[0] == '-') num *= -1;
    return num;
}

int main(){
    char v[128];
    long int n;

    while(scanf("%s", v) != EOF){

        n = string2int(v);
        printf("%ld %ld\n", n, n*2);
    }


    return 0;
}