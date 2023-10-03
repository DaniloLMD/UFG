#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long int dx, dy; //delta x e y
    long int i_lx, i_mx, i_ly, i_my; //indices de limite e menor valor de X e Y
    long int area = 0;
    int qtd_x, qtd_y;

    cin >> qtd_x;
    cin >> qtd_y;

    vector<long int> x(qtd_x);
    vector<long int> y(qtd_y);


    for(int i = 0; i < qtd_x; i++){
        cin >> x[i];
    }
    
    for(int i = 0; i < qtd_y; i++){
        cin >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    //somando o maior retangulo
    dy = (y[qtd_y-1] - y[0]);
    dx = (x[qtd_x - 1] - x[0]);
    area += (dx * dy) % (1000000000 + 7);

    //somando os retangulos com Y constante e X variando
    dy = (y[qtd_y-1] - y[0]);
    i_mx = 0;
    

    while(1){
        i_lx = i_mx + 1;
        //avancando o limite
        while(1){

            dx = x[i_lx] - x[i_mx];
            area += (dx * dy) % (1000000000 + 7);
            
            i_lx++;
            if(i_mx == 0 && i_lx >= qtd_x - 1) break;
            else if(i_lx >= qtd_x) break;
        } 

        //avancando o minimo 
        i_mx++;
        if(i_mx >= qtd_x - 1) break;

    }

    //somando os retangulos com X constante e Y variando
    dx = (x[qtd_x - 1] - x[0]);
    i_my = 0;

    while(1){
        i_ly = i_my + 1;

        //avancando o limite
        while(1){

            dy = y[i_ly] - y[i_my];
            area += (dx * dy) % (1000000000 + 7);
 
            i_ly++;
            if(i_my == 0 && i_ly >= qtd_y - 1) break;
            else if(i_ly >= qtd_y) break;
        } 

        //avancando o minimo 
        i_my++;
        if(i_my >= qtd_y - 1) break;

    }

    //somando os retangulos com ambos X e Y variando
    i_my = 0;
    while(1){
        i_ly = i_my + 1;

        //avancando o limite de Y
        while(1){
            dy = y[i_ly] - y[i_my];
 
            //avancando x
            i_mx = 0;
            while(1){
                i_lx = i_mx + 1;

                //avancando o limite
                while(1){

                    dx = x[i_lx] - x[i_mx];
                    area += (dx * dy) % (1000000000 + 7);

                    i_lx++;
                    if(i_mx == 0 && i_lx >= qtd_x - 1) break;
                    else if(i_lx >= qtd_x) break;
                } 

                //avancando o minimo 
                i_mx++;
                if(i_mx >= qtd_x - 1) break;
            }
            
            i_ly++;
            if(i_my == 0 && i_ly >= qtd_y - 1) break;
            else if(i_ly >= qtd_y) break;
        } 

        //avancando o minimo de Y
        i_my++;
        if(i_my >= qtd_y - 1) break;
    }

    area = area % (1000000000 + 7);

    cout << area << endl;


    return 0;
}
