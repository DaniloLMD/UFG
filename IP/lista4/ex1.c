#include <stdio.h>
 
int main(){
    double m[2][2];
    double det = 0;
    int i, j;
 
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            scanf("%lf", &m[i][j]);
        }
    }
 
    det += (m[0][0] * m[1][1]) - (m[0][1]*m[1][0]);
 
   printf("%.2lf\n", det);
 
 
    return 0;
}
