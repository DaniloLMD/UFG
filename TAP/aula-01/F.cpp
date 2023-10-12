#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

std::vector<int> pilha;

void dfs(vector<vector<int>> &matrix, vector<bool> &visited, int vertice, int ultimo) {
    if (visited[vertice]) {
        return;
    }

    visited[vertice] = true;

    pilha.push_back(vertice);

    if (vertice == ultimo) {
        for(int c = 0; c < pilha.size(); c++){
            if(c != 0){
                cout << ' ' << pilha[c];
            }else{
                cout << pilha[c];
            }
        }
    }

    for (int proximo: matrix[vertice]) {
        dfs(matrix, visited, proximo, ultimo);
    }

    if (not pilha.empty())
        pilha.pop_back();
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    n++;
    vector<vector<int>>matrix(n, vector<int>(0));
    vector<bool>estados(n);
    for(bool c: estados){
        c = false;
    }
    for(int c = 1; c < matrix.size() - 1; c++){
        int X, Y;
        cin >> X >> Y;
        matrix[X].push_back(Y);
        matrix[Y].push_back(X);
    }
    
    dfs(matrix, estados, x, y);

    cout << endl;

    return 0;
}