#include <stdio.h>
#include <stdlib.h>
 
typedef struct{
    int *pessoas;
    int *consumos;
    int qtd_imov;
    int tot_pessoas;
    int tot_consumo;
    double consumo_medio;
}    cidade;
 
//recebe um vetor inteiro e remove o indice atual dele
void remover(int *v, int indice, int tamanho){
    int c;
    for(c = indice; c < tamanho - 1; c++){
        v[c] = v[c+1];
    }
    v = realloc(v, (tamanho - 1) * sizeof(int));
}
 
int main(){
    int c, c2, qtd_imoveis, qtd_cidades = 0, i;
    cidade *v;
    int t;
    int consumo, consumo2;
    while(1){
        //lendo quantos imoveis tem na cidade atual
        scanf("%d", &qtd_imoveis);
        if(qtd_imoveis == 0) break;
        //atualizando a quantidade de cidades
        qtd_cidades++;
        i = qtd_cidades - 1;
        //realocando o vetor conforme o numero de cidades aumenta
        v = realloc(v, qtd_cidades * sizeof(cidade));
        //alocando os vetores de pessoas e consumos
        v[i].pessoas = (int*) malloc(qtd_imoveis * sizeof(int));
        v[i].consumos = (int*) malloc(qtd_imoveis * sizeof(int));
        
        //lendo quantidade de pessoas e consumo de cada imovel
        v[i].qtd_imov = qtd_imoveis;
        v[i].tot_pessoas = 0;
        v[i].tot_consumo = 0;    
        for(c = 0; c < qtd_imoveis; c++){
            scanf("%d %d", &v[i].pessoas[c], &v[i].consumos[c]); 
            //calculando o tot_pessoas e o tot_consumo
            v[i].tot_pessoas += v[i].pessoas[c];
            v[i].tot_consumo += v[i].consumos[c];
        }
    
        //calculando o consumo medio da cidade
        v[i].consumo_medio = (double) v[i].tot_consumo / v[i].tot_pessoas;
    }
    
    //printando
    for(c = 0; c < qtd_cidades; c++){
        if(c != 0){
            printf("\n");
        }
    
        //verificando se tem algum imovel com consumo igual
        for(c2 = 0; c2 < v[c].qtd_imov; c2++){
            for(i = c2 + 1; i < v[c].qtd_imov; i++){
                consumo = v[c].consumos[c2] / v[c].pessoas[c2];
                consumo2 = v[c].consumos[i] / v[c].pessoas[i];
                //se achou imoveis com consumo igual, junta as pessoas e o consumo total
                if(consumo == consumo2){
                    v[c].pessoas[c2] += v[c].pessoas[i];
                    v[c].consumos[c2] += v[c].consumos[i];
                    //removendo o imovel
                    remover(v[c].pessoas, i, v[c].qtd_imov);
                    remover(v[c].consumos, i, v[c].qtd_imov);
                    v[c].qtd_imov--;
                    i--;
                }
                
            }
        }
    
        //ordenando em ordem crescente o consumo
        for(c2 = 0; c2 < v[c].qtd_imov; c2++){
            for(i = 0; i < (v[c].qtd_imov - 1); i++){
                consumo = v[c].consumos[i] / v[c].pessoas[i];
                consumo2 = v[c].consumos[i+1] / v[c].pessoas[i+1];
                //realizando as trocas
                if(consumo2 < consumo){
                    //trocando os consumos
                    t = v[c].consumos[i];
                    v[c].consumos[i] = v[c].consumos[i+1];
                    v[c].consumos[i+1] = t;
                    
                    //trocando as pessoas
                    t = v[c].pessoas[i];
                    v[c].pessoas[i] = v[c].pessoas[i+1];
                    v[c].pessoas[i+1] = t;
                }
            }
        }
        
        
        printf("Cidade# %d:\n", c+1);
        for(c2 = 0; c2 < v[c].qtd_imov; c2++){
            consumo = v[c].consumos[c2] / v[c].pessoas[c2];
            printf("%d-%d",v[c].pessoas[c2], consumo);
            if(c2+1 != v[c].qtd_imov) printf(" ");
        }
        printf("\n");
        printf("Consumo medio: %.2lf m3.", v[c].consumo_medio);
        if(c + 1 != qtd_cidades) printf("\n");    
    }
    
    return 0;
}
