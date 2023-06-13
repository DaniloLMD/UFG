#include <stdio.h>

#define N 128 + 1
/**
2 * @param str string de entrada
3 * printar o código ASCII de cada caracter da str
4 */
void print_codes( char * str ){
    int c;
    for(c = 0; str[c] != '\0'; c++){
        printf("%d", str[c]);
        if(str[c + 1] != '\0') printf(",");
    }
    printf("\n");
}
 

/**
2 * @param str vetor de caracteres onde a string lida será gravada
3 * @param n quantidade máxima de caracteres a ser lidos
4 * @return quandidade de caracteres lidos
5 * precisa ser colocado o '\0' no final!!
6 */
int le_string( char * str, int n ){
    char lixo[N];
    int c, j = 0;

    for(c = 0; ; c++){
        scanf("%c", &lixo[c]);
        if(lixo[c] == '\n'){
            if(c == 0){
                lixo[c] = 'g';
                c = -1;
            }
            else{
                j = c;
                break; 
            }
        }
    }
    for(c = 0; c < n; c++){
        if(c == j) break;
        str[c] = lixo[c];
    }
    if(n > j) str[j] = '\0';
    else str[n] = '\0';
    return c-1;
}

int main(){
    char str[N], s[N];
    char c;
    int i;

    //x & texto 123
    scanf("%c", &c);
    le_string(str, 3);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);

    //abcdef
    scanf("%c", &c);
    le_string(str, 5);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);

    //x y z h w
    scanf("%c", &c);
    le_string(str, 5);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);

    //99 & texto com espacos
    scanf("%d", &i);
    le_string(str, 3);
    print_codes(str);
    printf("inteiro:%d, str:%s\n", i, str);

    //printf("Digite inteiros separados por espaco: ");
    scanf("%d", &i);
    //printf("inteiro:%d\n", i);
    //printf("Le string (15):\n");
    le_string(str, 15);
    print_codes(str);
    printf("inteiro:%d, str:%s\n", i, str);

    //printf("Digite uma string sem espacos: ");
    scanf("%s", s);
    //printf("string:%s\n", str);
    //printf("Le string (10):\n");
    le_string(str, 100);
    print_codes(str);
    printf("string:%s, str:%s\n", s, str);

    //printf("Digite uma string com espacos: ");
    scanf("%s", s);
    //printf("string:%s\n", str);
    //printf("Le string (20):\n");
    le_string(str, 100);
    print_codes(str);
    printf("string:%s, str:%s\n", s, str);
    return 0;
}