#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

int main(){
    long double h, c, l, soma;
    long double d1, d2, d3, d4;
    cin >> h >> c >> l;


    d1 = sqrt((l+2*h)*(l+2*h) + c * c);
    d2 = sqrt(l*l + (c+2*h)*(c+2*h));
    d3 = sqrt((c+h) * (c+h) + (l+h)*(l+h));
    d4 = c+l;

    //cout << min(d1, min(d2, d3)) << endl;
    long double d = min(d1, min(d2,min(d3,d4)));
    printf("%.4Lf", d);

    return 0;
}