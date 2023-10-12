#include <iostream>

using namespace std;

int main(){

    string str, temp, maior, menor;
    int i2;

    cin >> str;
    temp = maior = menor = str;

    for(int c = 1; c < str.size(); c++){
        i2 = 0;
        for(int i = c; i2 < str.size(); i++, i2++){
            temp[i2] = str[i % str.size()];
        }

        if(temp < menor) menor = temp;
        
        if(temp > maior) maior = temp;

    }

    cout << menor << endl << maior << endl;

    return 0;
}