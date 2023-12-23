#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a, b;


    cin >> a >> b;
    double k = b + 3*a/2;
    double m = a*b/2;

    double x1 = (2*k + sqrt(4*k*k - 4*9*m)) / 18;
    double x2 = (2*k - sqrt(4*k*k - 4*9*m)) / 18;

    double v1 = 3*x1*x1*x1 - x1*x1*k + x1*m;
    double v2 = 3*x2*x2*x2 - x2*x2*k + x2*m;

    double v, x;
    if(v1 > v2){
        v = v1;
        x = x1;
    }
    else{
        v = v2;
        x = x2;
    }

    printf("%.8lf %.8lf", x, v);

    return 0;
}