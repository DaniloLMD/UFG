#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    string palavra, padrao, temp;

    cin >> palavra;
    cin >> padrao;
    vector<string> matrix(palavra.size());
    temp = padrao;
    

    for(int i = 0; i + padrao.size() <= palavra.size(); i++){
        for(int i2 = 0; i2 < padrao.size(); i2++){
            temp[i2] = palavra[i+i2];
        }
        matrix[i] = temp;
        cout << i << ": " << matrix[i] << endl;
    }



    return 0;
}
