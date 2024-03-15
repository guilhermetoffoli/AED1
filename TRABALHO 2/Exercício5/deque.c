#include <stdlib.h>
#include <string.h>
#include "deque.h"

#define STR 21
#define MAX 10

struct deque{
    char str[MAX][STR];
    int inicio, cont;
};

/*
Operação: cria_deque
    -Entrada: nenhum
    -Pré-condição: nenhum
    -Processo: cria uma instância do deque
    -Pós-condição: nenhum
    -Saída: retorna um endereço
*/

Deque cria_deque(){
    Deque N = (Deque)malloc(sizeof(struct deque));
   
    if (N != NULL){
        N->inicio = MAX - 1;
        N->cont = MAX - 1;
    }
    return N;
}

/*
Operação: deque_vazio
    -Entrada: um deque
    -Pré-condição: deque existir
    -Processo: verifica se o deque é vazio
    -Pós-condição: nenhuma
    -Saída: 1 para sucesso e 0 para falha
*/

int deque_vazio(Deque deq){
    if (deq == NULL){
        return 0;
    }
    if (deq->cont == 0){
        return 1;
    }
    else 
        return 0;
}

/*
Operação: deque_cheio
    -Entrada: um deque
    -Pré-condição: deque existir
    -Processo: verifica se o deque é cheio
    -Pós-condição: nenhuma
    -Saída: 1 para sucesso e 0 para falha
*/

int deque_cheio(Deque deq){
    if (deq == NULL){
        return -1;
    }
    if (deq->cont == MAX){
        return 1;
    }
    else
        return 0;
}

/*
Operação: insere_fim
    -Entrada: um deque e uma string 
    -Pré-condição: deque existir e não estar cheio
    -Processo:insere um elemento no fim
    -Pós-condição: elemento adicionado no fim
    -Saída: 1 para sucesso e 0 para falha
*/

int insere_fim(Deque deq, char *A){

    if (deq == NULL || deque_cheio(deq)){
        return 0;
    }
    strcpy(deq->str[(deq->inicio+deq->cont)%MAX], A);
    deq->cont++;
    return 1;
}

/*
Operação: insere_inicio
    -Entrada: um deque e uma string 
    -Pré-condição: deque existir e não estar cheio
    -Processo:insere um elemento no inicio
    -Pós-condição: elemento adicionado no inicio
    -Saída: 1 para sucesso e 0 para falha
*/

int insere_inicio(Deque deq, char *A){
    if (deq == NULL || deque_cheio(deq)){
        return 0;
    }
    
    strcpy (deq->str[deq->inicio], A);
    deq->inicio = (deq->inicio - 1 + MAX) % MAX;
    deq->cont++;
    return 1;
}
/*
Operação: remove_inicio
    -Entrada: Um deque e uma string
    -Pré-condição: deque existir e não estar vazio
    -Processo: remove no inicio
    -Pós-condição: 1 para sucesso e 0 para falha
    -Saída: string removida
*/

int remove_inicio(Deque deq, char *A){
    if (deq == NULL || deque_vazio(deq)){
        return 0;
    }
    strcpy (A, deq->str[deq->inicio]);
    deq->inicio = (deq->inicio + 1) % MAX;
    deq->cont--;
    return 1;
}

/*
Operação: remove_fim
    -Entrada: Um deque e uma string
    -Pré-condição: deque existir e não estar vazio
    -Processo: remove no fim
    -Pós-condição: 1 para sucesso e 0 para falha
    -Saída: string removida
*/

int remove_fim(Deque deq, char *A){
    if (deque_vazio(deq)){
        return 0;
    }
    strcpy (A, deq->str[(deq->inicio+deq->cont)%MAX]);
    deq->cont--;
    
    return 1;
}
/*
Operação: apaga_deque
    -Entrada: Endereço de um deque
    -Pré-condição: deque existir
    -Processo: apaga o endereço de memória que contém o deque
    -Pós-condição: nenhuma
    -Saída: 1 para sucesso e 0 para falha
*/

int apaga_deque(Deque *deq){
    if(deq == NULL){
        return 0;
    }
    free(*deq);
    *deq = NULL;
    
    return 1;
}

/*
Operação: esvazia_deque
    -Entrada: Um deque
    -Pré-condição: deque existir
    -Processo:
    -Pós-condição:
    -Saída:
*/

int esvazia_deque(Deque deq){
    if(deq == NULL){
        return 0;
    }
    deq->inicio = MAX - 1;
    deq->cont = MAX - 1;
    
    return 1;
}