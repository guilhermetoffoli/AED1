#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void imprime_fila(Fila, Pessoa);

int main(){
    Fila f = NULL;
    Pessoa elem;
    int ativo = 1;
    int n, verifica = 0;

    while(ativo == 1){
        
        printf("--Fila--\n");
        printf("\n 1 - Criar Fila\n");
        printf(" 2 - Inserir cadastro na Fila\n");
        printf(" 3 - Remover cadastro da Fila de forma ordenada\n");
        printf(" 4 - Imprimir Fila\n");
        printf(" 5 - Limpar Fila\n");
        printf(" 6 - Apagar Fila\n");
        printf(" 7 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &n);
        setbuf(stdin, NULL);

        switch (n){
            case 1:
                if(verifica == 0){
                    f = cria_fila();
                    verifica = 1;
                    printf("\nA fila foi criada com sucesso");
                }
                else {
                    printf("\nA lista ja foi criada\n");
                }
                break;
            case 2:
                printf("Insira o nome do paciente: ");
                scanf("%[^\n]", elem.nome);

                printf("Insira a idade: ");
                scanf("%d", &elem.idade);

                printf("Insira o peso: ");
                scanf("%f", &elem.peso);

                printf("Insira a altura: ");
                scanf("%f", &elem.altura);

                printf("Insira a doenca: ");
                getchar();
                scanf("%[^\n]", &elem.doenca);

                printf("Insira a gravidade da doenca: ");
                scanf("%d", &elem.gravidade);

                printf("\n");
                if (insere_fim(&f, elem) == 1) {
                    printf("Elemento inserido.\n");
                } else {
                    printf("Falha ao inserir elemento.\n");
                }

                break;
            case 3:
                if(remove_ord(&f, &elem) == 0)
                    printf("Lista vazia\n");
                else{
                    printf("O paciente: \n\n");
                    printf("Nome: %s\n", elem.nome);
                    printf("Idade: %d\n", elem.idade);
                    printf("Peso: %.2f\n", elem.peso);
                    printf("Altura: %.2f", elem.altura);
                    printf("Doenca: %c\n", elem.doenca);
                    printf("Gravidade: %d\n\n", elem.gravidade);
                    printf("Foi removido\n");
                }
                break;
            case 4:
                if(f != NULL)
                    imprime_fila(f, elem);
                else 
                    printf("Nao foi possivel imprimir.\n");
                break;
            case 5:
                if(esvazia_fila(&f) == 0)
                    printf("Fila nao existente\n");
                else{
                        printf("Fila esvaziada\n");
                    }
                break;
            case 6:
                apaga_fila(&f);
                printf("Fila apagada\n");
                break;
            case 7:
                printf("\nSaindo..\n");
                ativo = 0;
                break;
            default:
                printf("Lista ainda nao foi criada!\n");
        }
    }

    return 0;
}

void imprime_fila(Fila f, Pessoa elem){
    if(fila_vazia(f) == 1){
        printf("\n -- Fila vazia --\n");
        return ;
    }
    printf("\nFila:\n");

    Fila aux = cria_fila();

    while(fila_vazia(f) == 0){
        remove_ord(&f, &elem);
        printf("Nome: %s\n", elem.nome);
        printf("Idade: %d\n", elem.idade);
        printf("Peso: %.2f\n", elem.peso);
        printf("Altura: %.2f\n", elem.altura);
        printf("Doenca: %c\n", elem.doenca);
        printf("Gravidade: %d", elem.gravidade);

        insere_fim(&aux, elem);
        printf("\n\n");
    }
    while(fila_vazia(aux) == 0){
        remove_ord(&aux, &elem);
        insere_fim(&f, elem);
    }
}