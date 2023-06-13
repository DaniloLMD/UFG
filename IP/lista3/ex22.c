#include <stdio.h>

void achar_anao(int *p){
    int a, b, c, soma = 0;
    int ord[7], t = 0, x = 0, q;

    for(a = 0; a < 9; a++){
        for(b = a + 1; b < 9; b++){

            soma = 0;   
            for(c = 0; c < 9; c++){
                if(c != a && c != b) soma += p[c];
            }

            if(soma == 100){
                for(c = 0; c < 9; c++){
                    if(c != a && c != b){
                        ord[t] = p[c];
                        t++;
                    }
                }
                while(1){
                    for(q = 0; q < 6; q++){
                        if(ord[q] > ord[q + 1]){
                            t = ord[q];
                            ord[q] = ord[q+1];
                            ord[q + 1] = t;
                        }
                        else x++;
                    }
                    if(x == 6){
                        for(q = 0; q < 7; q++) printf("%d\n", ord[q]);
                        return;
                    }
                    x = 0;
                }
            }
        }
    }


}

int main(){

    int qtd, v[9] ,c;

    scanf("%d", &qtd);

    while(qtd--){
        for(c = 0; c < 9; c++) scanf("%d", &v[c]);
        achar_anao(v);
    }

    return 0;
}