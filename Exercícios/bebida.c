#include <stdlib.h>
#include <string.h>
#include "bebida.h"

Lista cria_lista(){
    Lista L = (Lista) malloc(sizeof(struct lista));


    if(L != NULL){
        L->fim = 0; 
    }

    return L;
}

int lista_vazia(Lista L){
    if(L == NULL) return 0; //Lista inexistente

    if(L->fim == 0) return 1;//lista vazia
    
    else return 0;//lista nao vazia
}

int lista_cheia(Lista L){
    if(L == NULL) return 0; //Lista inexistente

    if(L->fim == MAX) return 1; //lista cheia
    
    else return 0;//lista nao cheia
}

int insere_ord(Lista L, char str[]){
    if (L == NULL || lista_cheia(L) == 1)
        return 0; //falha

    strcpy(L->no[L->fim], str); // Insere elemento

    L->fim++; // Avança o Fim

    return 1;
}

int remove_ord(Lista L, char str[]){
    if (L == NULL || lista_vazia(L) == 1)
        return 0; //falha
    
    if(strcmp(str, L->no[L->fim-1])) L->fim--;

    int i = 0;

    while(i < L->fim && (strcmp(str, L->no[L->fim-1]) != 0)){
        i++;
    }

    //Deslocamento p/ a esquerda a fim de remover o el na pos 1
    int x;
    for (x=1+1; x < L->fim; x++)
    {
        L->no[x-1][0] = L->no[x][0];
    }
    L->fim--;

    return 1; //Sucesso
}

int apaga_lista(Lista * end_L){
    if(*end_L == NULL) return 0; //Falha

    free(*end_L);
    *end_L = NULL;

    return 1;
}

int esvazia_lista(Lista L){
    if(L == NULL) return 0; //Falha

    L->fim = 0;

    return 1;
}

int get_elem_pos(Lista L, int pos, char *str[]){
    if(L == NULL || lista_vazia(L) == 1 || pos < 1 || pos > L->fim) return 0; //Falha

    //*str[STR] = L->no[pos-1][0];
    strcmp(*str, L->no[pos-1]);


    return 1;
}

int imprime_lista(Lista L){
    if(lista_vazia(L) == 1){
        return 0;
    }
    return 1;
}