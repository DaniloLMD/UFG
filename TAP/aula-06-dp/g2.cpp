#include <bits/stdc++.h>

using namespace std;

const int max_saque = (int) 1e4 + 10;
const int max_notas = 60;

int N;
int usados[max_notas];
int notas[max_notas][2];
int dp[max_saque][max_notas][max_notas];

/*
    saque = valor a ser sacado
    N = quantidade de notas
    nota_atual = nota atual
    dp = matriz 3d para evitar calculos ja feitos
    notas = matriz 2d em que [0] representa o valor e [1] representa a quantia total
    usados = vetor que conta quantas vezes ja usou cada nota
*/
int banco(int saque, int nota_atual){

    if(saque == 0) return 1; //conseguiu chegar no valor sem troco
    if(saque < 0) return 0; //ultrapassou o valor
    if(nota_atual >= N) return 0; //a nota atual nao esaqueiste

    //ja calculou o valor atual
    if(dp[saque][nota_atual][usados[nota_atual]] != -1){
        return dp[saque][nota_atual][usados[nota_atual]];
    }

    //ainda tem mais notas da mesma para usar
    if(usados[nota_atual] < notas[nota_atual][1]){
        //calcula novamente com +1 da nota atual
        usados[nota_atual]++;
        if(banco(saque - notas[nota_atual][0], nota_atual)){
            return dp[saque][nota_atual][usados[nota_atual]+1] = 1;
        }
        //volta pro calculo anterior(atual)
        usados[nota_atual]--;
    }

    //calcula com a proxima nota,   se funcionou, guarda o calculo como dando certo
    if(banco(saque, nota_atual+1)){
        return dp[saque][nota_atual][usados[nota_atual]] = 1;
    }
    //se nao, guarda o calculo da proxima nota como dando errado
    return dp[saque][nota_atual][usados[nota_atual]] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;

    cin >> N >> X;

    for(int i = 0; i <= X; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k < max_notas; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        cin >> notas[i][0] >> notas[i][1];
    }

    if(banco(X, 0)) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}