#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double h, c, l;

    cin >> h >> c >> l;

    double d1 = sqrt(pow(l+2*h, 2) + c*c);
    double d2 = sqrt(l*l + pow(c+2*h, 2));
    double d3 = sqrt(pow(c+h,2) + pow(l+h,2));

    double d;

    d = min(d1, d2);
    d = min(d, d3);
     

    printf("%.4lf\n", d);
    return 0;
}