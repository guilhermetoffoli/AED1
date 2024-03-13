#include <stdlib.h>
#include "listafloat.h"

struct no{
    float info;
    struct no *prox;
};

/*
Operação: cria_lista()
    -Entrada: nenhuma.
    -Pré-condição: nenhuma.
    -Processo: Aloca um nó cabeçalho para a lista.
    -Saída: retorna o nó cabeçalho alocado.
    -Pós-condição: nenhuma.
*/

Lista cria_lista(){
    Lista cab;
    cab = (Lista) malloc(sizeof(struct no));
    if(cab != NULL){
        cab->prox = NULL;
        cab->info = 0; 
    }
    return cab; //se falhar retorna NULL
}

/*
Operação: lista_vazia
    -Entrada: Uma lista.
    -Pré-condição: Lista precisa ser instanciada.
    -Processo: Verifica se a lista está vazia.
    -Saída: 1 se é vazia e 0 se não.
    -Pós-condição: nenhuma
*/

int lista_vazia(Lista L) {
    if(L == NULL){
        return 1;
    }
    else
        return 0; 
}

/*
Operação: insere_ord
    -Entrada: O endereço de uma lista com o elemento a ser inserido.
    -Pré-condição: nenhuma.
    -Processo: Insere ordenadamente um elemento por meio de uma alocação a cada inserção.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: lista com o elemento inserido ordenadamente.
*/

int insere_ord (Lista *L, float elem) {
    Lista N = (Lista) malloc(sizeof(struct no));

    if (N == NULL)  return 0;  

    N->info = elem; 

    Lista aux = *L; 

    while (aux->prox != NULL && aux->prox->info > elem)
        aux = aux->prox; 
    
    N->prox = aux->prox;

    aux->prox = N;
    (*L)->info++;

    return 1;
}

/*
Operação: insere_ord_inter
    -Entrada: O endereço de uma lista a ser intercalada com os elemento a serem inseridos.
    -Pré-condição: nenhuma.
    -Processo: Insere os elementos intercalados na lista.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: lista com os elementos intercalados.
*/

int insere_inter (Lista *L, float elem) {
    Lista N = (Lista) malloc(sizeof(struct no));

    if (N == NULL)  return 0;  

    N->info = elem;

    Lista aux = *L;

    while (aux->prox != NULL && aux->prox->info > elem)
        aux = aux->prox;
    
    N->prox = aux->prox;

    aux->prox = N;

    return 1;
}

/*
Operação: remove_ord
    -Entrada: O endereço de uma lista e um elemento.
    -Pré-condição: Lista precisa ser instanciada e não pode estar vazia.
    -Processo: remove da lista o elemento selecionado.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Elemento selecionado removido da lista.
*/

