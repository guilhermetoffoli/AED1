#include <stdio.h>
#include "listexerc.h"
#include <string.h>

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
            printf("[5]Inserir na posição\n");
            printf("[6]Remover elemento\n");
            printf("[7]Remover menor\n");
            printf("[8]Imprimir lista\n");
            printf("[9]Concatenar\n");
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
                char string[STR];
                printf("\nDigite a string a ser inserida: ");
                scanf("%s", string);

                if(cont == 0){    
                    if(insere_elem(L, string) == 0) {
                        printf("\nA lista já está cheia\n");
                        printf("\nNão foi possivel incluir o elemento %s \n", string);
                    }
                    else{
                        printf("\nO elemento %s foi incluido com sucesso\n", string);
                    }
                }
                
                else{
                    if(insere_elem(L2, string) == 0) {
                        printf("\nA lista já está cheia\n");
                        printf("\nNão foi possivel incluir o elemento %s \n", string);
                    }
                    else{
                        printf("\nO elemento %s foi incluido com sucesso\n", string);
                    }   
                }
                break;
            }
            case 5: {
                char str[STR];
                int pos;
                printf("\nInsira a String: ");
                scanf("%s", str);

                printf("\nDigite a posição desejada: ");
                scanf("%d", &pos);

                if(cont == 0){
                    if(insere_pos(L, pos, str) == 0){
                        printf("\nPosição inexistente\n");
                    }
                    else{
                        printf("\nString ->%s<- inserida na posição %d\n", str, pos);
                    }
                }

                else{
                    if(insere_pos(L2, pos, str) == 0){
                        printf("\nPosição inexistente\n");
                    }
                    else{
                        printf("\nString ->%s<- inserida na posição %d\n", str, pos);
                    }
                }
                break;
            }
            case 6: {
                char string[STR];
                printf("\nDigite a string a ser removida: ");
                scanf("%s", string);

                if(cont == 0){
                    if(remove_elem(L, string) == 0){
                        if(lista_vazia(L) == 1)
                            printf("\n\nA lista está vazia\n");
                        else
                            printf("\nNão existe o elemento %s\n", string);
                    }
                    else
                        printf("\nO elemento %s foi removido\n", string);
                }
                else{
                    if(remove_elem(L2, string) == 0){
                        if(lista_vazia(L) == 1)
                        printf("\n\nA lista está vazia\n");
                        else
                            printf("\nNão existe o elemento %s\n", string);
                    }   
                    else
                        printf("\nO elemento %s foi removido\n", string);
                }
                break;
            }
            case  7:{
                char menor[STR];
                if(cont == 0){
                    if(remove_menor(L, menor) == 0){
                        printf("\nLista não existe!\n");
                    }
                    else
                        printf("\nA menor string é ->%s<-\n", menor);
                }

                if(cont == 1){
                    if(remove_menor(L2, menor) == 0){
                        printf("\nLista não existe!\n");
                    }
                    else
                        printf("\nA menor string é ->%s<-\n", menor);
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
                if(concatenar_lista(L, L2, L3) == 0)
                    printf("\nEstá faltando alguma lista!\n");
                else{
                    printf("\nConcatenado!\n");
                    imprime_lista(L3);
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

                else{
                    if(tamanho_lista(L2, &tam) == 0)
                        printf("\nLista não existe\n");
                    else
                        printf("\nA lista tem %d elementos\n", tam);
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
    if(lista_vazia(L)){
            printf("\n===LISTA VAZIA===\n");
    }
    else{
        printf("\nLista:");
        for (int i = 1; ; i++){
            char str[STR];
            if(get_elem_pos(L, i, str) == 0){
                break;
            }
            printf(" %s ", str);
        }
        printf("\n");
    }
}