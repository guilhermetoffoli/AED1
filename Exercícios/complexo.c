#include<stdio.h>
#include <stdlib.h>
#include "complexo.h"

struct complexo{
    int real, comp;
};

/*
Operação: cria_nro
    -Entrada: nenhuma
    -Pré-condição: nenhuma
    -Processo: criar um número complexo
    -Saída: endereço do número complexo criado
    -Pós-condição: nenhuma
*/

nmro * cria_nro(){
   nmro *n;
   n = (nmro *) malloc(sizeof(nmro));

   return n;
}

/*
Operação: get_nro
    -Entrada: Endereço do n complexo e 2 inteiros
    -Pré-condição: nenhuma
    -Processo: retorna os valores das partes real e imaginária de um n complexo.
    -Saída: 1 Sucesso 0 Falha
    -Pós-condição: número complexo com valores de real e comp
*/

int get_nro(nmro *n, int *real, int *comp){
    if(n == NULL){
        return 0;
    }

    *real = n->real;
    *comp = n->comp;

    return 1;
}

/*
Operação: libera_nro
    -Entrada: endereço do endereço de um n complexo
    -Pré-condição: nenhuma
    -Processo: Liberar a memória usada pelo complexo
    -Saída: nenhuma
    -Pós-condição: número racional liberado
*/

void libera_nro(nmro ** n){
    free(*n);
    *n = NULL;
}

/*
Operação: mult
    -Entrada: endereço de dois números complexos
    -Pré-condição: nenhuma
    -Processo: realiza a multiplicação de complexos
    -Saída: endereço da multiplicação
    -Pós-condição: nenhuma
*/

nmro * mult(nmro *C1, nmro *C2){
    nmro *Cmult;
    Cmult = cria_nro();

    if(Cmult != NULL){
        Cmult->real = (C1->real * C2->real)-(C1->comp * C2->comp);
        Cmult->comp = (C1->real * C2->comp)+(C1->comp * C2->real);
    }

    return Cmult; 
}

/*
Operação: set_nro
    -Entrada: Endereço do n complexo e 2 inteiros
    -Pré-condição: nenhuma
    -Processo: Atribui o valor do número real e o complexo
    -Saída: 1 Sucesso 0 falha
    -Pós-condição: Número complexo com valores alterados
*/

int set_nro(nmro *n, int real, int comp){
    if(n == NULL)
        return 0; //FALHA

    n->real = real;
    n->comp = comp;

    return 1; //Sucesso
}

/*
Operação: soma
    -Entrada: endereço de dois nros complexos
    -Pré-condição: nenhuma
    -Processo: realiza a soma de complexos
    -Saída: endereço da soma
    -Pós-condição: nenhuma
*/

nmro * soma(nmro *C1, nmro *C2){
    nmro *Csoma;
    Csoma = cria_nro();

    if(Csoma != NULL){
    Csoma->real = C1->real + C2->real;
    Csoma->comp = C1->comp + C2->comp;
    }

    return Csoma; //SUCESSO
}

/*
Operação: sub
    -Entrada: endereço de dois nros complexos
    -Pré-condição: nenhuma
    -Processo: realiza a subtração de complexos
    -Saída: endereço da subtração
    -Pós-condição: nenhuma
*/

nmro * sub(nmro *C1, nmro *C2){
    nmro *Csub;
    Csub = cria_nro();

    if(Csub != NULL){
    Csub->real = (C1->real)-(C2->real);
    Csub->comp = (C1->comp)-(C2->comp);
    }

    return Csub; //SUCESSO
}