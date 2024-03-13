#include <stdlib.h>
#include <string.h>
#include "listexerc.h"

/*
Operação: cria_lista()
    -Entrada: nenhuma.
    -Pré-condição: nenhuma.
    -Processo: Instancia uma lista.
    -Saída: Lista com memória alocada.
    -Pós-condição: nenhuma.
*/

Lista cria_lista(){  
    Lista L = (Lista) malloc(sizeof(struct lista));

    if(L != NULL){
        L->fim = 0;
    }

    return L;
}

/*
Operação: lista_vazia
    -Entrada: Uma lista.
    -Pré-condição: Lista precisa ser instanciada.
    -Processo: Verifica se a lista está vazia.
    -Saída: 1 se é vazia e 0 se não.
    -Pós-condição: nenhuma
*/

int lista_vazia(Lista L){
    if(L == NULL) return 0; 

    if(L->fim == 0) return 1;
    
    else return 0;//lista nao vazia

}

/*
Operação: lista_cheia
    -Entrada: Uma lista.
    -Pré-condição: Lista precisa ser instanciada.
    -Processo: Verifica se a lista está cheia.
    -Saída: 1 se é cheia e 0 se não.
    -Pós-condição: nenhuma.
*/

int lista_cheia(Lista L){
    if(L == NULL) return 0; 

    if(L->fim == MAX) return 1; 
    
    else return 0;//lista nao cheia

}

/*
Operação: insere_elem
    -Entrada: Uma lista e uma string.
    -Pré-condição: Lista precisa ser instanciada.
    -Processo: Insere strings na lista.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: String inserido na lista.
*/

int insere_elem(Lista L, char str[]){
    if (L == NULL || lista_cheia(L) == 1)
        return 0; 

    strcpy(L->no[L->fim], str);

    L->fim++;

    return 1;
}

/*
Operação: remove_elem
    -Entrada: Uma lista.
    -Pré-condição: Lista precisa ser instanciada e um caracter válido.
    -Processo: remove da lista a string selecionada.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: String selecionada removida da lista.
*/

int remove_elem(Lista L, char str[]){
    if (L == NULL || lista_vazia(L) == 1)
        return 0; 

    int i = 0;

    while(i < L->fim && (strcmp(L->no[i], str) != 0)){
        i++;
    }

    if (i == L->fim)
        return 0;     

    //Deslocamento p/ a esquerda a fim de remover o el na pos 1
    int x;
    for (x=i+1; x < L->fim; x++)
    {
        strcpy(L->no[x-1], L->no[x]);
    }
    L->fim--;

    return 1; 
}

/*
Operação: apaga_lista
    -Entrada: Endereço de uma lista.
    -Pré-condição: Lista ter caracteres.
    -Processo: Libera a memória alocada pela lista. 
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: memória liberada.
*/

int apaga_lista(Lista * end_L){
    if(*end_L == NULL) return 0; 

    free(*end_L);
    *end_L = NULL;

    return 1;
}

/*
Operação: int esvazia_lista
    -Entrada: Uma lista.
    -Pré-condição: Lista existir.
    -Processo: Retira todos os elementos ao voltar no começo da lista.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista sem elementos.
*/

int esvazia_lista(Lista L){
    if(L == NULL) return 0; 

    L->fim = 0;

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

int get_elem_pos(Lista L, int pos, char str[]){
    if(L == NULL || lista_vazia(L) || pos < 1 || pos > L->fim)   return 0; //Falha

    strcpy(str, L->no[pos-1]);

    return 1;
}

/*
Operação: insere_pos
    -Entrada: Uma lista, a string e a posição a ser inserida.
    -Pré-condição: Lista existir e posição ser válida.
    -Processo: Insere a string na posição solicitada.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista com a string digitada.
*/

int insere_pos(Lista L, int pos, char str[]){
    if(L == NULL || pos < 1 || pos > L->fim || lista_vazia(L)) 
        return 0; 

    strcpy(L->no[pos-1], str);

    return 1;
}

/*
Operação: remove_menor
    -Entrada: Uma lista e uma string.
    -Pré-condição: Lista existir e ter pelo menos um elemento.
    -Processo: Retira a menor string disponível na lista.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista sem o menor elemento.
*/

int remove_menor(Lista L, char menor[]){
    if (L == NULL || lista_vazia(L) == 1)
        return 0; //falha
        
    int i;

    for (i = 1; i < L->fim ; i++){
        if(strcmp(L->no[i-1], L->no[i]) > 0)            
            strcpy(menor, L->no[i]);

        if(strcmp(menor, L->no[i-1]) == 0)
            break;
    }

    i--;
    int x;
    for (x=i+1; x < L->fim; x++)
    {
        strcpy(L->no[x-1], L->no[x]);
    }
    L->fim--;

    return 1;
}

/*
Operação: concatenar_lista
    -Entrada: Três listas.
    -Pré-condição: Duas das listas existirem e não estarem vazias.
    -Processo: Concatena as strings das duas primeiras listas e guarda em uma terceira.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista 3 com strings concatenadas das duas primeiras listas.
*/

int concatenar_lista (Lista L, Lista L2, Lista L3) {

    if(lista_vazia(L) || lista_vazia(L2)) return 0; //falha

    Lista aux;
    aux = cria_lista();
    int maior = L->fim;
    int i;

    if(L2->fim > L->fim){
        maior = L2->fim;
    }

    for (int i = 0; i < L->fim; i++)
        strcpy(aux->no[i], L->no[i]);
    
    L3->fim = 1;
    for(int i = 1; i < maior+1 ; i++){
        strcpy(L3->no[i-1], strcat(aux->no[i-1], L2->no[i-1]));
        L3->fim++;
    }

    return 1;
}

/*
Operação: tamanho_lista
    -Entrada: Uma lista e o endereço do tamanho.
    -Pré-condição: Lista existir.
    -Processo: Conta quantos elementos tem na lista.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: nenhuma.
*/

int tamanho_lista(Lista L, int *tam){
    if(L == NULL) return 0; //Falha

    *tam = L->fim;

    return 1;
}