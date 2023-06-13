#include <stdio.h>

int main(){
    int qtd = 0, sena = 0, quina = 0, quadra = 0, c, t, c2;
    int aposta[6], resultado[6];

    for(c = 0; c < 6; c++){
        scanf("%d", &aposta[c]);
    }
    scanf("%d", &qtd);

    while(qtd--){
        for(c = 0; c < 6; c++){
            scanf("%d", &resultado[c]);
        }

        t = 0;
        for(c = 0; c< 6; c++){
            for(c2 = 0; c2 < 6; c2++){
                if(aposta[c] == resultado[c2]) t++;
            }
        }
        if (t == 6) sena++;
        else if(t == 5) quina++;
        else if (t == 4) quadra++;
    }

    if(sena == 0) printf("Nao houve acertador para sena\n");
    else printf("Houve %d acertador(es) da sena\n", sena);

    if(quina == 0) printf("Nao houve acertador para quina\n");
    else printf("Houve %d acertador(es) da quina\n", quina);

    if(quadra == 0) printf("Nao houve acertador para quadra\n");
    else printf("Houve %d acertador(es) da quadra\n", quadra);

    return 0;
}
