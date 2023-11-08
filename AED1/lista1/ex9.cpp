//questao 9
#include <iostream>

void hanoi(int qtd, char O, char D, char A){
    if(qtd == 1){
        printf("(%c,%c)\n", O, D);
        return;
    }

    hanoi(qtd-1, O, A, D);
    printf("(%c,%c)\n", O, D);

       
    hanoi(qtd-1, A, D, O);
}

int main(){
    int qtd;

    std::cin >> qtd;
    hanoi(qtd, 'O', 'D', 'A');
    return 0;
}