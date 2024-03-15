#include<stdlib.h>
#include"ex2.h"

# define max 20

struct pilha {
    char no[max];
    int topo;
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

Pilhachar cria_pilha_char() {
    Pilhachar p;

    p = (Pilhachar) malloc (sizeof (struct pilha));

    if (p != NULL)

    p->topo = -1;

    return p;
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

int pilha_vazia_char(Pilhachar p) {
    if (p->topo == -1) return 1;

    else return 0;
}

/*
Operação Pilha_Cheia:
    – Entrada: endereço da pilha
    – Pré-condição: nenhuma
    – Processo: verifica se a pilha está cheia
    – Saída: retorna 1 se pilha cheia ou 0 caso
    contrário
    – Pós-condição: nenhuma
*/

int pilha_cheia_char(Pilhachar p) {
    if (p->topo == max-1) return 1;

    else return 0;
}

/*
Operação: int esvazia_lista
    -Entrada: Uma pilha.
    -Pré-condição: pilha existir.
    -Processo: Retira todos os elementos ao voltar no começo da pilha.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: pilha sem elementos.
*/

int esvazia_lista_char(Pilhachar P){
    if(P == NULL) return 0; 

    P->topo = -1;

    return 1;
}

/*
Operação: apaga_lista
    -Entrada: Endereço de uma pilha.
    -Pré-condição: Pilha ter caracteres.
    -Processo: Libera a memória alocada pela pilha. 
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: memória liberada.
*/
int apaga_lista_char(Pilhachar *end_P){
    if(*end_P == NULL) return 0;

    free(*end_P);

    *end_P == NULL;

    return 1;

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

int push_char(Pilhachar p, char elem) {
    if (p == NULL || pilha_cheia(p) == 1) return 0;

    // Insere o elemento no topo
    p->topo++;

    p->no[p->topo] = elem;

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

int pop_char(Pilhachar p, char *elem) {
    if (p == NULL || pilha_vazia(p) == 1) return 0;

    *elem = p->no[p->topo]; // Retorna o elemento

    p->topo--; // Remove o elemento do topo

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

int le_topo_char (Pilhachar p, char *elem) {
    if (p == NULL || pilha_vazia(p) == 1) return 0;

    *elem = p->no[p->topo]; // Retorna o elemento
    
    return 1;
}

struct no {
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

Pilhareal cria_pilha_real () {
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

int pilha_vazia_real (Pilhareal p) {
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

int esvazia_pilha_real(Pilhareal *p){
    if(*p == NULL) return 0;

    while(*p != NULL){
        Pilhareal aux = *p;

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

int apaga_pilha_real(Pilhareal *p){
    return (esvazia_pilha_real(p));
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

int push_real (Pilhareal *p, float elem) {
    Pilhareal N = (Pilhareal) malloc(sizeof(struct no));
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

int pop_real (Pilhareal *p, float *elem) {
    if (pilha_vazia(*p) == 1)
        return 0;

    Pilhareal aux = *p;

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

int le_topo_real (Pilhareal *p, float *elem) {
    if (pilha_vazia_real(*p) == 1)
        return 0;
    *elem = (*p)->info;

    return 1;
}

int valida_escopo(char operacao[]){
    int contparen = 0, contcolch = 0, contchave = 0;
    Pilhachar p = cria_pilha_char;
    char c;

    for (int i = 0; operacao[i] != '\0'; i++){
        if( operacao[i]!='+' && operacao[i]!='-' && operacao[i]!='/' && operacao[i]!='*'
                && operacao[i]!='^' && operacao[i]!='(' && operacao[i]!=')' && operacao[i]!='[' &&
                operacao[i]!=']' && operacao[i]!='{' && operacao[i]!='}' && (operacao[i]<'A' || operacao[i]>'F'))
            {
                return -1;
            }
        if (operacao[i] == '('){
            push_char(p, operacao[i]);
            contparen++;
        }
        else if (operacao[i] == '['){
            if (!pilha_vazia_char(p)){
                le_topo_char(p, operacao[i]); 
                if (operacao[i] == '('){
                    return -3;
                }
            }
            push_char(p, operacao[i]);
            contcolch++;
        }
        else if (operacao[i] == '{'){
            if (!pilha_vazia_char(p)){
                le_topo_char(p, operacao[i]); 
                if (operacao[i] == '(' || operacao[i] == '['){
                    return -5;
                }
            }
            push_char(p, operacao[i]);
            contchave++;
        }
        else if(operacao[i] == ')' && contparen != 1){
            return -7;
        }
        else if (operacao[i] == ']' && contcolch != 1){
            return -9;
        }
        else if (operacao[i] == '}' && contchave != 1){
            return -11;
        }
    }
    return 1;
}