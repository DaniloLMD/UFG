#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    long atual, anterior;
    long superx = 0, supery = 0;
    vector<long int> eixos_x(n-1);
    vector<long int> eixos_y(m-1);
    cin >> anterior;
    for(int c = 0; c < eixos_x.size(); c++){
        cin >> atual;
        eixos_x[c] = atual - anterior;
        anterior = atual;
    }
    cin >> anterior;
    for(int c = 0; c < eixos_y.size(); c++){
        cin >> atual;
        eixos_y[c] = atual - anterior;
        anterior = atual;
    }

    for(int c = 0; c < eixos_x.size(); c++){
        superx = (superx + (eixos_x.size() - c)*(c + 1)*eixos_x[c]) % (1000000000+7);
    }

    for(int c = 0; c < eixos_y.size(); c++){
        supery = (supery + (eixos_y.size() - c)*(c+1)*eixos_y[c]) % (1000000000+7);
    }

    cout << (superx*supery) % (1000000000+7) << endl;

    return 0;
}