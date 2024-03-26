#include<stdlib.h>
#include<math.h>
#include "pontoR3.h"

struct ponto{
    float x, y, z;
};

/*
Operação: cria_pto
    Entrada: coordenadas x, y e z do ponto
    Pré-condição: nenhuma
    Processo: criar uma instância do ponto e atribuir os valores das suas coordenadas
    Saída: Endereço do ponto criado ou NULL em caso de falha
    Pós-condição: um novo ponto é criado 
*/


pto cria_ponto(float x, float y, float z){
    pto p = (pto) malloc(sizeof(struct ponto));

    if(p != NULL)
    {
        p->x = x;
        p->y = y;
        p->z = z;
    }
    return p;
}

/*
    Entrada: endereço do endereço do ponto
    Pré-condição: endereço ser válido
    Processo: apaga a instância do ponto
    Saída: 1 sucesso, 0 falha
    Pós-condição: Um ponto é apagado
*/

int apaga_pto(pto * p){
    if(*p == NULL){
        return 0; //FALHA
    }

    free(*p);
    *p == NULL;

    return 1; //SUCESSO
}

/*
Operação: distancia_2ptos

    Entrada: enderelo de dois pts
    Pré-condição: endereço dos ptos serem válidos
    Processo: calcular a distância
    Saída: distância entre os pontos
    Pós-condição: nenhuma
*/

float distancia_2ptos(pto  p1, pto p2){
    if(p1 == NULL || p2 == NULL){
        return -1; //FALHA
    }
float dist = sqrt(pow((p2->x-p1->x), 2) + pow((p2->y-p1->y), 2) + pow((p2->z-p1->z), 2));

return dist;
}
