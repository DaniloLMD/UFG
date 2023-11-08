#include <vector>
#include <iostream>

using namespace std;

void build_crivo_div(vector<int> &primos, int limite){
    for(int c = 2; c * c <= limite; c++){
        if(primos[c] == 1){
            for(int d = c * c; d <= limite; d += c){
                if(primos[d] < 2){
                    primos[d] = c;
                }
            }
        }
    }
}

int menor_primo(vector<int> &primos,int num){
    if(primos[num] > 1){
        return primos[num];
    }else{
        return num;
    }
}

vector<int> fatores_primos(vector<int> &primos, int num){
    vector<int> retorno;
    if(num <= 1){
        return {0};
    }else {
        while(num > 1){
            int divisor_atual = menor_primo(primos, num);
            int res = 0;
            while(menor_primo(primos, num) == divisor_atual){
                res++;
                num /= divisor_atual;
            }
            retorno.push_back(res);
        }
    }
    return retorno;
}

int divisores(vector<int> fatores){
    int resultado = 1;
    for(int c = 0; c < fatores.size(); c++){
        fatores[c]++;
        resultado *= fatores[c];
    }
    return resultado;
}

int gdc(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gdc(b, a % b);
    }
}

int qtd_div(int num){
    int k = 0;
    for(int c = 1; c * c <= num; c++){
        if(num % c == 0){
            k++;
            if(num / c != c){
                k++;
            }
        }   
    }
    return k;
}

int main(){
    int n, num_limite = 1e6 + 1;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    vector<int> primeiros_div_primos(num_limite, 1);
    build_crivo_div(primeiros_div_primos, num_limite);
    
    for(;n > 0; n--){
        int checa1, checa2;
        cin >> checa1 >> checa2;
        //cout << divisores(fatores_primos(primeiros_div_primos, gdc(checa1, checa2))) << '\n';
        cout << qtd_div(gdc(checa1, checa2)) << '\n';
    }
    
    return 0;
}