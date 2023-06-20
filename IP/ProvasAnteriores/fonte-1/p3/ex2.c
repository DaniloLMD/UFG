#include <stdio.h>

void ordena(int *x, int qtd){
    int c, k, t;
    while(1){
        k = 0;
        for(c = 0; c < qtd - 1; c++){
            if(x[c] > x[c+1]){
                t = x[c];
                x[c] = x[c+1];
                x[c+1] = t;
            }
            else k++;
        }
        if(k == qtd - 1) break;
    }
}


int main(){
    int n, col, lin, i = 0, j = 0, c = 0;
    int m[1000][1000], m2[1000][1000], v[1000];

    scanf("%d", &n);

    for(lin = 0; lin < n; lin++){
        for(col = 0; col < n; col++) scanf("%d", &m[lin][col]);
    }  

    for(col = 0; col < n; col++){
        c = 0;
        for(lin = 0; lin < n; lin++){
            v[c] = m[lin][col];
            c++;
        }

        ordena(v, c);
        c = 0;
        for(lin = 0; lin < n; lin++){
            m[lin][col] = v[c];
            c++;
        }
    }

    for(lin = 0; lin < n; lin++){
        for(col = 0; col < n; col++) printf("%d ", m[lin][col]);
        printf("\n");
    }        

    return 0;
}