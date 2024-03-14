#include <stdio.h>
#include "listafloat.h"


int
main()
{
    int op, flag = 0, cont = 0;
    Lista L, L2, L3;

    do{
        do{
            printf("\n------------------------\n");
            printf("[1]Criar uma lista\n");
            printf("[2]Esvaziar lista\n");
            printf("[3]Apagar lista\n");
            printf("[4]Inserir elemento\n");
            printf("[5]Remover elemento\n");
            printf("[6]Remover da posição\n");
            printf("[7]Iguais\n");
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
                    if((L = cria_lista()) == NULL){
                        printf("\nFalha na alocação\n");
                        return -1;
                    }
                    else{
                        printf("\nLista criada 1 com sucesso\n");
                        printf("\nAperte novamente 1 para criar a segunda lista.\n");
                    }
                }
                if(flag == 1){
                    if((L2 = cria_lista()) == NULL){
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
                float elem;
                printf("\nDigite o elemento a ser inserido: ");
                scanf("%f", &elem);

                if(cont == 0){
                    if(insere_ord(&L, elem) == 0) {
                        printf("\nA lista já está cheia\n");
                        printf("\nNão foi possivel incluir o elemento %0.3f \n", elem);
                    }
                    else{
                        printf("\nO elemento ->%0.3f<- foi incluido com sucesso\n", elem);
                    }
                }
                else{
                    if(insere_ord(&L2, elem) == 0) {
                        printf("\nA lista já está cheia\n");
                        printf("\nNão foi possivel incluir o elemento %0.3f \n", elem);
                    }
                    else{
                        printf("\nO elemento ->%0.3f<- foi incluido com sucesso\n", elem);
                    }
                }
                break;
            }
            case 5: {
                float elem = 0;
                printf("\nDigite o elemento a ser removido: ");
                scanf("%f", &elem);

                if(cont == 0){
                    if(remove_ord(&L, elem) == 0){
                        if(lista_vazia(L) == 1)
                            printf("\n\nA lista está vazia\n");
                        else
                            printf("\nNão existe o elemento %0.3f\n", elem);
                    }
                    else{
                        printf("\nO elemento ->%0.3f<- foi removido\n", elem);
                    }
                }
                else{
                    if(remove_ord(&L2, elem) == 0){
                        if(lista_vazia(L2) == 1)
                            printf("\n\nA lista está vazia\n");
                        else
                            printf("\nNão existe o elemento %0.3f\n", elem);
                    }
                    else{
                        printf("\nO elemento ->%0.3f<- foi removido\n", elem);
                    }
                }
                break;
            }
            case 6: {
                int pos;
                float elem;

                printf("Digite a posição: ");
                scanf("%d", &pos);

                if(cont == 0){
                    if(remover_pos(&L, &pos, &elem) == 0)
                        printf("\nPosição inexistente\n");
                    else
                        printf("\nElemento %0.3f removido da posição %d!\n", elem, pos);
                }
                else{
                    if(remover_pos(&L2, &pos, &elem) == 0)
                        printf("\nPosição inexistente\n");
                    else
                        printf("\nElemento %0.3f removido da posição %d!\n", elem, pos);
                }
                break;
            }
            case 7: {
                if (comparar_lista(&L, &L2) == 1)
                    printf("\nAs listas são iguais!\n");
                else 
                    printf("\nAs listas são diferentes!\n");
            
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
                if(intercalar_lista(&L, &L2, L3) == 0){
                    printf("\nEstá faltando alguma lista!\n");
                    printf("Ou tamanho de listas diferentes!\n");
                }
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
                        printf("\nA lista tem %d elementos\n", tamanho_lista(&L)-1);
                }
                else{
                    if(tamanho_lista(&L2) == 0)
                        printf("\nLista não existe!\n");
                    else
                        printf("\nA lista tem %d elementos\n", tamanho_lista(&L2)-1);
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
            printf(" %0.3f ", elem);
        }
        printf("\n");
    }
}