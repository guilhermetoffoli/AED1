#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct no {
    Pessoa paciente;
    struct no *prox;
};

/*Operação cria_fila:
-Entrada: nenhuma
-Pre-condição: nenhuma 
-Processo: retorna NULL
-Saida: NULL
-Pos-condição: nenhuma
*/
Fila cria_fila(){
    return NULL;
}
/*Operação fila_vazia:
-Entrada: endereço da fila
-Pre-condição: fila ser valida
-Processo: verifica se a fila é igual a NULL
-Saída: retorna 1 se a fila for NULL e 0 caso não
-Pós-condição: nenhuma
*/
int fila_vazia(Fila f){
    if(f == NULL)
        return 1;
    else 
        return 0;
}
/*Operação insere_fim:
-Entrada: endereço da fila, elemento para inserir
-Pre-condição: espaço na memória para alocação de um novo nó
-Processo: aloca espaço de memória para o novo nó, guarda o novo elemento nele e insire na lista
-Saída: retorna 1 se o elemento foi inserido, 0 se falhou
-Pós-condição: elemento na lista
*/
int insere_fim(Fila *f, Pessoa elem){
    Fila N = (Fila)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->paciente = elem;

    if(fila_vazia(*f) == 1){
        N->prox = N;
        *f = N;
    }
    else{
        N->prox = (*f)->prox;
        (*f)->prox = N;
        *f = N;
    }
    return 1;
}

/*Operação remove_ord:
-Entrada: endereço da fila, endereço do elemento que foi removido
-Pre-condição: fila ser não vazia
-Processo: remove o elemento e libera memoria do nó. 
-Saída: retorna 1 se foi removid, 0 se falhou
-Pós-condição: elemento removido da lista
*/
int remove_ord(Fila *f, Pessoa *elem){
    if(fila_vazia(*f) == 1)
        return 0;

    Fila aux = (*f)->prox;
    *elem = aux->paciente;

    if(*f == (*f)->prox)
        *f = NULL;
    else
        free(aux);

    return 1;
}

/*Operação esvazia_fila:
-Entrada: endereço da fila
-Pre-condição: nenhuma
-Processo: processo do apaga_fila(f)
-Saida: retorna apaga_fila(f)
-Pos-condição: nenhuma
*/
int esvazia_fila(Fila *f){
    return apaga_fila(f);
}

/*operação apaga_fila:
-Entrada: endereço da fila
-Pre-condição: fila ser vazia
-Processo: apaga a fila
-Saida: retorna 1 caso tenha dado certo e 0 caso contrario
-Pos-condição: fila apagada
*/
int apaga_fila(Fila *f){
    if(fila_vazia(*f))
        return 0; 
    while(*f != (*f)->prox){
        Fila aux = (*f)->prox;
        (*f)->prox = aux->prox;
        free(aux);
    }
    Fila aux = *f;
    *f = NULL;
    free(aux);
    return 1;
}

/*Operação get_elem_pos
-Entrada: a fila, a posição do elemento, o endereço que vai guardar o elemento na posição
-Pre-condição: fila não vazia
-Processo: procura pelo elemento na posição "pos" e passa o valor que está nessa posição para o endereço de "elem"
-Saida: 0 se a lista está vazia, 1 caso contrário
-Pos-condição: nenhuma
*/
int get_elem_pos(Fila f, int pos, Pessoa *elem){
    if (fila_vazia(f)) return 0;
    Fila aux = f;
    while (pos > 0) {
        aux = aux->prox;
        pos--;
    }
    *elem = aux->paciente;

    return 1;
}