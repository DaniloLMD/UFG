#include "list.h"

struct no{
    int key;
    int data;
    Node next;
    Node prev;
};

struct list{
    Node begin;
    Node end;
    int size;
};

//cria e retorna um novo nó
Node Node_new(int data, int key){
    Node new_node = (Node) malloc(sizeof(struct no));
    new_node->data = data;
    new_node->key = key;
    new_node->next = new_node->prev = NULL;
}

bool Lista_new(List* l_ref){
    List new_list = (List) malloc(sizeof(struct list));
    if(new_list == NULL)
        return false;

    new_list->size = 0;
    new_list->begin = NULL;
    new_list->end = NULL;
    *l_ref = new_list;
    return true;
}

bool Lista_delete(List* l_ref){
    if(l_ref == NULL)
        return false;

    List l = *l_ref;
    Node node_atual = l->begin; 
    Node node_anterior;
    while(node_atual != NULL){
        node_anterior = node_atual;
        node_atual = node_atual->next;
        free(node_anterior);
    }
    
    free(l);
    *l_ref = NULL;
    return true;
}

bool Lista_push_front(List l, int valor, int chave){
    Node new_node = Node_new(valor, chave);

    if(new_node == NULL)
        return false;

    if(l->size == 0){
        l->begin = l->end = new_node;
    }
    else{
        new_node->next = l->begin;
        l->begin->prev = new_node;
        l->begin = new_node;
    }

    l->size++;
    return true;
}

bool Lista_push_back(List l, int valor, int chave){
    Node new_node = Node_new(valor, chave);

    if(new_node == NULL)
        return false;

    if(l->size == 0){
        l->begin = new_node;
    }
    else{
        l->end->next = new_node;
    }

    new_node->prev = l->end;
    l->end = new_node;
    l->size++;
    return true;
}

bool Lista_push_ordered(List l, int valor, int chave){
    Node new_node = Node_new(valor, chave);

    if(new_node == NULL)
        return false;

    if(l->size == 0){
        l->begin = l->end = new_node;
    }

    else{
        Node atual = l->begin;
        while(atual != NULL){
            if(atual->data >= valor){

                if(atual == l->begin){
                    new_node->next = l->begin;
                    l->begin->prev = new_node;
                    l->begin = new_node;
                }
                else{
                    new_node->next = atual;
                    new_node->prev = atual->prev;
                    atual->prev->next = new_node;
                    atual->prev = new_node;
                }

                break;
            }
            atual = atual->next;
        }
        if(atual == NULL){
            new_node->prev = l->end;
            l->end->next = new_node;
            l->end = new_node;
        }
    }

    l->size++;
    return true;
}


void Lista_print(List l){
    Node atual = l->begin;
    int i = 0;

    printf("Tamanho: %d\n", l->size);
    printf("    key      data\n");
    while(atual != NULL){
        printf("%d:  %d\t  ,  %d \n", ++i, atual->key, atual->data);
        atual = atual->next;
    }
}

void Lista_reverse_print(List l){
    Node atual = l->end;
    int i = l->size;

    printf("Tamanho: %d\n", l->size);
    printf("    key      data\n");
    while(atual != NULL){
        printf("%d:  %d\t  ,  %d \n", i--, atual->key, atual->data);
        atual = atual->prev;
    }
}

bool Lista_pop_front(List l){
    if(l->size == 0)
        return false;
    
    Node inicio = l->begin;
    

    l->begin = l->begin->next;
    if(l->begin != NULL)
        l->begin->prev = NULL;
    l->size--;
    
    free(inicio);

    if(l->size == 0)
        l->end = NULL;
    
    return true;
}

bool Lista_pop_back(List l){
    if(l->size == 0)
        return false;

    Node final = l->end;
    l->end = l->end->prev;
    if(l->end != NULL)
        l->end->next = NULL;

    free(final);

    l->size--;
    if(l->size == 0)
        l->begin = NULL;
}

bool Lista_pop_key(List l, int key){
    Node atual = l->begin;

    while(atual != NULL){

        if(atual->key == key){

            //lista com apenas um elemento
            if(l->begin == l->end){
                l->begin = l->end = NULL;
            }
            
            //elemento no inicio
            else if(atual == l->begin){
                atual->next->prev = NULL;
                l->begin = atual->next;
            }
            
            //elemento no fim
            else if(atual == l->end){
                atual->prev->next = NULL;
                l->end = atual->prev;
            }
            //elemento no meio
            else{
                atual->next->prev = atual->prev;
                atual->prev->next = atual->next;
            }

            free(atual);
            l->size--;

            return true;
        }

        atual = atual->next;
    }


    return false;
}

bool Lista_concat(List l1, List l2){
    if(l2 == NULL)
        return false;

    if(l2->size == 0)
        return false;
    
    Node atual = l2->begin;
    while(atual != NULL){
        Lista_push_back(l1, atual->data, atual->key);
        atual = atual->next;
    }

    return true;
}