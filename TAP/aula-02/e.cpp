#include <iostream>

using namespace std;

bool procura(string s, char letra){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == letra) return true;
    }

    return false;
}


int main(){

    string original, sub;
    int max = 0, temp, i2;
    bool achou;

    cin >> original;
    cin >> sub;

    for(int i = 0; i < original.size(); i++){
        temp = 0;
        if(procura(sub , original[i])){
            i2 = i;
            achou = false;
            for(int c = 0; c < sub.size(); c++){
                if(original[i2] == sub[c]){
                    temp++;
                    i2++;
                    achou = true;
                }
                else{
                    if(achou){
                        break;
                    }
                }
            }
            cout << "Para a letra " << original[i] << ": " << temp << endl;
        }

        if(temp > max) max = temp;

        cout << original[i] << ": " << temp << endl;

    }

    cout << sub.size() - max << endl;

    return 0;
}