int remove_ord (Lista *L, float elem) {
    if (lista_vazia(*L) == 1)
        return 0; 

    Lista aux = *L;

    while (aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;

    if (aux->prox == NULL || aux->prox->info > elem)
        return 0; 

    Lista aux2 = aux->prox; 

    aux->prox = aux2->prox; 
    
    free(aux2); 
    (*L)->info--;

    return 1;
}

/*
Operação: esvazia_lista
    -Entrada: Endereço de uma lista.
    -Pré-condição: Lista existir.
    -Processo: Remove elemento a elemento liberando a memória alocada por eles.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista vazia com a memória alocada por eles liberada.
*/

int esvazia_lista(Lista *L){
    if(L == NULL) return 0;

    while(*L != NULL){
        Lista aux = *L; 
        *L = aux->prox; 
        free(aux);
    }

    return 1;
}

/*
Operação: apaga_lista
    -Entrada: Endereço de uma lista.
    -Pré-condição: Lista existir.
    -Processo: Chama o esvazia_lista e remove elemento a elemento liberando a memória alocada por eles.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista vazia com a memória alocada por eles liberada.
*/

int apaga_lista(Lista *L){
    return (esvazia_lista(L));
}

/*
Operação: int get_elem_pos
    -Entrada: Uma lista, a posição do elemento e o endereço do elemento.
    -Pré-condição: Lista existir, não ser vazia, além de ter as posições válidas.
    -Processo: Pega o elemento da sua respectiva posição.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: o endereço do elemento com o valor da sua posição na lista.
*/

int get_elem_pos(Lista L, int pos, float *elem){
    if(lista_vazia(L) || pos <= 0) return 0;

    int cont = 1;
    Lista Aux = L;

    while (Aux->prox != NULL && cont < pos){
        Aux = Aux->prox;
        cont++;
    }
    if(cont != pos) return 0; 
    
    *elem = Aux->info;

    return 1;
}

/*
Operação: comparar_lista
    -Entrada: Endereço de duas listas.
    -Pré-condição: Lisats existirem.
    -Processo: Compara os elementos das duas listas.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: nenhuma.
*/

int comparar_lista(Lista *L, Lista *L2){
    int i, j, flag = 0;

    Lista aux = *L;
    Lista aux2 = *L2;   

    while (aux != NULL && aux2 != NULL){
        if(aux->info != aux2->info){
                flag = 1;
                break;
        }
        aux = aux->prox;
        aux2 = aux2->prox;
    }
    
    if(flag == 1) return 0;

    else return 1;
}

/*
Operação: remover_pos
    -Entrada: O endereço de uma lista, além dos endereços de uma posição do número a ser removido e o elemento removido.
    -Pré-condição: Lista existir e posição ser válida.
    -Processo: Remove o elelemento da posição solicitada.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista sem o elemento solicitado.
*/

int remover_pos(Lista *L, int *pos, float *elem){
    if (lista_vazia(*L) == 1)
        return 0; 

    Lista aux = *L; 

    int i;
    for(i = 1; aux->prox != NULL && i != *pos; i++)
        aux = aux->prox;

    if (aux->prox == NULL)
        return 0; 

    Lista aux2 = aux->prox;

    *elem = aux->prox->info;

    aux->prox = aux2->prox; 
    free(aux2);
    (*L)->info--;

    return 1;
}

/*
Operação: intercalar_lista 
    -Entrada: O endereço de três listas.
    -Pré-condição: Duas das listas existirem e não estarem vazias.
    -Processo: Intercala os elementos das duas listas e guarda em uma terceira lista.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista 3 com os elementos intercalados das duas primeiras listas.
*/

int intercalar_lista(Lista L, Lista L2, Lista L3){
    if(lista_vazia(L) || lista_vazia(L2)) return 0; //falha
    
    Lista aux = L->prox; 

    int i = 0;
    while( i < L->info){

        Lista N = (Lista) malloc(sizeof(struct no));

        if (N == NULL) return 0;

        N->info = aux->info;

        Lista aux2 = L3;
        while (aux2->prox != NULL && aux2->prox->info > aux->info)
            aux2 = aux2->prox;

        N->prox = aux2->prox;
        aux2->prox = N;
        L3->info++;

        aux = aux->prox;
        i++;
    }

    Lista aux2 = L2->prox;

    i = 0;
    while(i < L2->info){

        Lista N = (Lista) malloc(sizeof(struct no));

        if (N == NULL) return 0;

        N->info = aux2->info;

        Lista aux3 = L3;
        while (aux3->prox != NULL && aux3->prox->info > aux2->info)
            aux3 = aux3->prox;

        N->prox = aux3->prox;
        aux3->prox = N;
        L3->info++;

        aux2 = aux2->prox;
        i++;
    }
    return 1;
}

/*
Operação: tamanho_lista
    -Entrada: Endereço de uma lista.
    -Pré-condição: Lista existir.
    -Processo: Conta quantos elementos a lista tem.
    -Saída: Quantidade de elementos na lista.
    -Pós-condição: nenhuma.
*/

int tamanho_lista(Lista* L){
    if(L == NULL) return 0;
    int cont = 0;

    Lista aux = *L;

    while (aux != NULL){
        cont++;
        aux = aux->prox;
    }

    return cont;
}