//copia a string 2 para a string 1
void str_copy(char* s1, char *s2);

//retorna o tamanho de uma string
int str_len(char* s);

//funcao que recebe 2 strings e retorna 1(V) ou 0(F) se elas sao iguais
int str_compare(char *s1, char *s2);

//consome o buffer do terminal
void consome_buffer(void);

//recebe uma string e realoca ela para o novo tamanho
char* realoca_str(int tamanho);