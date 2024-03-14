#include <stdlib.h>
#include "listaex6.h"

struct no {
    double info;
    struct no * prox;
    struct no * ant;
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
Operação: lista_vazia
    -Entrada: Uma lista.
    -Pré-condição: Lista precisa ser instanciada.
    -Processo: Verifica se a lista está vazia.
    -Saída: 1 se é vazia e 0 se não.
    -Pós-condição: nenhuma
*/

int lista_vazia(Lista L) {
    if (L == NULL)
        return 1; // Lista vazia
    else
        return 0; // Lista NÃO vazia
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
Operação: insere_elem
    -Entrada: O endereço de uma lista com o elemento a ser inserido.
    -Pré-condição: nenhuma.
    -Processo: Insere um elemento na lista por meio de uma alocação a cada inserção.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: lista com o elemento inserido ordenadamente.
*/

int insere_elem(Lista *L, double elem){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL) return 0; //Falha

    N->info = elem; //Insere o conteúdo
    N->ant = NULL; //Não tem antecessor do novo no
    N->prox = *L; //Sucessor do nó recebe mesmo end da lista

    if(lista_vazia(*L) == 0) (*L)->ant = N; //Faz o antecessor ser o novo no

    *L = N; // Faz a lista apontar para o novo no

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

int remove_elem(Lista *L, double elem){
    if(lista_vazia(*L)) return 0;

    Lista aux = *L;

    while (aux->prox != NULL && aux->info != elem)
        aux = aux->prox;
    
    if(aux->info != elem) return 0;
    if(aux->prox != NULL) aux->prox->ant = aux->ant;
    if(aux->ant != NULL) aux->ant->prox = aux->prox; 
    if(aux == *L) *L = aux->prox;

    free(aux);
    
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

    while((*L)->prox != *L){
        Lista aux = (*L)->prox; //Aponta para os primeiros elementos da lista
        (*L)->prox = aux->prox; //Aponta pra o próximo el
        free(aux); //Libera os primeiros elementos até l -> NULL
    }
    *L = NULL;
    return 1; //Sucesso
}

/*
Operação: int get_elem_pos
    -Entrada: Uma lista, a posição do elemento e o endereço do elemento.
    -Pré-condição: Lista existir, não ser vazia, além de ter as posições válidas.
    -Processo: Pega o elemento da sua respectiva posição.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: o endereço do elemento com o valor da sua posição na lista.
*/

int get_elem_pos(Lista L, int pos, double *elem){
    if(lista_vazia(L) || pos <= 0) return 0;

    int cont = 1;
    Lista Aux = L;

    while (Aux->prox != NULL && cont < pos){
        Aux = Aux->prox;//Avança
        cont++;
    }
    if(cont != pos) return 0; //FALHA não existe posição solicitada
    
    *elem = Aux->info;

    return 1;
}

/*
Operação: insere_pos
    -Entrada: O endereço de uma lista, do elemento e da posição a ser inserida.
    -Pré-condição: Lista existir e posição ser válida.
    -Processo: Insere o elemento na posição solicitada.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista com o elemento digitado.
*/

int insere_pos(Lista L, int *pos, double *elem){
    if(*pos < 1 || tamanho_lista(&L)+1 < *pos ) return 0; //falha

    if(tamanho_lista(&L)+1 == *pos){
        Lista N = (Lista) malloc(sizeof(struct no));
        Lista aux = L;
        if(N == NULL) return 0; 

        N->info = *elem; 

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = N;
        N->ant = aux;
    }
    else{
        Lista N = (Lista) malloc(sizeof(struct no));
        Lista aux = L;
        if(N == NULL) return 0; //Falha

        N->info = *elem; 

        for(int i = 1; i < *pos-1; i++)
            aux = aux->prox;
        
        N->ant = aux; //Inserindo novo no 
        N->prox = aux->prox;

        aux->prox = N; 
        N->prox->ant = aux;

    }
    return 1;
}

/*
Operação: remove_menor
    -Entrada: Uma lista e o elemento.
    -Pré-condição: Lista existir e ter pelo menos um elemento.
    -Processo: Retira o menor elemento disponível na lista.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista sem o menor elemento.
*/

int remove_menor(Lista *L, double *elem){
    if (lista_vazia(*L) == 1) return 0; // Falha

    Lista aux = *L;

    *elem = aux->info;

    while (aux->prox != NULL && *elem != aux->info){
        if(*elem > aux->prox->info){
            *elem = aux->prox->info;
        }
        aux = aux->prox;
    }
    if(aux->prox != NULL) aux->prox->ant = aux->ant;
    if(aux->ant != NULL) aux->ant->prox = aux->prox; 
    if(aux == *L) *L = aux->prox;

    free(aux);
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

    Lista aux = *L;
    Lista aux2 = NULL;

    while(aux != NULL){
        aux2 = aux->ant;
        aux->ant = aux->prox;
        aux->prox = aux2;
        aux = aux->ant;
    }
    if(aux2 != NULL)
        *L2 = aux2->ant;

    return 1;
}

/*
Operação: remove_todos
    -Entrada: Endereço de uma lista e do elemento.
    -Pré-condição: Lista não ser vazia.
    -Processo: Remove todas as ocorrências de um dado elemento.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista sem as ocorrências solicitadas.
*/

int remove_todos(Lista *L, double *elem){
   
    Lista aux = *L;
    Lista aux2;

    while(aux != NULL){
        if(aux->info == *elem){
            aux2 = aux->prox;

            if(aux->info != *elem) return 0;
            if(aux->prox != NULL) aux->prox->ant = aux->ant;
            if(aux->ant != NULL) aux->ant->prox = aux->prox; 
            if(aux == *L) *L = aux->prox;

            free(aux);
            aux = aux2;
        }
        else
            aux = aux->prox;
    }

    if (aux == NULL) 
        return 0; 

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
    int cont = 0;

    Lista aux = *L;

    while (aux != NULL){
        cont++;
        aux = aux->prox;
    }

    return cont;
}