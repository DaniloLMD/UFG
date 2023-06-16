#include <stdio.h>
 
int main(){
    int letras = 0, vogais = 0, consoantes = 0, n, c;
    char v[10000];
 
    scanf("%d%*c", &n);
 
    while(n--){
        scanf("%[^\n]%*c", v);
 
        for(c = 0; v[c] != '\0'; c++){
            if(v[c] >= 'A' && v[c] <= 'Z' || v[c] >= 'a' && v[c] <= 'z'){
                letras++;
                if(v[c] == 'A' || v[c] == 'E' || v[c] == 'I' || v[c] == 'O' ||
                v[c] == 'U' || v[c] == 'a' || v[c] == 'e' || v[c] == 'i' || v[c] == 'o' || v[c] == 'u') vogais++;
                else consoantes++;
            }
        }
        printf("Letras = %d\n", letras);
        printf("Vogais = %d\n", vogais);
        printf("Consoantes = %d\n", consoantes);
        letras = 0;
        vogais = 0;
        consoantes = 0;
    }
 
}
