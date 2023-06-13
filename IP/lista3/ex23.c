#include <stdio.h>  

int main(){
    int q1, q2, c, t , ordem = 0, d;
    int v[100000];

    scanf("%d", &q1);
    scanf("%d", &q2);
    d = q1 + q2;

    for(c = 0; c < d; c++){
        scanf("%d", &v[c]);
    }

    while(1){
        for(c = 0; c < d - 1; c++){
            if(v[c] > v[c + 1]){
                t = v[c];
                v[c] = v[c+1];
                v[c+1] = t;
            }
            else if(v[c] <= v[c + 1]) ordem++;
        }
        if(ordem == (d - 1)) break;
        ordem = 0;
    }

    for(c = 0; c < q2 + q1; c++){
        printf("%d\n", v[c]);
    }

    return 0;
}