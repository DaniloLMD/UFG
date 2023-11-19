#include <iostream>

// Função com parâmetro padrão
void exemploFuncao(int parametro = 10) {
    std::cout << "O valor do parâmetro é: " << parametro << std::endl;
}

int main() {
    // Chamada da função sem fornecer o valor do parâmetro
    exemploFuncao();  // Isso usará o valor padrão (10)

    // Chamada da função fornecendo um valor diferente para o parâmetro
    exemploFuncao(20);

    return 0;
}
