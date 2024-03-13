#include <stdio.h>
#include "listaint.h"


int
main()
{
    int op, flag = 0, cont = 0;
    Lista L, L2, L3, L4, L5;

    do{
        do{
            printf("\n------------------------\n");
            printf("[1]Criar uma lista\n");
            printf("[2]Esvaziar lista\n");
            printf("[3]Apagar lista\n");
            printf("[4]Inserir elemento\n");
            printf("[5]Remover elemento\n");
            printf("[6]Remover maior\n");
            printf("[7]Inverter\n");
            printf("[8]Imprimir lista\n");
            printf("[9]Intercalar\n");
            printf("[10]Tamanho\n");
            printf("[11]Sair\n");
            printf("\nDigite sua opção: ");
            scanf("%d", &op);
            getchar();

            if(op < 1 || op > 11)
                printf("Opção não válida\n");
        }while(op < 1 || op > 11);

        if(op == 11)
            break;
        else if(op != 1 && flag < 0){
            printf("\nA lista precisa ser criada!\n");
            continue;
        }
        switch (op){
            case 1: {      
                if(flag == 0){
                    if((L = cria_lista()) != NULL){
                        printf("\nFalha na alocação\n");
                        return -1;
                    }
                    else{
                        printf("\nLista criada 1 com sucesso\n");
                        printf("\nAperte novamente 1 para criar a segunda lista.\n");
                    }
                }
                if(flag == 1){
                    if((L2 = cria_lista()) != NULL){
                        printf("\nFalha na alocação\n");
                        return -1;
                    }
                    else
                        printf("\nLista criada 2 com sucesso\n");
                    cont = 1;
                }
                flag = 1;
                break;
            }
            case 2: {
                if(cont == 0){
                    if (esvazia_lista(&L) == 0){
                        printf("\nLista inexistente\n");
                    }
                    else{
                        printf("\n\nA lista %d foi esvaziada com sucesso\n", cont+1);
                    }
                }
                else{
                    if (esvazia_lista(&L2) == 0){
                        printf("\nLista inexistente\n");
                    }
                    else{
                        printf("\n\nA lista %d foi esvaziada com sucesso\n", cont+1);
                    }
                }
                break;
            }
            case 3: {
                if(cont == 0){
                    if (apaga_lista(&L) == 0) {
                        printf("\n\nLista não existe para ser apagada\n");
                    }
                    else{
                        printf("\n\nLista 1 apagada com sucesso\n");
                    }
                }
                else{
                    if (apaga_lista(&L2) == 0) {
                        printf("\n\nLista não existe para ser apagada\n");
                    }
                    else{
                        printf("\n\nLista 1 apagada com sucesso\n");
                        flag = 1;
                        cont = 0;
                    }
                }
                break;
            }
            case 4: {
                int elem;
                printf("\nDigite o elemento a ser inserido: ");
                scanf("%d", &elem);

                if(cont == 0){
                    if(insere_elem(&L, elem) == 0) {
                        printf("\nNão foi possivel incluir o elemento %d \n", elem);
                    }
                    else{
                        printf("\nO elemento ->%d<- foi incluido com sucesso\n", elem);
                    }
                }
                else{
                    if(insere_elem(&L2, elem) == 0) {
                        printf("\nNão foi possivel incluir o elemento %d \n", elem);
                    }
                    else{
                        printf("\nO elemento ->%d<- foi incluido com sucesso\n", elem);
                    }
                }
                break;
            }
            case 5: {
                int elem = 0;
                printf("\nDigite o elemento a ser removido: ");
                scanf("%d", &elem);

                if(cont == 0){
                    if(remove_elem(&L, elem) == 0){
                        if(lista_vazia(L) == 1)
                            printf("\n\nA lista está vazia\n");
                        else
                            printf("\nNão existe o elemento %d\n", elem);
                    }
                    else{
                        printf("\nO elemento ->%d<- foi removido\n", elem);
                    }
                }
                else{
                    if(remove_elem(&L2, elem) == 0){
                        if(lista_vazia(L2) == 1)
                            printf("\n\nA lista está vazia\n");
                        else
                            printf("\nNão existe o elemento %d\n", elem);
                    }
                    else{
                        printf("\nO elemento ->%d<- foi removido\n", elem);
                    }
                }
                break;
            }
            case 6: {
                int elem;
                if(cont == 0){
                    if(remover_maior(&L, &elem) == 0){
                        printf("\nLista vazia!\n");
                    }
                    else
                        printf("\nElemento ->%d<- retirado!\n", elem);
                }
                else{
                    if(remover_maior(&L2, &elem) == 0){
                        printf("\nLista vazia!\n");
                    }
                    else
                        printf("\nElemento ->%d<- retirado!\n", elem);
                }
                break;
            }
            case 7: {
                L4 = cria_lista();
                L5 = cria_lista();
                if(cont == 0){
                    if(inverter_lista(&L, &L4) == 0)
                        printf("\nLista vazia!");
                    else{
                        printf("\nLista invertida! ");
                        imprime_lista(L4);
                    }
                }
                else{
                    if(inverter_lista(&L2, &L5) == 0)
                        printf("\nLista vazia!");
                    else
                        imprime_lista(L5);
                }
                break;
            }
            case 8: {
                if(cont == 0)
                    imprime_lista(L);
                else
                    imprime_lista(L2);
                break;
            }
            case 9: {
                L3 = cria_lista();
                if(intercalar_lista(&L, &L2, &L3) == 0)
                    printf("\nEstá faltando alguma lista!\n");
                else{
                    printf("\nIntercalado!\n");
                    imprime_lista(L3);
                }
                break;   
            }
            case 10: {
                if(cont == 0){
                    if(tamanho_lista(&L) == 0)
                        printf("\nLista não existe!\n");
                    else
                        printf("\nA lista tem %d elementos\n", tamanho_lista(&L));
                }
                else{
                    if(tamanho_lista(&L2) == 0)
                        printf("\nLista não existe!\n");
                    else
                        printf("\nA lista tem %d elementos\n", tamanho_lista(&L2));
                }
                break;
            }
        }
    }while(op != 11);

    printf("\nVolte sempre!\n");

	return 0;
}

/*
Operação: imprime_lista
    -Entrada: Uma lista.
    -Pré-condição: Lista existir
    -Processo: Imprime a lista.
    -Saída: nenhuma.
    -Pós-condição: nenhuma.
*/

void imprime_lista(Lista L){
    if(lista_vazia(L) == 1){
            printf("\n===LISTA VAZIA===\n");
    }
    else{
        printf("\nLista:");
        for (int i = 1; ; i++){
            float elem;
            if(get_elem_pos(L, i, &elem) == 0){
                break;
            }
            printf(" %f ", elem);
        }
        printf("\n");
    }
}