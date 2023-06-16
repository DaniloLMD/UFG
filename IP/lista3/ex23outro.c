#include <stdio.h>
#include <stdlib.h>

void ordena(int *v, int tamanho){
    int c, d , t;
    while(1){
        d = 0;
        for(c = 0; c < tamanho - 1; c++){
           if(v[c] > v[c+1]){
                t = v[c];
                v[c] = v[c+1];
                v[c+1] = t;
            }
            else d++;
        }
        if(d == tamanho - 1) break;
    }
}

int main(){
    int q1, q2, c, a = 0, b = 0;
    int *p1, *p2, *p;
    
    scanf("%d", &q1);
    scanf("%d", &q2);

    p1 = (int*) malloc(q1 * sizeof(int));
    p2 = (int*) malloc(q2 * sizeof(int));
    p = (int*) malloc((q1+q2) * sizeof(int));

    for(c = 0; c < q1; c++) scanf("%d", &p1[c]);
    for(c = 0; c < q2; c++) scanf("%d", &p2[c]);

    ordena(p1, q1);
    ordena(p2, q2);
    
    for(c = 0; c < q1 + q2; c++){
        if(p1[a] <= p2[b] && a < q1){
            p[c] = p1[a];
            a++;
        }
        else if(b < q2){
            p[c] = p2[b];
            b++;
        }
        else{
            p[c] = p1[a];
            a++;
        }
        printf("%d\n", p[c]);
    }
    return 0;
}