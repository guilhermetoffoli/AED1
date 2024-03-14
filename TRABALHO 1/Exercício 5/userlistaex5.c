#include <stdio.h>
#include "listaex5.h"

int
main()
{
    int op, flag = 0, cont = 0;
    Lista L, L2;

    do{
        do{
            printf("\n------------------------\n");
            printf("[1]Criar uma lista\n");
            printf("[2]Esvaziar lista\n");
            printf("[3]Apagar lista\n");
            printf("[4]Inserir no final\n");
            printf("[5]Inserir no inicio\n");
            printf("[6]Inserir posição\n");
            printf("[7]Remover no final\n");
            printf("[8]Remover no inicio\n");
            printf("[9]Remover pares\n");
            printf("[10]Imprimir\n");
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
                        printf("\nAperte 1 novamentre para criar a segunda lista\n");
                    }
                }
                if(flag == 1){
                    if((L2 = cria_lista()) == NULL){
                        printf("\nFalha na alocação\n");
                        return -1;
                    }
                    else
                        printf("\nLista criada 2 com sucesso\n");
                    cont = 0;
                }
                flag == 1;
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
                    if(insere_final(&L, elem) == 0) {
                        printf("\nA lista já está cheia\n");
                        printf("\nNão foi possivel incluir o elemento %d \n", elem);
                    }
                    else{
                        printf("\nO elemento ->%d<- foi incluido com sucesso\n", elem);
                    }
                }
                else{
                    if(insere_final(&L2, elem) == 0) {
                        printf("\nA lista já está cheia\n");
                        printf("\nNão foi possivel incluir o elemento %d \n", elem);
                    }
                    else{
                        printf("\nO elemento ->%d<- foi incluido com sucesso\n", elem);
                    }
                }
                break;
            }
            case 5: {
                int elem;
                printf("\nDigite o elemento a ser inserido: ");
                scanf("%d", &elem);
                if(cont == 0){
                    if(insere_inicio(&L, &elem) == 0){
                        printf("\nNó não alocado\n");
                    }
                    else
                        printf("\nElemento ->%d<- inserido!", elem);
                }
                else{
                    if(insere_inicio(&L, &elem) == 0){
                        printf("\nNó não alocado\n");
                    }
                    else
                        printf("\nElemento ->%d<- inserido!", elem);
                }
                break;
            }
            case 6: {
                int pos, elem;
                printf("\nDigite a posição desejada: ");
                scanf("%d", &pos);
                printf("\nDigite o elemento a ser inserido: ");
                scanf("%d", &elem);

                if(cont == 0){
                    if(insere_pos(&L, &pos, &elem) == 0){
                        printf("\nNó não alocado ou posição inexistente\n");
                    }
                    else
                        printf("\nElemento ->%d<- inserido na posição %d!", elem, pos);
                }
                else{
                    if(insere_pos(&L, &pos, &elem) == 0){
                        printf("\nNó não alocado ou posição inexistente\n");
                    }
                    else
                        printf("\nElemento ->%d<- inserido na posição %d!", elem, pos);
                }
                break;
            }
            case 7: {
                int elem;
                if(cont == 0){
                    if(remove_final(&L, &elem) == 0){
                        printf("\nLista vazia!\n");
                    }
                    else{
                        printf("\nElemento ->%d<- retirado do final!\n", elem);
                    }
                }
                else{
                    if(remove_final(&L, &elem) == 0){
                        printf("\nLista vazia!\n");
                    }
                    else{
                        printf("\nElemento ->%d<- retirado do final!\n", elem);
                    }
                }
                break;
            }
            case 8: {
                int elem = 0;

                if(cont == 0){
                    if(remove_inicio(&L, elem) == 0){
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
                    if(remove_inicio(&L2, elem) == 0){
                        if(lista_vazia(L2) == 1)
                            printf("\n\nA lista está vazia\n");
                        else
                            printf("\nNão existe o elemento %d\n", elem);
                    }
                    else{
                        printf("\nO elemento ->%d<- foi removido\n", elem);
                    }
                }
            }
            case 9: {
                int elem;
                if(cont == 0){
                    if(remove_par(&L, &elem) == 0){
                        printf("\nLista vazia\n");
                    }
                    else
                        printf("\nPares removidos!\n");
                }
                else{
                    if(remove_par(&L2, &elem) == 0){
                        printf("\nLista vazia\n");
                    }
                    else
                        printf("\nPares removidos!\n");
                }
                break;
            }
            case 10: {
                if(cont == 0)
                    imprime_lista(L);
                else
                    imprime_lista(L2);
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
            printf(" %d ", elem);
        }
        printf("\n");
    }
}