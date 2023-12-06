#include <iostream>
#include <vector>
using namespace std;

int main(){
    unsigned long long int qtd;
    cin >> qtd;
    

    vector<string> v(qtd);
    vector<unsigned long long int> count(26, 0); //cada indice representa uma letra

    unsigned long long int res = 0;
    unsigned long long int m, a, r, c, h;

    for(int i = 0; i < qtd; i++){
        cin >> v[i];
        //count[v[i][0] - 'A']++;

        if(v[i][0] == 'M') m++;
        if(v[i][0] == 'A') a++;
        if(v[i][0] == 'R') r++;
        if(v[i][0] == 'C') c++;
        if(v[i][0] == 'h') h++;

    } 

    
    /*m = count['M'-'A'];
    a = count['A'-'A'];
    r = count['R'-'A'];
    c = count['C'-'A'];
    h = count['H'-'A'];*/

    res += m*a*r;
    res += m*a*c;
    res += m*a*h;
    res += m*r*c;
    res += m*r*h;
    res += m*c*h;

    res += a*r*c;
    res += a*r*h;
    res += a*c*h;

    res += r*c*h;

    cout << res << endl;  

    return 0;
}
