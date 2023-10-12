#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maior_seq(string palavra){
    int index_maior_seq = 0, tam = palavra.size();
    int contador = 0;
    int i2, i_max, i_temp;
    vector<int> z(tam); 

    i_max = 0;
    for(int i=0; i < tam - 1; i++){
        while(i + z[i] + 1 < tam && palavra[i + z[i]] <= palavra[i + z[i] + 1]){
            z[i]++; 
        }

        if(z[i] > z[i_max]) i_max = i;

        if(z[i] > 1){
            i2 = i+1;
            for(int c = z[i] - 1; c > 0 && i2 < tam; c--){
                z[i2++] = c;
            }
            if(i2 < tam) i = i2;
        }
    }

    i2 = tam-1;
    i_temp = tam-1;
    //procurando a seq do final pro comeco
    for(int i = 0; i < tam; i++){
        if(palavra[i2] <= palavra[i]){
            z[i_temp]++;
            i2 = i;
        }
        else{
            break;
        }    
    } 

    if(z[i_temp] > z[i_max]) i_max = i_temp;

    cout << "Z na seq: ";
    for(int i: z){
        cout << i << " ";
    }
    cout << endl;


    return i_max;
}

int maior_seq2(string palavra){
    int index_maior_seq = 0, tam = palavra.size();
    int contador = 0;
    int i2, i_max, i_temp;
    vector<int> z(tam); 

    i_max = 0;
    for(int i=0; i < tam; i++){
        while(i + z[i] + 1 < tam && palavra[i + z[i]] >= palavra[i + z[i] + 1]){
            z[i]++; 
        }

        if(z[i] > z[i_max]) i_max = i;

        if(z[i] > 1){
            i2 = i+1;
            for(int c = z[i] - 1; c > 0 && i2 < tam; c--){
                z[i2++] = c;
            }
            if(i2 < tam) i = i2;
        }
    }

    i2 = tam-1;
    i_temp = tam-1;
    //procurando a seq do final pro comeco
    for(int i = 0; i < tam; i++){
        if(palavra[i2] >= palavra[i]){
            z[i_temp]++;
            i2 = i;
        }
        else{
            break;  
        }       
    } 
    
    if(z[i_temp] > z[i_max]) i_max = i_temp;

    cout << "Z na seq2: ";
    for(int i: z){
        cout << i << " ";
    }
    cout << endl;

    return i_max;

    /*    .
        aaba

        ba
        ba aa
    */
}
/*
void ordema_z(string palavra){
    string nova = palavra;
    int tamanho = palavra.size(), index_f = palavra.size() - 1;
    char primeiro, ultimo;
    for(int c = 0; c < nova.size(); c++){
        if(nova[0] > nova[]){

        }
    }

} 
*/
int main(){
    string str, nova;
    cin >> str;

    int index = maior_seq(str), controle = 0;
    for(int c = index; 1==1; c++){
        cout << str[c % str.size()];
        controle++;
        if(controle == str.size()) break;
    }
    cout << endl;


    index = maior_seq2(str);
    cout << "index da seq2 = " << index << ", letra = " << str[index] << endl;
    cout << "str[str.size() - 1] = " << str[str.size() - 1] << endl;
    controle = 0;
    for(int c = index; 1==1; c++){
        cout << str[c % str.size()];
        controle++;
        if(controle == str.size()) break;
    }
    cout << endl;


    return 0;
}

