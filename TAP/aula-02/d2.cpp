#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void menor_str(string palavra){
    int tam = palavra.size();
    int i2, i_string;
    vector<int> z(tam); 

    string menor, temp;
    menor = temp = palavra;

    for(int i=1; i < tam; i++){

        i_string = 0;
        while(palavra[(i + z[i]) % tam] <= palavra[(i + z[i] + 1) % tam]){
           
            for(int c = i; i_string < tam; c++, i_string++){
                temp[i_string] = palavra[c % tam];
            }

            z[i]++; 
        }

        if( (temp < menor && temp.size() > 1)){
            menor = temp;
        }

        if(z[i] > 1){
            i2 = i+1;
            for(int c = z[i] - 1; c > 0 && i2 < tam; c--){
                z[i2++] = c;
            }
            if(i2 < tam) i = i2;
        }
    }

    cout << menor << endl;
}

void maior_str(string palavra){
    int tam = palavra.size();
    int i2, i_string;
    vector<int> z(tam); 

    string maior, temp;
    maior = temp = palavra;

    for(int i=1; i < tam; i++){

        i_string = 0;
        while(palavra[(i + z[i]) % tam] >= palavra[(i + z[i] + 1) % tam]){
           
            for(int c = i; i_string < tam; c++, i_string++){
                temp[i_string] = palavra[c % tam];
            }

            z[i]++; 
        }

        if( temp > maior ){
            maior = temp;
        }

        if(z[i] > 1){
            i2 = i+1;
            for(int c = z[i] - 1; c > 0 && i2 < tam; c--){
                z[i2++] = c;
            }
            if(i2 < tam) i = i2;
        }
    }

    cout << maior << endl;
}

int main(){
    string str;
    cin >> str;

    if(str.size() == 1){
        cout << str << endl;
        cout << str << endl;
        return 0;
    }

    menor_str(str);
    maior_str(str);

    return 0;
}

