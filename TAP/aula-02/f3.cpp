#include <iostream>
using namespace std;

int main(){

    string original, sub;   
    long int tam, frequencia = 0, corretos = 0, i_sub = 0;


    cin >> original;
    cin >> sub;

    for(int i = 0; i < original.size(); i++){

        if(original[i] == sub[i_sub]){
            corretos++;
            i_sub++;
        }
        else{
            corretos = 0;
            i_sub = 0;
        }

        if(corretos == sub.size()){
            frequencia++;
            corretos--;
            i_sub--;

            if(i+1 != original.size()){
                if(sub[i_sub] == original[i+1]){
                    i_sub = 0;
                }
            }
        }
    }
    
    cout << frequencia << endl;
    return 0;
}