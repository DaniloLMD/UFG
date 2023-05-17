#include <stdio.h>

int main(){
    int d, m, a;
    char bissexto = 'n';

    scanf("%d %d %d", &d, &m, &a);

    if(a % 4 == 0 && a % 100 != 0 || a % 400 == 0){
        bissexto = 's'
    }
    
    if(a < 1900 || a > 2036){
        printf("DATA FORA DO INTERVALO ESTIPULADO\n");
        return 0;
    }

    else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){

    }
    else if(m == 4 || m == 6 || m == 9 || m == 11){

    }else if(m == 2){
        if(bissexto == 's'){

        }else(){
            
        }
    }






    return 0;
}