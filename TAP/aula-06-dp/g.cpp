#include <bits/stdc++.h>

using namespace std;

#define ll long long

/*
    saque = valor a ser sacado
    N = quantidade de notas
    nota_atual = nota atual
    dp = matriz 3d para evitar calculos ja feitos
    notas = matriz 2d em que [0] representa o valor e [1] representa a quantia total
    usados = vetor que conta quantas vezes ja usou cada nota
*/
int banco(int saque, int N, int nota_atual, vector<vector<vector<int>>>& dp, vector<vector<int>>& notas, vector<int>& usados){

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
        if(banco(saque - notas[nota_atual][0], N, nota_atual, dp, notas, usados)){
            return dp[saque][nota_atual][usados[nota_atual]+1] = 1;
        }
        //volta pro calculo anterior(atual)
        usados[nota_atual]--;
    }

    //calcula com a proxima nota,   se funcionou, guarda o calculo como dando certo
    if(banco(saque, N, nota_atual+1, dp, notas, usados)){
        return dp[saque][nota_atual][usados[nota_atual]] = 1;
    }
    //se nao, guarda o calculo da proxima nota como dando errado
    return dp[saque][nota_atual][usados[nota_atual]] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;

    cin >> N >> X;

    //notas[0] = valor ; notas[1] = quantidade
    vector<vector<int>> notas(N, vector<int>(2)); //guarda o valor da nota e a quantidade total

    vector<int> usadas(N, 0); //guarda a quantidade de notas que ja utilizou da nota i, 0 < i < N

    //  matriz 3d: saque - numero de notas - notas usadas, tudo inicializado em -1
    vector<vector<vector<int>>> dp(X, vector<vector<int>>(N, vector<int>(N, -1)));

    for(int i = 0; i < N; i++){
        cin >> notas[i][0] >> notas[i][1];
    }

    if(banco(X, N, 0, dp, notas, usadas)) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}