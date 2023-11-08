//questao 14
#include <iostream>
#include <vector>
#include <list>


/*          Arvore        */
typedef struct _tree_node TreeNode;
typedef struct _tree Tree;

struct _tree_node{
    TreeNode **filhos;
    bool visitado;
    int val;
    int qtd_filhos;
};

struct _tree{
    TreeNode* inicio;
};


//cria uma arvore
Tree* Tree_create(void);
//destroi uma arvore
void Tree_destroy(Tree** T_ref);
//cria um node de tree
TreeNode* TreeNode_create(int val);
//destroi um node de tree
void TreeNode_destroy(TreeNode** Tnode_ref);
//liga um nó filho com o nó pai
void TreeNode_link(TreeNode* pai, TreeNode* filho);

Tree* Tree_create(){
    Tree* new_tree = (Tree*) malloc(1 * sizeof(Tree));
    new_tree->inicio = NULL;
    return new_tree;
}

TreeNode* TreeNode_create(int val){
    TreeNode* new_node = (TreeNode*) malloc(1 * sizeof(TreeNode));

    new_node->val = val;
    new_node->visitado = 0;
    new_node->filhos = NULL;
    new_node->qtd_filhos = 0;

    return new_node;
}

void TreeNode_link(TreeNode* pai, TreeNode* filho){
    pai->qtd_filhos++;

    pai->filhos = (TreeNode**) realloc(pai->filhos, pai->qtd_filhos * sizeof(TreeNode*));

    pai->filhos[pai->qtd_filhos-1] = filho;
}




/*              DOUBLY LINKED LIST                              */
typedef struct _doubly_node DNode;
typedef struct _doubly_linked_list LinkedList;

struct _doubly_node{
    int val; 
    struct _doubly_node* next;
    struct _doubly_node* prev;
};

struct _doubly_linked_list{
    struct _doubly_node* begin;
    struct _doubly_node* end;
    unsigned long int size;
};

//cria e retorna um nó duplo
DNode* DNode_create(int val);

//cria uma linked list dupla
LinkedList* LinkedList_create(void);
//destroi uma linked list dupla
void LinkedList_destroy(LinkedList** L_ref);
//adiciona um elemento no final de uma lista
void LinkedList_addLast(LinkedList* L, int val);
//printa os valores de uma linked list
void LinkedList_print(const LinkedList* L);
//retorna o tamanho da lista
unsigned long int LinkedList_size(const LinkedList* L); 
//verifica se a lista esta vazia e retorna True(vazia) ou False(nao vazia)
bool LinkedList_empty(LinkedList* L);
//remove o ultimo elemento da lista
void LinkedList_removeLast(LinkedList* L);


DNode* DNode_create(int val){
    DNode* new_node = (DNode*) malloc(1 * sizeof(DNode));

    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

LinkedList* LinkedList_create(void){
    LinkedList* new_list = (LinkedList*) malloc(1 * sizeof(LinkedList));

    new_list->size = 0;
    new_list->begin = NULL;
    new_list->end = NULL;

    return new_list;
}

void LinkedList_destroy(LinkedList** L_ref){
    LinkedList* L = *L_ref;

    DNode* node_atual = L->begin;
    DNode* node_anterior = NULL;
    while(node_atual != NULL){
        node_anterior = node_atual;
        node_atual = node_atual->next;
        free(node_anterior);
    }

    free(L);
    *L_ref = NULL;
}

void LinkedList_addLast(LinkedList* L, int val){
    DNode* new_node = DNode_create(val);

    new_node->prev = L->end;
    if(LinkedList_empty(L)){
        L->begin = new_node;
    }
    else{
        L->end->next = new_node;
    }

    L->end = new_node;
    L->size++;
}

void LinkedList_removeLast(LinkedList* L){

    //a lista ja esta vazia
    if(LinkedList_empty(L)) return;

    //a lista so tem um elemento
    if(L->size == 1){
        free(L->end);
        L->begin = NULL;
        L->end = NULL;
        return;
    }

    //a lista tem mais de um elemento
    DNode* atual = L->end;
    L->end = L->end->prev;
    L->end->next = NULL;

    free(atual);
    L->size--;
}

void LinkedList_print(const LinkedList* L){

    if(L == NULL){
        return;
    }

    DNode *node_atual = L->begin;

    while(node_atual != NULL){  
        if(node_atual == L->begin) printf("%d", node_atual->val);
        else printf(" %d", node_atual->val);
        node_atual = node_atual->next;
    }
}

unsigned long int LinkedList_size(const LinkedList* L){
    return L->size;
}

bool LinkedList_empty(LinkedList* L){
    return L->size == 0;
}










































using namespace std;

int maior_xor = 0, k;
vector<int> valores(0);


int main(){

    int tam, t;

    cin >> tam >> k;

    for(int i = 0; i < tam; i++){
        cin >> t;
        valores.push_back(t);
    }

    Tree* arvore = Tree_create();
    TreeNode* new_node;

    //criando a raiz
    for(int i = 0; i < tam; i++){
        new_node = TreeNode_create(valores[i]);
        TreeNode_link(arvore->inicio, new_node);
    }
    
    //montando a arvore
    for(int i = 0; i < tam; i++){
        for(int i2 = i+1; i2 < tam; i++){
            TreeNode_link(arvore->inicio->filhos[i], arvore->inicio->filhos[i2]);
        }
    }

    //percorrendo a arvore
    TreeNode* node_atual;
    int contador;
    for(int i = 0; i < tam; i++){
        node_atual = arvore->inicio->filhos[i];
        contador = 0;
        while(1){
            if(node_atual == NULL || contador == k){
                break;
            }

            
            node_atual = 

        }
    }



    return 0;
}