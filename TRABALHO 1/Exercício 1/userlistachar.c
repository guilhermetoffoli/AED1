#include <stdio.h>
#include "listachar.h"

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
            printf("[6]Remover na posição\n");
            printf("[7]Remover vogais\n");
            printf("[8]Imprimir lista\n");
            printf("[9]Intercalar\n");
            printf("[10]Tamanho da lista\n");
            printf("[11]Sair\n");
            printf("\nDigite sua opção: ");
            scanf("%d", &op);
            getchar();

            if(op < 1 || op > 11)
                printf("\nOpção não válida\n");
        }while(op < 1 || op > 11);

        if(op == 11)
            break;
        else if(op != 1 && flag == 0){
            printf("\nA lista precisa ser criada!\n");
            continue;
        }
        switch (op){
            case 1: {      
                if(flag == 0){
                    L = cria_lista();

                    if(L == NULL){
                        printf("\nFalha na alocação\n");
                        return -1;
                    }
                    
                    printf("\nA lista %d foi criada com sucesso\n", flag+1);
                    printf("\nAperte novamente 1 para criar a segunda lista.\n");
                }  
                if(flag == 1){        
                    L2 = cria_lista();

                    if(L2 == NULL){
                        printf("\nFalha na alocação\n");
                        return -1;
                    }

                    printf("\nA lista %d foi criada com sucesso\n", flag+1);
                    cont = 1;
                }
                flag = 1;
                break;
            }
            case 2: {
                if(cont == 0)
                    if (esvazia_lista(L) == 0)
                        printf("\nLista inexistente\n");
                    else
                        printf("\nA lista %d foi esvaziada com sucesso\n", cont+1);

                else
                    if (esvazia_lista(L2) == 0)
                        printf("\nLista inexistente\n");
                    else
                        printf("\nA lista %d foi esvaziada com sucesso\n", cont+1);
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
                    printf("\n\nLista não existen para ser apagada\n");
                    }
                    else{
                        printf("\n\nLista 2 apagada com sucesso\n");
                        flag = 1;
                        cont = 0;
                    }
                }
                break;
            }
            case 4: {
                char elem;
                printf("\nDigite o elemento a ser inserido: ");
                scanf("%c", &elem);

                if(cont == 0){    
                    if(insere_ord(L, elem) == 0) {
                        printf("\nA lista já está cheia\n");
                        printf("\nNão foi possivel incluir o elemento %c \n", elem);
                    }
                    else{
                        printf("\nO elemento %c foi incluido com sucesso\n", elem);
                    }
                }
                
                else{
                    if(insere_ord(L2, elem) == 0) {
                        printf("\nA lista já está cheia\n");
                        printf("\nNão foi possivel incluir o elemento %c \n", elem);
                    }
                    else{
                        printf("\nO elemento %c foi incluido com sucesso\n", elem);
                    }   
                }
                break;
            }
            case 5: {
                char elem;
                printf("\nDigite o elemento a ser removido: ");
                scanf("%c", &elem);

                if(cont == 0){
                    if(remove_ord(L, elem) == 0){
                        if(lista_vazia(L) == 1)
                            printf("\n\nA lista está vazia\n");
                        else
                            printf("\nNão existe o elemento %c\n", elem);
                    }
                    else
                        printf("\nO elemento %c foi removido\n", elem);
                }
                else{
                    if(remove_ord(L2, elem) == 0){
                        if(lista_vazia(L) == 1)
                        printf("\n\nA lista está vazia\n");
                        else
                            printf("\nNão existe o elemento %c\n", elem);
                    }   
                    else
                        printf("\nO elemento %c foi removido\n", elem);
                }
                break;
            }
            case 6: {
                int pos;
                printf("\nInsira a posição desejada: ");
                scanf("%d", &pos);

                if(cont == 0){
                    if(remover_pos(L, pos) == 0){
                        printf("\nPosição inexistente");
                    }
                    else{
                        printf("\nElemento removido da posição %d", pos);
                    }
                }
                else{
                    if(remover_pos(L2, pos) == 0){
                        printf("\nPosição inexistente");
                    }
                    else{
                        printf("\nElemento removido da posição %d", pos);
                    }
                }
                break;
            }
            case  7:{
                if(cont == 0){
                    if(remove_vogal(L) == 0){
                        if(lista_vazia(L) == 1)
                            printf("\n\nA lista está vazia\n");
                        else
                            printf("\nNão existe vogais\n");
                    }
                    else
                        printf("\nAs vogais foram removidas\n");
                
                }else{
                    if(remove_vogal(L2) == 0){
                        if(lista_vazia(L2) == 1)
                            printf("\n\nA lista está vazia\n");
                        else
                            printf("\nNão existe vogais\n");
                    }
                    else
                        printf("\nAs vogais foram removidas\n");
                }
                break;
            }
            case 8: {
                if(cont == 0){
                    imprime_lista(L);
                }

                else{
                    imprime_lista(L2);
                }
                break;
            }
            case 9:{
                L3 = cria_lista();
                if(intercalar_lista(L, L2, L3) == 0)
                    printf("\nEstá faltando alguma lista!\n");
                else{
                    printf("\nIntercalado!\n");
                    printf("\nLista:");
                    for (int i = 1; ; i++){
                        char elem;
                        if(get_elem_pos_inter(L3, i, &elem) == 0){
                            break;
                        }
                        printf(" %c ", elem);
                    }
                    printf("\n");
                }
                break;  
            }
            case 10:{
                int tam = 0;

                if(cont == 0){
                    if(tamanho_lista(L, &tam) == 0)
                        printf("\nLista não existe\n");
                    else
                        printf("\nA lista tem %d elementos\n", tam);
                }
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
    if(lista_vazia(L)){
            printf("\n===LISTA VAZIA===\n");
    }
    else{
        printf("\nLista:");
        for (int i = 1; ; i++){
            char elem;
            if(get_elem_pos(L, i, &elem) == 0){
                break;
            }
            printf(" %c ", elem);
        }
        printf("\n");
    }
}