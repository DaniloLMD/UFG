#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    string palavra, padrao, temp;
    int maior = 0, iguais;

    cin >> palavra;
    cin >> padrao;
    temp = padrao;
    

    for(int i = 0; i + padrao.size() <= palavra.size(); i++){
        iguais = 0;
        for(int i2 = 0; i2 < padrao.size(); i2++){
            if(palavra[i+i2] == padrao[i2]) iguais++;
        }

        if(iguais > maior) maior = iguais;
    }

    cout << padrao.size() - maior << endl;

    return 0;
}
