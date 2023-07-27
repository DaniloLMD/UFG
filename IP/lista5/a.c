#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
typedef struct{
    double x, y, z, u, norma;
}ponto;
 
int main(){
    ponto *v;
    ponto temp;
    int qtd, c, c2;
    
    //lendo a quantidade de pontos
    scanf("%d", &qtd);
    v = (ponto*) malloc(qtd * sizeof(ponto));
    for(c = 0; c < qtd; c++){
        scanf("%lf %lf %lf %lf", &v[c].u, &v[c].x, &v[c].y, &v[c].z);
        v[c].norma = sqrt(pow(v[c].x,2) + pow(v[c].y,2) + pow(v[c].z,2) + pow(v[c].u,2));
    }
    //ordenando
    for(c = 0; c < qtd-1; c++){
        for(c2 = 0; c2 < qtd-1; c2++){
            if(v[c2].norma > v[c2+1].norma){
                temp.x = v[c2].x;
                temp.y = v[c2].y;
                temp.z = v[c2].z;
                temp.u = v[c2].u;
                temp.norma = v[c2].norma;
            
                v[c2].x = v[c2+1].x;
                v[c2].y = v[c2+1].y;
                v[c2].z = v[c2+1].z;
                v[c2].u = v[c2+1].u;
                v[c2].norma = v[c2+1].norma;
                
                v[c2+1].x = temp.x;
                v[c2+1].y = temp.y;
                v[c2+1].z = temp.z;
                v[c2+1].u = temp.u;
                v[c2+1].norma = temp.norma;
            }
        }
        
        //printando
        for(c = 0; c < qtd; c++){
            printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", v[c].u, v[c].x, v[c].y, v[c].z, v[c].norma);
        }
        
    }
    
 
 
    return 0;
}
