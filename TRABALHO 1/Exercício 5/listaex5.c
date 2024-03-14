#include <stdlib.h>
#include "listaex5.h"

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
Operação: insere_final
    -Entrada: O endereço de uma lista com o elemento a ser inserido.
    -Pré-condição: nenhuma.
    -Processo: Insere um elemento no final da lista por meio de uma alocação a cada inserção.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: lista com o elemento inserido no final.
*/

int insere_final(Lista *L, int elem){
    //Aloca um novo nó e preenche o campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL) return 0; //falha nó, nao alocado

    N->info = elem; //Insere o conteudo



    if(lista_vazia(*L) == 1){
        N->prox = N; 
        *L = N; 
    }
    else{ 
        N->prox = (*L)->prox; 
        (*L)->prox = N;
        *L = N; 
    } 
    return 1;
}

/*
Operação: remove_inicio
    -Entrada: O endereço de uma lista e um elemento.
    -Pré-condição: Lista precisa ser instanciada e não pode estar vazia.
    -Processo: remove da lista o elemento do inicio.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Elemento do inicio removido da lista.
*/

int remove_inicio(Lista *L, int *elem){
    if(lista_vazia(*L) == 1) return 0;

    Lista aux = (*L)->prox; 
    *elem = aux->info; 

    if(*L == (*L)->prox) 
        *L = NULL; 
    else 
        (*L)->prox = aux->prox; 

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
        Lista aux = (*L)->prox;
        (*L)->prox = aux->prox; 
        free(aux); 
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

int get_elem_pos(Lista L, int pos, int *elem){
    if(lista_vazia(L) || pos <= 0) return 0;

    int cont = 1;
    Lista Aux = L->prox;

    while (Aux->prox != L->prox && cont < pos){
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

int insere_pos(Lista *L, int *pos, int *elem){
    if(tamanho_lista(L)+1 < *pos || *pos < 1) return 0; //falha

    if(tamanho_lista(L)+1 == *pos){
        Lista N = (Lista) malloc(sizeof(struct no));
        if(N == NULL) return 0; //falha nó, nao alocado

        N->info = *elem; //Insere o conteudo

        N->prox = (*L)->prox; 
        (*L)->prox = N;
        *L = N; 

        return 1;
    }
    else{
        Lista N = (Lista) malloc(sizeof(struct no));
        if(N == NULL) return 0; //falha nó, nao alocado

        Lista aux = (*L)->prox;

        int i;
        for(i = 0; i < *pos-2; i++)
            aux = aux->prox;

        N->info = *elem; //Insere o conteudo
        N->prox = aux->prox;
        aux->prox = N;
    }
     
    return 1;
}

/*
Operação: remove_par
    -Entrada: Endereço de uma lista e de um elemento.
    -Pré-condição: Lista existir e ser não vazia.
    -Processo: Remove apenas os elementos pares.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista sem elementos pares.
*/

int remove_par(Lista *L, int *elem){
    Lista Aux = *L;
    if(lista_vazia(*L) == 1) return 0;

    while (Aux->prox != *L){
            *elem = Aux->prox->info;
            if((*elem % 2) == 0){
                Lista Aux2 = Aux->prox; 
                Aux->prox = Aux2->prox;
                free(Aux2);
        }
        Aux = Aux->prox;
    }
        
    return 1;
}

/*
Operação: insere_inicio
    -Entrada: O endereço de uma lista com o elemento a ser inserido.
    -Pré-condição: nenhuma.
    -Processo: Insere um elemento no início da lista por meio de uma alocação a cada inserção.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: lista com o elemento inserido no início.
*/

int insere_inicio(Lista *L, int *elem){
  
    if(L == NULL) return 0; 

    Lista N = (Lista) malloc(sizeof(struct no));

    if(N == NULL) return 0;
    
    N->info = *elem; 
    N->prox = (*L);   
    *L = N;  
    return 1;
}

/*
Operação: remove_final
    -Entrada: O endereço de uma lista e um elemento.
    -Pré-condição: Lista precisa ser instanciada e não pode estar vazia.
    -Processo: remove da lista o elemento do final.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Elemento do inicio removido do final.
*/

int remove_final(Lista *L, int *elem){
    if(lista_vazia(*L) == 1) return 0;
    
    Lista aux = *L;
    *elem = aux->info;

    if(*L == (*L)->prox) 
        *L = NULL; //Trata lista com 1 único elemento
    else
        *L = aux->prox;

    free(aux);

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

    Lista aux = (*L)->prox;

    while (aux != *L){
        cont++;
        aux = aux->prox;
    }

    return cont+1;
}
