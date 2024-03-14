#include <stdlib.h>
#include "listaint.h"

struct no {
    int info;
    struct no * prox;
};

/*
Operação: cria_lista()
    -Entrada: nenhuma.
    -Pré-condição: nenhuma.
    -Processo: nenhum.
    -Saída: retorna NULL para a lista ser "criada".
    -Pós-condição: nenhuma.
*/

Lista cria_lista() {
    return NULL;
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
Operação: lista_vazia
    -Entrada: Uma lista.
    -Pré-condição: Lista precisa ser instanciada.
    -Processo: Verifica se a lista está vazia.
    -Saída: 1 se é vazia e 0 se não.
    -Pós-condição: nenhuma
*/

int lista_vazia(Lista L) {
    if (L == NULL)
        return 1;
    else
        return 0; // Lista NÃO vazia
}

/*
Operação: insere_elem
    -Entrada: O endereço de uma lista com o elemento a ser inserido.
    -Pré-condição: nenhuma.
    -Processo: Insere um elemento na lista por meio de uma alocação a cada inserção.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: lista com o elemento inserido ordenadamente.
*/

int insere_elem (Lista *L, int elem) {
    // Aloca um novo nó
    Lista N = (Lista) malloc(sizeof(struct no));

    if (N == NULL) { return 0; } 

    N->info = elem; 

    N->prox = *L; 

    *L = N; 

    return 1;
}

/*
Operação: remove_elem
    -Entrada: O endereço de uma lista e um elemento.
    -Pré-condição: Lista precisa ser instanciada e não pode estar vazia.
    -Processo: remove da lista o elemento selecionado.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Elemento selecionado removido da lista.
*/

int remove_elem (Lista *L, int elem) {
    if (lista_vazia(*L) == 1)
        return 0; 

    Lista aux = *L; 

    // Trata elemento = 1o nó da lista
    if (elem == (*L)->info) {
        *L = aux->prox; 
        free(aux); 
        return 1; 
    }

    while (aux->prox != NULL && aux->prox->info != elem)
        aux = aux->prox;

    if (aux->prox == NULL) 
        return 0; 


    Lista aux2 = aux->prox; 

    aux->prox = aux2->prox; 

    free(aux2);
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
Operação: int get_elem_pos
    -Entrada: Uma lista, a posição do elemento e o endereço do elemento.
    -Pré-condição: Lista existir, não ser vazia, além de ter as posições válidas.
    -Processo: Pega o elemento da sua respectiva posição.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: o endereço do elemento com o valor da sua posição na lista.
*/

int get_elem_pos(Lista L, int pos, int *elem){
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

/*
Operação: remove_maior
    -Entrada: Uma lista e o elemento.
    -Pré-condição: Lista existir e ter pelo menos um elemento.
    -Processo: Retira o maior elemento disponível na lista.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista sem o maior elemento.
*/

int remover_maior(Lista *L, int *elem){
    if (lista_vazia(*L) == 1)
        return 0; 

    Lista Lmaior = *L;
    Lista aux = *L;

    int maior = Lmaior->info;

    //Percorrimento até achar quem é o maior
    while(Lmaior->prox != NULL && Lmaior->prox->info != maior){
        if(maior < Lmaior->prox->info){
            maior = Lmaior->prox->info;
        }
        Lmaior = Lmaior->prox;
    }

    *elem = maior;

    //Tratando se o 1° no for maior
    if (*elem == (*L)->info) {
        *L = aux->prox; 
        free(aux); 
        return 1; 
    }

    while (aux->prox != NULL && aux->prox->info != *elem)
        aux = aux->prox;

    Lista aux2 = aux->prox;

    aux->prox = aux2->prox;

    free(aux2); 
    return 1;
}

/*
Operação: inverter_lista
    -Entrada: Endereço de duas listas.
    -Pré-condição: Listas existirem.
    -Processo: Insere os elementos da lista 1 invertidos na lista 2.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista 2 com os elementos da lista 1 invertidos. 
*/

int inverter_lista(Lista *L, Lista *L2){
    if(L == NULL || L2 == NULL) return 0;

    for (int i = 1; ; i++){
        int elem;
        if(get_elem_pos(*L, i, &elem) == 0){
            break;
        }
        insere_elem(L2, elem);
    }
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

int intercalar_lista(Lista *L, Lista *L2, Lista *L3){
    if(lista_vazia(*L) || lista_vazia(*L2)) return 0; //falha

    Lista aux = *L; 
    Lista aux2 = *L2; 
    Lista aux3 = *L3;
    
    int elem, maior = tamanho_lista(L);
    if(maior < tamanho_lista(L2))
        maior = tamanho_lista(L2);
    
    for(int i = 0; i < maior; i++){
        elem = aux->info;
        insere_elem(&aux3, elem); 
        
        aux = aux->prox; 
        aux3 = aux3->prox;

        elem = aux2->info;
        insere_elem(&aux3, elem);

        aux2 = aux2->prox;
        aux3 = aux3->prox;
    }
    L3 = aux3;
    return 1;
}