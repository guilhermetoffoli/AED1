#include <stdlib.h>
#include <string.h>
#include "ex3.h"

struct fila{
    Carro vetor[MAX];
    int ini,fim;
};

/*
Operação: cria_fila
    -Entrada: nenhuma
    -Pré-condição: nenhuma
    -Processo: cria uma instância para a fila
    -Pós-condição:nenhuma
    -Saída: endereço da fila
*/

Fila cria_fila(){
    Fila f = (Fila) malloc(sizeof(struct fila));
    if (f != NULL){
        f->ini = 0;
        f->fim = 0;
    }
    return f;
}

/*
Operação: fila_vazia
    -Entrada: Uma fila
    -Pré-condição: fila existir
    -Processo: verifica se a fila está vazia
    -Pós-condição: nenhuma
    -Saída: -1 para fila inexistente, 0 para falha e 1 para sucesso
*/

int fila_vazia(Fila f){
    if (f == NULL){
        return -1;
    }

    if (f->ini == f->fim){
        return 1;
    }
    else
        return 0;
}

/*
Operação: fila_cheia
    -Entrada: Uma fila
    -Pré-condição: fila existir
    -Processo: verifica se a fila está cheia
    -Pós-condição: nenhuma
    -Saída: -1 para fila inexistente, 0 para falha e 1 para sucesso
*/

int fila_cheia(Fila f){
    if (f == NULL){
        return -1;
    }

    if (f->ini == (f->fim+1)%MAX){
        return 1;
    }
    else
        return 0;
}

/*
Operação: esvazia_fila
    -Entrada: Uma fila
    -Pré-condição: Fila existir
    -Processo: coloca a fila em condição de vazia
    -Pós-condição: fila sem os elementos
    -Saída: 0 para falha e 1 para sucesso
*/

int esvazia_fila(Fila f){
    if(f == NULL) return 0;

    f->fim = 0;
    f->ini = 0;

    return 1;
}

/*
Operação: apaga_fila
    -Entrada: Endereço de uma fila
    -Pré-condição: fila existir
    -Processo: apaga a instância da fila
    -Pós-condição: fila inexistente
    -Saída: 1 para sucesso e 0 para falha
*/

int apaga_fila(Fila *f){
    if(f == NULL) return 0;

    free(*f);
    *f = NULL;

    return 1;
}

/*
Operação: insere_fim
    -Entrada: Uma fila e um elemento
    -Pré-condição: fila existir e não estar cheia
    -Processo: coloca o elemento na fila
    -Pós-condição: fila com o elemento inserido
    -Saída: 1 para sucesso e 0 paar falha
*/

int insere_fim(Fila f, Carro a){
    if (f == NULL || fila_cheia(f)){
        return 0;
    }
    strcpy(f->vetor[f->fim].placa, a.placa);
    f->vetor[f->fim].servico = a.servico;
    f->vetor[f->fim].hora = a.hora;
    f->fim = (f->fim+1) % MAX; 
    return 1;
}

/*
Operação: remove_ini
    -Entrada: Uma fila e o endereço do elemento
    -Pré-condição: fila existir e não estar vazia
    -Processo: remove o elemento
    -Pós-condição: fila com o elemento removido
    -Saída: 1 para sucesso e 0 para falha
*/

int remove_ini(Fila f, Carro *a){
    if (f == NULL || fila_vazia(f)){
        return 0;
    }
    //remove o elemento do inicio
    strcpy(a->placa, f->vetor[f->ini].placa);
    a->servico = f->vetor[f->ini].servico;
    a->hora = f->vetor[f->ini].hora;

    f->ini = (f->ini+1)%MAX;

    return 1;
}

/*
Operação: Tamanho
    -Entrada: Uma fila
    -Pré-condição: fila existir
    -Processo: verifica o tamanho da fila
    -Pós-condição: nenhuma
    -Saída: o para falha e o tamanho da fila em caso de sucesso
*/

int tamanho_fila(Fila f){
    if(f == NULL)return 0;

    if (f->fim > f->ini) return f->fim-f->ini;
    else return f->ini+f->fim;
}