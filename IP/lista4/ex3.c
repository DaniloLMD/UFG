#include <stdio.h>

int potDez(int a){
    if(a == 0) return 1;
    else return 10 * potDez(a-1);
}

double fracao(char *t){
    double res;
    int c, c1, c2, c3, num1 = 0, num2 = 0;
    char n1[50], n2[50];

    for(c = 0; c < 50; c++) n1[c] = n2[c] = 0;

    for(c = 0; t[c] != '/'; c++){
        n1[c] = t[c] - '0';
    }
    c2 = c - 1;
    for(c1 = 0; c1 < c; c1++){
        num1 += n1[c1] * potDez(c2);
        c2--;
    }
    
    c1 = 0;
    for(c3 = c + 1; t[c3] != ' ' && t[c3] != '\0'; c3++){
        n2[c1] = t[c3] - '0';
        c1++;
    }
    
    c2 = c1 - 1;
    for(c1 = 0; n2[c1] != '\0'; c1++){
        num2 += n2[c1] * potDez(c2);
        c2--;
    }

    res = (double) num1 / num2;
    return res;
}

int main(){
    int qtd, n, c, c1, cont1, cont2, indice, indice2, caso = 1, teveEquivalente;
    double res1, res2;
    char t[50], f1[50], f2[50], x;

    scanf("%d%*c", &qtd);

    while(qtd--){

        scanf("%d%*c", &n);
        scanf("%[^\n]%*c", t);

        printf("Caso de teste %d\n", caso);
        caso++;

        indice = 0;
        teveEquivalente = 0;
        for(cont1 = 0; cont1 < n; cont1++){

            for(c1 = 0; c1 < 50; c1++) f1[c1] = 0;       

            c1 = 0;
            for(c = indice; t[c] != '\0' && t[c] != ' '; c++){
                //if(c >= 50) break;
                f1[c1] = t[c];
                c1++;
            }

            indice = indice2 = c + 1;
            res1 = fracao(f1);
            
            for(cont2 = cont1 + 1; cont2 < n; cont2++){

                for(c1 = 0; c1 < 50; c1++) f2[c1] = 0;       
                c1 = 0;
                for(c = indice2; t[c] != ' ' && t[c] != '\0'; c++){
                    //if(c >= 50) break;
                    f2[c1] = t[c];
                    c1++;
                }
                indice2 = c + 1;
                res2 = fracao(f2);
                if(res2 == res1){
                    printf("%s equivalente a %s\n", f1, f2);
                    teveEquivalente = 1;
                }
            }
        }
        if(!teveEquivalente) printf("Nao ha fracoes equivalentes na sequencia\n");
    }
    return 0;
}