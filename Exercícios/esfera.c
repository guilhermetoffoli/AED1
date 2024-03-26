#include<stdlib.h>
#include<math.h>
#include "pontoR3.h"
#include "esfera.h"

struct ponto{
    float x, y, z;
};

/*
Operação: area
    -Entrada: Dois pontos
    -Pré-condição: pontos serem válidos
    -Processo: Calcula a área de uma esfera (4*pi*r^2)
    -Saída: Area da esfera
    -Pós condição: nenhuma
*/

float area(pto  p1, pto p2){
    float area = pow(raio(p1, p2), 2)*4*3.14;

    return area;
}

/*
Operação: cria_esfera
    Entrada: coordenadas x, y e z do ponto que define a esfera
    Pré-condição: nenhuma
    Processo: criar uma instância do ponto e atribuir os valores das suas coordenadas
    Saída: Endereço do ponto criado ou NULL em caso de falha
    Pós-condição: um novo ponto é criado 
*/

pto cria_esfera(float x, float y, float z){
    pto p = (pto) malloc(sizeof(struct ponto));

    if(p != NULL){
        p->x = x;
        p->y = y;
        p->z = z;
    }
    return p;
}

/*
Operação: libera_esfera
    Entrada: endereço do endereço do ponto
    Pré-condição: endereço ser válido
    Processo: apaga a instância do ponto
    Saída: 1 sucesso, 0 falha
    Pós-condição: Um ponto é apagado
*/

int libera_esfera(pto *p){
    if(*p == NULL)
        return 0;
    
    free(*p);
    *p == NULL;

    return 1;
}

/*
Operação: raio

    Entrada: enderelo de dois pts
    Pré-condição: endereço dos ptos serem válidos
    Processo: calcular a distância
    Saída: raio, que é a distância entre os pontos
    Pós-condição: nenhuma
*/

float raio(pto  p1, pto p2){
    if(p1 == NULL || p2 == NULL){
        return -1; //FALHA
    }
    float dist = distancia_2ptos(p1, p2);

    return dist;
}

/*
Operação: volume
    -Entrada: Dois pontos
    -Pré-condição: pontos serem válidos
    -Processo: Calcula o volume de uma esfera (4/3 * pi * r^3)
    -Saída: Volume de uma esfera
    -Pós condição: nenhuma
*/

float volume(pto  p1, pto p2){
    float vol = (4/3)*3.14*pow(raio(p1, p2), 3);

    return vol;
}