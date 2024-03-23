#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

int qtd_vetores = 10; //quantidade de vetores
int num_elementos = 1e1; //numero de elementos de cada vetor
int num_elementos_busca = 1e0; //numero de elementos a serem buscados(sequencialmente e binariamente)
long long int min_num = 1; //menor numero possivel que pode ser gerado aleatoriamente
long long int max_num = 1e12; //maior numero possivel que pode ser gerado aleatoriamente

int gera_aleatorio(); //funcao que gera um numero aleatorio entre o intervalo [min_num , max_num]

//algoritmos de busca
bool algoritmo_busca_binaria(vector<int> v, int valor, int left, int right, int* index); //O(n)
bool algoritmo_busca_sequencial(vector<int> v, int valor, int* index); //O(log(n) + O(n)), tempo da busca + o tempo de ordenacao pelo Counting Sort

//funcoes que chamam as buscas
int busca_binaria(vector<vector<int>> vetores, vector<int> vetor_busca);
int busca_sequencial(vector<vector<int>> vetores, vector<int> vetor_busca);

//funcoes de ordenacao
vector<int> CountingSort(vector<int> v); //O(n)


int main(){
    srand(time(NULL));

    time_t inicio, fim;
    double tempo;
    int achados;

    vector<vector<int>> vetores(qtd_vetores, vector<int>(num_elementos));

    time(&inicio);
    //gerando os vetores
    for(int i = 0; i < qtd_vetores; i++){
        for(int j = 0; j < num_elementos; j++){
            vetores[i][j] = gera_aleatorio();
        }
    }
    time(&fim);
    tempo = double((double)fim - (double)inicio);
    printf("Intervalo de numeros aleatorios: [%lld , %lld]\n", min_num, max_num);
    printf("Tempo para gerar %d vetores com %d numeros aleatorios: %.10lf segundos\n", qtd_vetores, num_elementos, tempo);

    //gerando os numeros a serem buscados
    time(&inicio);
    vector<int> vetor_busca(num_elementos_busca);
    for(int i = 0; i < num_elementos_busca; i++){
        vetor_busca[i] = gera_aleatorio();
    }
    time(&fim);
    tempo = double(fim - inicio);
    printf("Tempo para gerar vetor com %d numeros a serem buscados: %.10lf segundos\n", num_elementos_busca, tempo);

    printf("\n\n");

    time(&inicio);
    achados = busca_sequencial(vetores, vetor_busca);
    time(&fim);
    tempo = double(fim - inicio);
    printf("Tempo gasto pela busca sequencial em %d vetores de %d elementos: %.10lf segundos\n", qtd_vetores, num_elementos, tempo);
    printf("Numeros achados = %d\n", achados);
    printf("\n\n");

    printf("\n\n");
    time(&inicio);
    CountingSort(vetores[0]);
    time(&fim);
    tempo = double(fim - inicio);
    printf("Tempo gasto pelo Counting Sort para ordenar 1 vetor de %d elementos: %.10lf segundos\n", num_elementos, tempo);

    printf("\n");
    time(&inicio);
    for(int i = 0; i < qtd_vetores; i++){
        CountingSort(vetores[i]);
    }
    time(&fim);
    tempo = double(fim - inicio);
    printf("Tempo gasto pelo Counting Sort para ordenar %d vetores de %d elementos: %.10lf segundos\n", qtd_vetores,num_elementos, tempo);
    time(&inicio);
    achados = busca_binaria(vetores, vetor_busca);
    time(&fim);
    tempo = double(fim - inicio);
    printf("Tempo total (busca e ordenacao) gasto pela busca binaria em %d vetores de %d elementos: %.10lf segundos\n", qtd_vetores, num_elementos, tempo);
    printf("Numeros achados = %d\n", achados);


    return 0;   
}


//#######################     implementacao das funcoes       #######################################


int gera_aleatorio(){
    return (rand() % (max_num - min_num + 1) + min_num);
}

bool algoritmo_busca_sequencial(vector<int> v, int valor, int* index = NULL){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == valor){
            if(index) *index = i;
            return true;
        }
    }
    return false;
}

vector<int> CountingSort(vector<int> v){
    int max = min_num;

    for(int i = 0; i < v.size(); i++){
        if(v[i] > max)
            max = v[i];
    }

    vector<int> ordenado(v.size());
    vector<int> contador(max+1, 0);

    for(int i = 0; i < v.size(); i++){
        contador[v[i]]++;
    }

    for(int i = 1; i <= max; i++){
        contador[i] += contador[i-1];
    }

    for(int i = 0; i < v.size(); i++){
        ordenado[--contador[v[i]]] = v[i];
    }

    return ordenado;
}

bool algoritmo_busca_binaria(vector<int> v, int valor, int left, int right, int* index = NULL){
    if(left > right) return false;
    int meio = left + (right-left)/2; //(left + right)/2;
    if(v[meio] != valor && left >= right) return false;
    
    if(v[meio] == valor){
        if(index) *index = meio;
        return true;
    }

    else if(valor < v[meio]){
        right = meio - 1;
    }
    else if(valor > v[meio]){
        left = meio + 1;
    }

    return algoritmo_busca_binaria(v, valor, left, right, index);
}

int busca_sequencial(vector<vector<int>> vetores, vector<int> vetor_busca){
    int indice_aparicao;
    int quantidade_achados = 0;

    //busca sequencial  
    cout << "## BUSCA SEQUENCIAL ##\n";
    for(int j = 0; j < vetor_busca.size(); j++){
        //cout << "j = " << j << endl;
        for(int i = 0; i < vetores.size(); i++){
            //cout << " i = " << i << endl;
            if(algoritmo_busca_sequencial(vetores[i], vetor_busca[j], &indice_aparicao)){
                //cout << "Numero " << vetor_busca[j] << " encontrado no indice " << indice_aparicao  << " do vetor " << i+1 << endl;
                quantidade_achados++;
            }
            else{
                //cout << "Numero << " << vetor_busca[j] << " nao encontrado no vetor " << i << endl;
            }
        }
    }
    
    return quantidade_achados;
}
int busca_binaria(vector<vector<int>> vetores, vector<int> vetor_busca){
    int indice_aparicao;
    int quantidade_achados = 0;

    time_t a, b;
    double t;

    //busca binaria
    cout << "## BUSCA BINARIA ##\n";
    for(int j = 0; j < vetor_busca.size(); j++){
        //cout << "j = " << j << endl;
        for(int i = 0; i < vetores.size(); i++){
            vetores[i] = CountingSort(vetores[i]);

            if(algoritmo_busca_binaria(vetores[i], vetor_busca[j], 0, vetores[i].size() - 1, &indice_aparicao)){
                //cout << "Numero " << vetor_busca[j] << " encontrado no indice " << indice_aparicao  << " do vetor " << i+1 << endl;
                quantidade_achados++;
            }
            else{
                //cout << "Numero " << vetor_busca[j] << " nao encontrado no vetor " << i+1 << endl;
            }
        }
    }
    return quantidade_achados;
}