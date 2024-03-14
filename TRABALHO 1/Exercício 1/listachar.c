#include <stdlib.h>
#include "listachar.h"

struct lista{
    char no[MAX];
    char no2[MAX+MAX];
    int fim;
};

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
Operação: insere_ord
    -Entrada: Uma lista e um caractere.
    -Pré-condição: Lista precisa ser instanciada e um caracter válido.
    -Processo: Insere na lista caracteres ordenados em relação a tabela ASCII.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Caractere inserido ordenadamente na lista.
*/

int insere_ord(Lista L, char elem){
    if (L == NULL || lista_cheia(L) == 1)
        return 0; //falha

    if(lista_vazia(L) == 1 || elem >= L->no[L->fim-1]){
        L->no[L->fim] = elem;
    }
    else{
        int i, aux = 0;
        while(elem >= L->no[aux]){
            aux++;
        }
        for (i = L->fim; i > aux; i--){
            L->no[i] = L->no[i-1];
        }
        L->no[aux] = elem;       
    }

    L->fim++;

    return 1;
}

/*
Operação: remove_ord
    -Entrada: Uma lista e um caractere.
    -Pré-condição: Lista precisa ser instanciada e um caracter válido.
    -Processo: remove da lista o caracter selecionado.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Caracter selecionado removido da lista.
*/

int remove_ord(Lista L, char elem){
    if (L == NULL || lista_vazia(L) == 1 || elem < L->no[0] || elem > L->no[L->fim-1])
        return 0; //falha

    int i = 0, x = 0;

    while(i < L->fim && L->no[i] < elem){
        i++;
    }

    if(i == L->fim || L->no[i] > elem) return 0; 

    for (x=i+1; x < L->fim; x++){
        L->no[x-1] = L->no[x];
    }
    L->fim--;

    return 1; //Sucesso
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
    if(L == NULL) return 0; //Falha

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

int get_elem_pos(Lista L, int pos, char *elem){
    if(L == NULL || lista_vazia(L) == 1 || pos < 1 || pos > L->fim) return 0; //Falha

    *elem = L->no[pos-1];

    return 1;
}

/*
Operação: get_elem_pos_inter
    -Entrada: Uma lista intercalada, a posição do elemento e o endereço do elemento.
    -Pré-condição: Lista intercalada existir, não ser vazia, além de ter as posições válidas.
    -Processo: Pega o elemento da sua respectiva posição.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: o endereço do elemento com o valor da sua posição na lista intercalada. 
*/

int get_elem_pos_inter(Lista L, int pos, char *elem){
    if(L == NULL || pos < 1 || pos > L->fim) return 0; //Falha

    *elem = L->no2[pos-1];

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

/*
Operação: remover_pos
    -Entrada: Uma lista e uma posição do número a ser removido.
    -Pré-condição: Lista existir e posição ser válida.
    -Processo: Remove o caractere da posição solicitada.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista sem o caractere solicitado.
*/

int remover_pos(Lista L, int pos){
    if(L == NULL || pos < 1 || pos > L->fim || lista_vazia(L)) 
        return 0; //Falha

    int i, x = 0;

    for(i = 0; i < L->fim; i++){
        if(L->no[i] == L->no[pos-1]){
            for (x=i+1; x < L->fim; x++)
            {
               L->no[x-1] = L->no[x];
            }
            L->fim--;
        }
    }

    return 1;
}

/*
Operação: remove_vogal
    -Entrada: Uma lista.
    -Pré-condição: Lista existir.
    -Processo: Remove apenas os vogais presentes na lista.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista sem vogais.
*/

int remove_vogal(Lista L){
    char vogal[10] = {'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U'};

    if (L == NULL || lista_vazia(L) == 1){
        return 0; //falha
    }

    int t, i, x = 0;
    int aux = L->fim;

    for(i = 0; i < aux; i++) 
        for(t = 0; t < 10; t++) 
            if(L->no[i] == vogal[t]){
                x++;
                for (int x=i+1; x < L->fim; x++){ 
                    L->no[x-1] = L->no[x];                     
                }
                L->fim--;
                break;
            }

    return 1; //Sucesso
}

/*
Operação: intercalar_lista 
    -Entrada: Três listas.
    -Pré-condição: Duas das listas existirem e não estarem vazias.
    -Processo: Intercala os caracteres das duas listas e guarda em uma terceira lista.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista 3 com caracteres intercalados das duas primeiras listas.
*/

Lista intercalar_lista (Lista L, Lista L2) {
    if(lista_vazia(L) || lista_vazia(L2)) return 0; //falha
        Lista L3;

        int j, i;
        int maior = L->fim;

        if(maior < L2->fim)
            maior = L2->fim;

        L3->fim = L->fim+L2->fim;

        for (i = 0, j = 0; i < maior; i++)
        {
            L3->no2[i+j] = L->no[j];
            L3->no2[i+j+1] = L2->no[j];
            j++;
        }
    return L3;
}
