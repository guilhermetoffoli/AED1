#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex2.h"

#define MAX 50

int
main(){
    Pilhachar p_char = cria_pilha_char();
    Pilhareal p_real = cria_pilha_real();
    char operacao[MAX], posf[MAX];
    int verif = 0, ativo = 0, x = 0, h;

    while (1){
        esvazia_lista_char(p_char);
        esvazia_pilha_real(&p_real);

        printf("\nDigite a expressão a ser consultada: ");
        scanf("%s", operacao);

        if (strcmp(operacao, "FIM")) break;
        
        if (valida_escopo(operacao) == -1){
            printf("Expressao invalida");
            break;
        }
        else if(valida_escopo(operacao) == -3 || valida_escopo(operacao) == -5){
            printf("Erro de prioridade de escopo\n"); 
            break;
        }
        else if (valida_escopo(operacao) == -7)
        {
            printf("\nErro de finalizador ()\n");
            break;
        }
        else if(valida_escopo(operacao) == -9)
        {
            printf("\nErro de finalizador []\n");
            break;
        }
        else if(valida_escopo(operacao) == -11)
        {
            printf("\nErro de finalizador {}\n");
            break;
        }
        else{
            printf("Escopos corretos!!");
        }
    }
    

    return 1;
}