#include<stdlib.h>
#include"pilhaex1.h"

struct no{
    int info;
    struct no* prox;
};

/*
Operação Cria_Pilha:
    – Entrada: nenhuma
    – Pré-condição: nenhuma
    – Processo: cria uma pilha e a coloca no estado
    de pilha vazia
    – Saída: endereço da pilha criada
    – Pós-condição: nenhuma
*/

Pilha cria_pilha () {
    return NULL;
}

/*
Operação Pilha_Vazia:
    – Entrada: endereço da pilha
    – Pré-condição: nenhuma
    – Processo: verifica se a pilha está vazia
    – Saída: retorna 1 se pilha vazia ou 0 caso
    contrário
    – Pós-condição: nenhuma
*/

int pilha_vazia (Pilha p) {
    if (p == NULL) return 1;

    else return 0;
}

/*
Operação: esvazia_pilha
    -Entrada: Endereço de uma pilha.
    -Pré-condição: Pilha existir.
    -Processo: Remove elemento a elemento liberando a memória alocada por eles.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Pilha vazia com a memória alocada por eles liberada.
*/

int esvazia_pilha(Pilha *p){
    if(*p == NULL) return 0;

    while(*p != NULL){
        Pilha aux = *p;

        *p = aux->prox; 
        
        free(aux); 
    }
    return 1; //Sucesso
}

/*
Operação: apaga_pilha
    -Entrada: Endereço de uma pilha.
    -Pré-condição: Pilha existir.
    -Processo: Chama o esvazia_lista e remove elemento a elemento liberando a memória alocada por eles.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Pilha vazia com a memória alocada por eles liberada.
*/

int apaga_pilha(Pilha *p){
    return (esvazia_pilha(p));
}

/*
Operação Empilha (push):
    – Entrada: endereço da pilha e o elemento a ser
    inserido
    – Pré-condição: pilha não estar cheia
    – Processo: inserir o elemento informado no topo
    da pilha
    – Saída: retorna 1 se a operação foi bem
    sucedida ou 0 caso contrário
    – Pós-condição: a pilha de entrada com um
    elemento a mais
*/

int push (Pilha *p, int elem) {
    Pilha N = (Pilha) malloc(sizeof(struct no));
    if (N == NULL)
        return 0;

    N->info = elem;

    N->prox = *p;

    *p = N;

    return 1;
}

/*
Operação Desempilha (pop):
    – Entrada: endereço da pilha e o endereço de
    retorno do elemento do topo da pilha
    – Pré-condição: pilha não estar vazia
    – Processo: remover o elemento que está no
    topo da pilha e retorná-lo
    – Saída: retorna 1 se a operação foi bem
    sucedida ou 0 caso contrário
    – Pós-condição: a pilha de entrada com um
    elemento a menos e a variável de retorno com o
    elemento removido
*/

int pop (Pilha *p, int *elem) {
    if (pilha_vazia(*p) == 1)
        return 0;

    Pilha aux = *p;

    *elem = aux->info;

    *p = aux->prox;

    free(aux);

    return 1;
}

/*
Operação Le_Topo:
    – Entrada: endereço da pilha e o endereço de
    retorno do elemento do topo da pilha
    – Pré-condição: pilha não estar vazia
    – Processo: retornar o valor do elemento que
    está no topo da pilha SEM removê-lo
    – Saída: retorna 1 se a operação foi bem
    sucedida ou 0 caso contrário
    – Pós-condição: variável de retorno com o
    elemento do topo
*/

int le_topo (Pilha *p, int *elem) {
    if (pilha_vazia(*p) == 1)
        return 0;
    *elem = (*p)->info;

    return 1;
}
