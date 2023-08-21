#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
typedef struct{
    double u, x, y, z;
}ponto;
 
void calc_dist(ponto a, ponto b){
    double distancia = 0;
    distancia += pow(a.u - b.u, 2) + pow(a.x - b.x, 2) + pow(a.y - b.y, 2)+ pow(a.z - b.z, 2);
    printf("%.2lf\n", sqrt(distancia));
}
 
int main(){
    ponto *v;
    int qtd, c, c2;
    
    scanf("%d", &qtd);
    v = (ponto*) malloc(qtd * sizeof(ponto));
    
    for(c = 0; c < qtd; c++){
        scanf("%lf %lf %lf %lf", &v[c].u, &v[c].x,&v[c].y, &v[c].z);
    }
    
    for(c = 0; c < qtd - 1; c++){
        calc_dist(v[c], v[c+1]);
    }
    
    
    return 0;
}
