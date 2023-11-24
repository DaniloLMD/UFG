#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main(){
    ll N, X, Y;

    cin >> N >> X >> Y;

    vector<ll> red(N, 0);
    vector<ll> blue(N,0);

    red[N-1] = 1;

    bool quebrar;
    while(1){
        
        quebrar = true;
        for(int i = 1; i < N; i++){
            if(red[i] > 0 || blue[i] > 0) quebrar = false; 
        }
        if(quebrar) break;
        
        for(int i = 1; i < red.size(); i++){
            blue[i] += X * red[i];
            red[i-1] += red[i];
            red[i] = 0;
        }

        for(int i = 1; i < blue.size(); i++){
            blue[i-1] += Y * blue[i];
            red[i-1] += blue[i];
            blue[i] = 0;
        }

    }


    cout << blue[0] << "\n";
    return 0;
}